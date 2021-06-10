
#include "stdafx.h"
#include "conductor.h"
#include "debug.h"
#include "metrics.h"
#include "engine.h"

namespace CORE {

	void Conductor::Init(void) {

		QueryPerformanceFrequency(&_freq);
		QueryPerformanceCounter(&_prev);
		QueryPerformanceCounter(&_now);

		Add(EEventType::MEASURE, std::bind(&Conductor::Measure, this), 1.0);

		EMB_DEBUG->Metrics()->AddMetric("FPS");
		EMB_DEBUG->Metrics()->AddMetric("TPS");

	}

	void Conductor::Update(void) {

		QueryPerformanceCounter(&_now);
		LONGLONG delta = _now.QuadPart - _prev.QuadPart;
		_prev = _now;

		double ms = (double)delta * 1000.0 / (double)_freq.QuadPart;

		for (auto &ev : _eventStates) {
			SEventState &state = ev.second;
			
			state.accumulator += ms;
			if (state.accumulator >= state.threshhold) {
				state.count++;
				state.accumulator -= state.threshhold;
				state.callback();
			}
		}

	}

	void Conductor::Measure(void) {

		EMB_DEBUG->Metrics()->UpdateMetric("FPS", _eventStates[EEventType::DRAW].count);
		EMB_DEBUG->Metrics()->UpdateMetric("TPS", _eventStates[EEventType::TICK].count);		

		_eventStates[EEventType::TICK].count = 0;
		_eventStates[EEventType::DRAW].count = 0;

	}

	void Conductor::Add(EEventType type, EventFunc callback, double rate) {
		SEventState state;
		state.accumulator = 0;
		state.callback = callback;
		state.rate = rate;
		state.countLastMeasure = 0;
		state.count = 0;
		state.threshhold = (1.0 / rate) * 1000.0;
		_eventStates[type] = state;
	}

}
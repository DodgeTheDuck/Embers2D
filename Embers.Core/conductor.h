#pragma once

#include <Embers.Lib/singleton.h>
#include <functional>

namespace CORE {

	typedef std::function<void()> EventFunc;

	enum EEventType {
		TICK,
		DRAW,
		MEASURE
	};

	struct SEventState {
		EventFunc callback;
		double rate;
		double threshhold;
		double accumulator;
		uint32_t countLastMeasure;
		uint32_t count;
	};

	class Conductor : public LIB::Singleton<Conductor> {

	public:

		void Init(void);
		void Update(void);
		void Measure(void);
		void Add(EEventType type, EventFunc callback, double rate);
		std::map<EEventType, SEventState> _eventStates;

	private:		
		LARGE_INTEGER _freq, _now, _prev;

	};

}
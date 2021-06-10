#pragma once

#include "dll.h"

namespace LIB {

	template<typename T> class Singleton {

	public:

		static T* GetInstance(void) {
			if (!_instance) _instance = new T();
			return _instance;
		};

	private:

		static T* _instance;

	};

	template<typename T> T* Singleton<T>::_instance = 0;

}
#pragma once

#include <Embers.Lib/dll.h>

namespace DEF {

	typedef std::map<std::string, std::vector<std::string>> EMB_API DefProperties;

	class EMB_API Loader {

	public:
		static DefProperties Load(const std::string& path);

	};

}
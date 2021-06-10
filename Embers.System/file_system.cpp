
#include "stdafx.h"
#include "file_system.h"

namespace SYS {

	std::string FileSystem::ReadText(std::string path) {
		std::ifstream t(path);
		std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
		return str;
	}

}
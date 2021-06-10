
#include "stdafx.h"
#include "loader.h"

#include <Embers.System/file_system.h>

namespace DEF {

	DefProperties Loader::Load(const std::string& path) {

		DefProperties props;
		std::string def = SYS::FileSystem::ReadText(path);

		std::string word = "";
		std::string key = "";
		std::vector<std::string> values;

		bool isKey = true;

		for (int i = 0; i < def.length(); i++) {

			char c = def[i];

			if (i == def.length() - 1) {
				word += c;
			}
			
			if (c == '\n' || i == def.length() - 1) {
				values.push_back(word);
				props[key] = values;
				isKey = true;
				word = "";
				key = "";
				values.clear();
			}
			else if (c == ' ') {

				if (isKey) {
					key = word;
					isKey = false;
				}
				else {
					values.push_back(word);
				}

				word = "";

			}
			else {
				word += c;
			}

		}

		return props;

	}

}
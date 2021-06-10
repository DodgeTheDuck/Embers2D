#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Lib/singleton.h>

namespace CORE {

	class Asset;

	class EMB_API AssetBank : public LIB::Singleton<AssetBank> {

	public:
		void Load(void);

		template<typename T>
		T* GetAsset(const std::string& name) {
			return (T*)_assets[name];
		}

	private:
		std::map<std::string, Asset*> _assets;

	};

}
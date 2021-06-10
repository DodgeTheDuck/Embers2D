#pragma once

#include <Embers.Lib/dll.h>
#include "component.h"

namespace CORE {

	class EMB_API CGuiComponent : public Component {

	public:

		CGuiComponent(SceneObject* owner);

		void Tick(void);

		virtual void PreDraw(void);
		void Draw(void);
		virtual void PostDraw(void);
		virtual void DrawPass(GFX::ERenderPass pass);
		virtual bool IsDirty(void);

		virtual CGuiComponent* SetDimensions(float width, float height);

	protected:
		virtual void _Rebuild(void);		

		bool _isDirty;	
		float _width;
		float _height;

	};

}
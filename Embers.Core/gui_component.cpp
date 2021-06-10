
#include "stdafx.h"
#include "gui_component.h"

namespace CORE {

	CGuiComponent::CGuiComponent(SceneObject* owner) : Component(owner) {
		_isDirty = true;
	}

	void CGuiComponent::Tick(void) {

	}

	void CGuiComponent::PreDraw(void) {

	}

	void CGuiComponent::Draw(void) {
		
	}

	void CGuiComponent::PostDraw(void) {

	}

	void CGuiComponent::DrawPass(GFX::ERenderPass pass) {

	}

	bool CGuiComponent::IsDirty(void) {
		return _isDirty;
	}

	CGuiComponent* CGuiComponent::SetDimensions(float width, float height) {
		_width = width;
		_height = height;
		_isDirty = true;
		return this;
	}

	void CGuiComponent::_Rebuild(void) {

	}

}
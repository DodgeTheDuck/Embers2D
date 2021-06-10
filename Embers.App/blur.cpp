
#include "stdafx.h"
#include "blur.h"

#include <Embers.Core/material.h>
#include <Embers.Core/gui_text_block.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>

#include <Embers.Graphics/gl.h>
#include <Embers.Core/gui_panel.h>

Blur::Blur(void) {

	AddComponent<CORE::CGuiPanel>();

	GetComponent<CORE::CTransform>()->Translate(glm::vec3(128, 128, 0));

}

void Blur::Tick(void) {


}
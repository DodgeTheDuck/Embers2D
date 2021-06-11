
#include "stdafx.h"
#include "rigid_body.h"
#include "effector.h"
#include "transform.h"
#include "polygon.h"
#include "scene_object.h"
#include "physics_world.h"
#include "engine.h"

namespace CORE {

	CRigidBody::CRigidBody(SceneObject* owner) : Component(owner) {

		CTransform* transform = _owner->GetComponent<CTransform>();
		CPolygon* polygon = _owner->GetComponent<CPolygon>();

		b2BodyDef def;
		def.type = b2_dynamicBody;
		def.position.Set(transform->Position.x, transform->Position.y);
		
		b2PolygonShape shape;

		if (polygon) {

			//TODO: this is gross, gotta make a better way to convert...
			std::vector<b2Vec2> bPoints;
			std::vector<glm::vec2> gPoints = polygon->GetPoints();
			
			for (int i = 0; i < gPoints.size(); i++) {
				bPoints.push_back({gPoints[i].x, gPoints[i].y});
			}

			shape.Set(bPoints.data(),bPoints.size());

		}
		else {
			shape.SetAsBox(2.0f, 2.0f);
		}

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 0.01f;
		fixtureDef.friction = 0.00f;

		_body = EMB_PHYSICS_WORLD->CreateBody(&def);

		_body->CreateFixture(&fixtureDef);

	}

	void CRigidBody::Tick(void) {

		CTransform* transform = _owner->GetComponent<CTransform>();

		transform->Position.x = _body->GetPosition().x;
		transform->Position.y = _body->GetPosition().y;

		transform->SetAngle(glm::degrees(_body->GetAngle()));

	}

	void CRigidBody::ApplyForce(glm::vec2 force, glm::vec2 point) {
		_body->ApplyForce({ force.x, force.y }, {point.x, point.y}, true);
	}

	void CRigidBody::ApplyForceAtCenter(glm::vec2 force) {
		_body->ApplyForceToCenter({ force.x, force.y }, true);
	}

	void CRigidBody::ApplyTorque(float torque) {
		_body->ApplyTorque(torque, true);
	}

	void CRigidBody::PreDraw(void) {

	}

	void CRigidBody::Draw(void) {

	}

	void CRigidBody::PostDraw(void) {
		
	}

	void CRigidBody::DrawPass(GFX::ERenderPass pass) {

	}

	CRigidBody* CRigidBody::AddEffector(Effector* effector) {
		_effectors.push_back(effector);
		return this;
	}


}
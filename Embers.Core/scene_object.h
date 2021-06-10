#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Graphics/gl.h>

namespace CORE {

	class Component;

	class EMB_API SceneObject {

	public:
		SceneObject(void);

		virtual void Tick(void);
		virtual void PostTick(void);

		virtual void Draw(void);		
		virtual void DrawPass(GFX::ERenderPass pass);
		
		template<typename T>
		T* AddChild(T* child) {
			child->_parent = this;
			_children.push_back(child);
			return child;
		}

		template<class T>
		T* AddComponent(void) {
			T* t = new T(this);
			_components.push_back(t);
			return t;
		}

		template<class T>
		T* GetComponent(void) {
			for (int i = 0; i < _components.size(); i++) {
				if (T* t = dynamic_cast<T*>(_components[i])) {
					return (T*)_components[i];
				}
			}
			return NULL;
		}

	protected:

		SceneObject* _parent;

	private: 
		std::vector<SceneObject*> _children;
		std::vector<Component*> _components;

	};

}
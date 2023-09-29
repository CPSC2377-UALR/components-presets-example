#pragma once
#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "ComponentList.h"
#include "GameObject.h"
#include "SDL.h"
#include "tinyxml2.h"
#include "Initializers.h"
#include "Texture.h"


#include "Definitions.h"
class SpriteComponent : public Component {
public:
	SpriteComponent(std::shared_ptr<GameObject> owner, GraphicsDevice* gDevice, SpritePresets& presets);
	~SpriteComponent();

	void Update();
	void draw();

	Vector2D getViewAdjustedPosition();

	std::shared_ptr<SpriteComponent> sprite{ nullptr };
	std::shared_ptr<Texture> texture{ nullptr };
	std::shared_ptr<BodyComponent> spriteBody{ nullptr };
	std::shared_ptr<GameObject> owner{ nullptr };

private:

	GraphicsDevice* gDevice;
};
#endif // !SPRITECOMPONENT_H
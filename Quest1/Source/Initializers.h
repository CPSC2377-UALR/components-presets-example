#pragma once
#ifndef INITIALIZERS_H
#define INITIALIZERS_H

#include "Vector2D.h"
#include "InputDevice.h"
#include <memory>
#include <string>
#include "Definitions.h"

// TODO 11. We create a struct to represent the attributes for a specific type of component, i.e., the properties I need to initialize it.

struct SpritePresets {
	bool createSprite{ false };
	std::shared_ptr<Texture> spriteTexture{ nullptr };
};

struct BodyPresets {
	bool createBody{ false };
	Vector2D bodyPosition{ 0,0 };
	float angle{ 0.0f };
	std::shared_ptr<SpriteComponent>sprite{ nullptr };
};

// TODO 12. Plase note we can a struct that encompases the different presents we've created for the components
// WHy is this interesting? We simplify the signature of the methods involved in the creation of new objects
struct ObjectFactoryPresets {
	SpritePresets spriteInitializers;
	BodyPresets bodyInitializers;
};

#endif // !INITIALIZERS_H

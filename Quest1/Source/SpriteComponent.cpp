#include "SpriteComponent.h"
#include "BodyComponent.h"
#include "Initializers.h"
SpriteComponent::SpriteComponent(std::shared_ptr<GameObject> owner,  GraphicsDevice* gDevice, SpritePresets& presets) : Component(owner), gDevice(gDevice)
{
	this->texture = presets.spriteTexture;
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Update()
{
}

void SpriteComponent::draw()
{
	Vector2D updatedPosition;
	updatedPosition = getViewAdjustedPosition();
	float angle = spriteBody->getAngle();
	this->texture->draw(gDevice->getRenderer(), updatedPosition, angle, NULL);
}

Vector2D SpriteComponent::getViewAdjustedPosition()
{
	return (spriteBody->getPosition() + gDevice->getView()->getPosition());
}

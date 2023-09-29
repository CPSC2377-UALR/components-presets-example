#include "BodyComponent.h"


BodyComponent::BodyComponent(std::shared_ptr<GameObject> owner, BodyPresets& presets): Component(owner) {
	bodyPosition.position = presets.bodyPosition;
	bodyPosition.angle = presets.angle;
}
BodyComponent::~BodyComponent()
{
}

void BodyComponent::Update()
{
}

float BodyComponent::getAngle()
{
	return bodyPosition.angle;
}

Vector2D BodyComponent::getPosition()
{
	return bodyPosition.position;
}

void BodyComponent::setAngle(float angle)
{
	bodyPosition.angle = angle;
}

void BodyComponent::setPosition(Vector2D position)
{
	bodyPosition.position = position;
}
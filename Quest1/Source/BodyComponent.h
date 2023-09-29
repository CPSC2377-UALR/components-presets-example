#pragma once
#ifndef BODYCOMPONENT_H
#define BODYCOMPONENT_H
#include "Component.h"
#include "ComponentList.h"
#include "Vector2D.h"
#include "Initializers.h"
#include "Definitions.h"
struct GamePosition {
	Vector2D position;
	float angle;
};
class BodyComponent : public Component {
public:
	BodyComponent(std::shared_ptr<GameObject> owner, BodyPresets &presets);
	~BodyComponent();

	void Update();

	float getAngle();
	Vector2D getPosition();

	void setAngle(float angle);
	void setPosition(Vector2D position);
private:
	GamePosition bodyPosition;
};
#endif // !BODYCOMPONENT_H

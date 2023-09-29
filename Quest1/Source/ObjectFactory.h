#pragma once
#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "tinyxml2.h"
#include "Initializers.h"
#include "GraphicsDevice.h"
#include "ComponentList.h"
#include "Library.h"
#include "Definitions.h" 

class ObjectFactory {
public: 	
	ObjectFactory() {};
	ObjectFactory(GraphicsDevice* gDevice, Library* assetLibrary) : gDevice(gDevice), assetLibrary(assetLibrary) {};
	std::shared_ptr<GameObject> create(tinyxml2::XMLElement* objectElement);
	std::shared_ptr<GameObject> create(ObjectFactoryPresets* presets);
private:
	GraphicsDevice* gDevice{ nullptr };
	Library* assetLibrary{ nullptr };
	std::shared_ptr<ObjectFactoryPresets> createPresetsFromXML(tinyxml2::XMLElement* objectElement);
	void addSpritePresets(SpritePresets* presets, tinyxml2::XMLElement* componentElement);
	void addBodyPresets(BodyPresets* presets, tinyxml2::XMLElement* componentElement);
};
#endif // !OBJECTFACTORY_H

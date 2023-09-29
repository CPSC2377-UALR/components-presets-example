#include "ObjectFactory.h"

// TODO 08. How do we build objects now that they consist of several components?
// We extract data from XML and use that to initialize the components

std::shared_ptr<GameObject> ObjectFactory::create(tinyxml2::XMLElement* objectElement)
{
	// TODO 09. We create a present for each component: ad hoc data structure that encompass all the properties for an object
	// TODO 13. We populate the presents with data extracted from the XML file.
	std::shared_ptr<ObjectFactoryPresets> presets = createPresetsFromXML(objectElement);
	// TODO 14. Once we have all the data in the presets, we can use then to actually create the objects
	std::shared_ptr<GameObject> newObject = create(presets.get());
	return newObject;
}

std::shared_ptr<GameObject> ObjectFactory::create(ObjectFactoryPresets* presets)
{
	std::shared_ptr<GameObject> newObject = std::make_shared<GameObject>();
	if (presets->spriteInitializers.createSprite) {
		// Please note we need to pass the owner (pointer to an object instance) of the component
		newObject->AddComponent(std::make_shared<SpriteComponent>(newObject, gDevice, presets->spriteInitializers));
		presets->bodyInitializers.sprite = newObject->GetComponent<SpriteComponent>();
	}
	if (presets->bodyInitializers.createBody) {
		newObject->AddComponent(std::make_shared<BodyComponent>(newObject, presets->bodyInitializers));
		newObject->GetComponent<SpriteComponent>()->spriteBody = newObject->GetComponent<BodyComponent>();
	}
	// Use presents to create new object with the desired components and initialize their properties
	return newObject;
}

std::shared_ptr<ObjectFactoryPresets> ObjectFactory::createPresetsFromXML(tinyxml2::XMLElement* objectElement)
{
	std::unique_ptr<ObjectFactoryPresets> presets = std::make_unique<ObjectFactoryPresets>();
	for (tinyxml2::XMLElement* componentElement = objectElement->FirstChildElement(); componentElement; componentElement = componentElement->NextSiblingElement()) {
		std::string componentName = componentElement->Attribute("name");
		if (componentName == "Sprite") {
			addSpritePresets(&presets->spriteInitializers, componentElement);
		}
		if (componentName == "Body") {
			addBodyPresets(&presets->bodyInitializers, componentElement);
		}
		// Load presents from xml related to other components here 
	}
	return presets;
}

void ObjectFactory::addSpritePresets(SpritePresets* presets, tinyxml2::XMLElement* componentElement)
{
	presets->createSprite = true;
	presets->spriteTexture = assetLibrary->getArtAsset(componentElement->Attribute("asset"));
}

void ObjectFactory::addBodyPresets(BodyPresets* presets, tinyxml2::XMLElement* componentElement)
{
	presets->createBody = true;
	componentElement->QueryFloatAttribute("x", (float*)(&presets->bodyPosition.x));
	componentElement->QueryFloatAttribute("y", (float*)(&presets->bodyPosition.y));
	componentElement->QueryFloatAttribute("angle", (float*)(&presets->angle));
}

// Methods to load component-specific presents from the xml file

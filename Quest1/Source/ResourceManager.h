#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include<vector>
#include<memory>
#include <string>
#include <SDL.h>
#include "Library.h"
#include "ObjectFactory.h"
#include "InputDevice.h"

#include "Definitions.h"
class ResourceManager {
public:
	ResourceManager(std::string levelConfig, std::string libraryConfig);
	~ResourceManager();
	void update();
	void draw();

	//Devices
	std::unique_ptr<GraphicsDevice> gDevice{ nullptr };
	std::unique_ptr<InputDevice> iDevice{ nullptr };

	//Library
	std::unique_ptr<Library> assetLibrary{ nullptr };

	//factory
	std::unique_ptr<ObjectFactory> factory{ nullptr };

	std::vector<std::shared_ptr<GameObject>> objects;

	Uint32 FPS{ 0 };

private:
	std::vector<std::shared_ptr<GameObject>> newObjects;
};
#endif // ! RESOURCEMANAGER_H

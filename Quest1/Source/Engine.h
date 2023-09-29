#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include<memory>
#include <SDL.h>
#include "Library.h"
#include "ObjectFactory.h"
#include "InputDevice.h"
#include "Timer.h"

// TODO 02

class Engine {
public:
	Engine(std::string levelConfig, std::string libraryConfig);
	~Engine();
	// TODO 04. This method resets every single component we might have
	void reset();
	bool run();
	void update();
	void draw();

private:
	
	//Devices
	std::unique_ptr<GraphicsDevice> gDevice{ nullptr };
	std::unique_ptr<InputDevice> iDevice{ nullptr };

	//Library
	std::unique_ptr<Library> assetLibrary{ nullptr };

	//factory
	// TODO 03. Please note we have a single object factory instead of a vector of object fatory objects
	// We'll create objects out of the same ObjectClass. We replace the hierarchy of objects with a hierarchy of components that might
	// add to an object to customize it
	std::unique_ptr<ObjectFactory> factory{ nullptr };

	//So now all the objects will be instances of the GameObject class. Each instance might be comprised of different components
	std::vector<std::shared_ptr<GameObject>> objects;

	Uint32 FPS{ 0 };

};

#endif // !ENGINE_H


#include "Engine.h"
#include "View.h"

// TODO 05. We parese the XML file and we create the devices included in the engine acccordingly
Engine::Engine(std::string levelConfig, std::string libraryConfig)
{

	//Configuring Assets
	tinyxml2::XMLDocument libraryDoc;
	if (libraryDoc.LoadFile(libraryConfig.c_str()) != tinyxml2::XML_SUCCESS)
	{
		printf("Bad File Path");
		exit(1);
	}

	tinyxml2::XMLElement* libraryRoot = libraryDoc.FirstChildElement("Library");  //Root
	tinyxml2::XMLElement* libraryElement = libraryRoot->FirstChildElement("AssetLibrary"); // Asset Library

	//Configuring Game
	tinyxml2::XMLDocument levelDoc;
	if (levelDoc.LoadFile(levelConfig.c_str()) != tinyxml2::XML_SUCCESS)
	{
		printf("Bad File Path");
		exit(1);
	}

	tinyxml2::XMLElement* root = levelDoc.FirstChildElement("Game");
	tinyxml2::XMLElement* gameElement = root->FirstChildElement(); //Screen

	int screenWidth{ 0 };
	int screenHeight{ 0 };

	gameElement->QueryIntAttribute("width", &screenWidth);
	gameElement->QueryIntAttribute("height", &screenHeight);

	// irconde: Creating a GraphicsDevice

	gDevice = std::make_unique<GraphicsDevice>(screenWidth, screenHeight, true);

	// Constructing Asset Library
	assetLibrary = (std::make_unique<Library>());
	tinyxml2::XMLElement* asset = libraryElement->FirstChildElement("Asset");

	while (asset) {
		//Adding assets to Library
		assetLibrary->addArtAsset(gDevice.get(), asset->Attribute("name"), asset->Attribute("spritepath"));
		asset = asset->NextSiblingElement("Asset");
	}

	gameElement = gameElement->NextSiblingElement(); //FPS
	FPS = std::stoi(gameElement->GetText());

	// irconde: Creating an ObjectFactory
	factory = std::make_unique<ObjectFactory>(gDevice.get(), assetLibrary.get());

	gameElement = gameElement->NextSiblingElement(); //Devices

	tinyxml2::XMLElement* deviceConfig = gameElement->FirstChildElement("Input");

	// irconde: Creating an Inputdevice

	iDevice = std::make_unique<InputDevice>();
	gameElement = gameElement->NextSiblingElement();  //Objects

	// TODO 06. Constructing objects. 
	for (tinyxml2::XMLElement* currentElement = gameElement; currentElement; currentElement = currentElement->NextSiblingElement()) {
		//constructing objects
		objects.push_back(std::shared_ptr<GameObject>(factory->create(currentElement)));
	}
	
}

Engine::~Engine()
{
	this->reset();
}

void Engine::reset()
{
	iDevice = nullptr;
	gDevice = nullptr;
	assetLibrary = nullptr;
	factory = nullptr;
}

// TODO 07. This contains the actions executed in the game loop
bool Engine::run()
{
	if (iDevice->keyStates[InputDevice::gameEvent::QUIT]) {
		return false;
	}
	std::unique_ptr<Timer>frameRate = std::make_unique<Timer>();
	if (!frameRate->Initialize(FPS)) {
		printf("Frame Timer could not intialize! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	frameRate->start();
	this->update();
	this->draw();
	frameRate->fpsRegulate();
	return true; 
}

void Engine::update()
{
	iDevice->Update();
	for (auto& object : objects) {
		object->Update();
	}
}

void Engine::draw()
{
	gDevice->Begin();
	for (auto& object : objects) {
		object->draw();
	}
	gDevice->Present();
}

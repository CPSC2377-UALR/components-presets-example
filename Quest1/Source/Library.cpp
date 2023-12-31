#include "Library.h"

Library::Library(){}

Library::~Library()
{
}

std::shared_ptr<Texture> Library::getArtAsset(std::string keyName)
{
	return artLibrary.find(keyName)->second;
}

bool Library::addArtAsset(GraphicsDevice* gDevice, std::string keyName, std::string spritePath)
{
	artLibrary.emplace(keyName, std::make_shared<Texture>(gDevice, spritePath));
	if (!artLibrary[keyName]->initialzied) {
		auto atrIter = artLibrary.find(keyName);
		artLibrary.erase(atrIter);
		return false;
	}
	return true;
}

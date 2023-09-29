#pragma once
#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include "SDL.h"
#include "SDL_image.h"
#include "View.h"
#include "Definitions.h"
class GraphicsDevice
{

public:
	GraphicsDevice(Uint32 width, Uint32 height, bool fullScreen);
	GraphicsDevice() = delete;
	~GraphicsDevice();

	//Rendering functions
	void Begin();
	void Present();

	SDL_Renderer* getRenderer();
	View* getView();

	void setView(View* view);
private:
	//Window(s) to display graphics
	SDL_Window* screen{ nullptr };
	SDL_Renderer* renderer{ nullptr };

	std::unique_ptr<View> view{ nullptr };
	//Parameters
	const Uint32 SCREEN_WIDTH{ 0 };
	const Uint32 SCREEN_HEIGHT{ 0 };

};

#endif
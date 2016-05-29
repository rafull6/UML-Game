#include "core/oxygine.h"
#include "core/Game.h"
#include "Stage.h"
#include "DebugActor.h"

using namespace oxygine;

// init main game class
Game* game;

// This function is called each frame
int mainloop(){
	// It gets passed to our aircraft game implementation
	game->update();

	getStage()->update();

	if (core::beginRendering())
	{
		Color clearColor(32, 32, 32, 255);
		Rect viewport(Point(0, 0), core::getDisplaySize());
		getStage()->render(clearColor, viewport);

		core::swapDisplayBuffers();
	}

	// Update engine-internal components
	// If input events are available, they are passed to Stage::instance.handleEvent
	// If the function returns true, it means that the user requested the application to terminate
	bool done = core::update();

	return done ? 1 : 0;
}

// Application entry point
void run(){
	ObjectBase::__startTracingLeaks();

	// create main object
	game = new Game("Aircraft Fighter");

	core::init_desc desc;
	desc.title = game->getTitle();

#if OXYGINE_SDL || OXYGINE_EMSCRIPTEN
	desc.w = 960;
	desc.h = 640;
	desc.fullscreen = false;
#endif

	game->preinit();
	core::init(&desc);

	Stage::instance = new Stage(true);
	Point size = core::getDisplaySize();
	getStage()->setSize(size);

	game->setWindowIcon("icon.bmp");

	DebugActor::show();

	// Initializes our game. See game.cpp
	game->init();

#ifdef EMSCRIPTEN
	/*
	If you build for Emscripten, mainloop is called automatically and shouldn't be called here.
	See emscripten_set_main_loop in the EMSCRIPTEN section below
	*/
	return;
#endif


	// This is the main game loop.
	while (1)
	{
		int done = mainloop();
		if (done)
			break;
	}
	/*
	If we get here, the user has requested the Application to terminate.
	We dump and log all our created objects that have not been freed yet
	*/
	ObjectBase::dumpCreatedObjects();

	// See aircraft.cpp for the shutdown function implementation
	game->destroy();


	//renderer.cleanup();

	// Releases all internal components and the stage
	core::release();

	// The dump list should be empty by now,
	// we want to make sure that there aren't any memory leaks, so we call it again.
	ObjectBase::dumpCreatedObjects();

	ObjectBase::__stopTracingLeaks();
	//end
}

#ifdef __S3E__
int main(int argc, char* argv[])
{
	run();
	return 0;
}
#endif


#ifdef OXYGINE_SDL

#include "SDL_main.h"
extern "C"
{
	int main(int argc, char* argv[])
	{
		run();
		return 0;
	}
};
#endif

#ifdef EMSCRIPTEN
#include <emscripten.h>

void one() { mainloop(); }

int main(int argc, char* argv[])
{
	run();
	emscripten_set_main_loop(one, 0, 0);
	return 0;
}
#endif

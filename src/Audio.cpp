#include "oxygine-framework.h"

#include "core/STDFileSystem.h"


#include "SoundPlayer.h"
#include "SoundSystem.h"
#include "SoundInstance.h"

#include "Audio.h"

using namespace oxygine;


//it is our resources
//in real project you would have more than one Resources declarations. It is important on mobile devices with limited memory and you would load/unload them
Resources resources;
SoundPlayer sfxPlayer;
SoundPlayer musicPlayer;

void example_preinit()
{

}

void audio_init()
{
	//initialize our sound system with 16 channels

	SoundSystem::instance = SoundSystem::create();
	SoundSystem::instance->init(16);

	sfxPlayer.initialize();
	musicPlayer.initialize();

	sfxPlayer.setResources(&resources);
	musicPlayer.setResources(&resources);

	//load xml file with resources definition
	resources.loadXML("xmls/audio.xml");
}

void audio_update()
{
	SoundSystem::get()->update();
	sfxPlayer.update();
	musicPlayer.update();
}

void audio_destroy()
{
	sfxPlayer.stop();
	musicPlayer.stop();
	SoundPlayer::free();
	SoundSystem::free();

	resources.free();
}

void play_music()
{
	musicPlayer.play(resources.get("music1.ogg"));
}

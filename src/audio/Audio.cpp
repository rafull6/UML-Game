#include "oxygine-framework.h"
#include "oxygine-sound.h"
#include "core/STDFileSystem.h"


#include "SoundPlayer.h"
#include "SoundSystem.h"
#include "SoundInstance.h"

#include "Audio.h"

using namespace oxygine;

Resources resources;
SoundPlayer sfxPlayer;
SoundPlayer musicPlayer;

void example_preinit()
{

}

void audio_init()
{

	SoundSystem::instance = SoundSystem::create();
	SoundSystem::instance->init(16);


	sfxPlayer.initialize();
	musicPlayer.initialize();

	sfxPlayer.setResources(&resources);
	musicPlayer.setResources(&resources);

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
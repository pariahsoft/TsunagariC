/***************************************
** Tsunagari Tile Engine              **
** gosu-sound.h                       **
** Copyright 2011-2014 PariahSoft LLC **
***************************************/

// **********
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// **********

#ifndef GOSU_SOUND_H
#define GOSU_SOUND_H

#include <Gosu/Audio.hpp>

#include "../cache-template.cpp"
#include "../sounds.h"
#include "../readercache.h"

class GosuSoundInstance : public SoundInstance
{
public:
	GosuSoundInstance(Gosu::SampleInstance instance);

	~GosuSoundInstance() = default;

	bool playing();
	void stop();

	bool paused();
	void pause();
	void resume();

	void volume(double volume);
	void pan(double pan);
	void speed(double speed);

private:
	GosuSoundInstance() = delete;
	GosuSoundInstance(const GosuSoundInstance&) = delete;
	GosuSoundInstance& operator=(const GosuSoundInstance&) = delete;

	Gosu::SampleInstance instance;
};


class GosuSounds : public Sounds
{
public:
	GosuSounds();

	~GosuSounds() = default;

	std::shared_ptr<SoundInstance> play(const std::string& path);

	void garbageCollect();

private:
	GosuSounds(const GosuSounds&) = delete;
	GosuSounds& operator=(const GosuSounds&) = delete;

	ReaderCache<std::shared_ptr<Gosu::Sample>> samples;
};

#endif

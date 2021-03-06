/***************************************
** Tsunagari Tile Engine              **
** gosu-music.h                       **
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

#ifndef GOSU_MUSIC_H
#define GOSU_MUSIC_H

#include "../cache-template.cpp"
#include "../music.h"
#include "../readercache.h"

namespace Gosu {
	class Song;
}

class GosuMusic : public Music
{
public:
	GosuMusic();
	~GosuMusic();

	bool setIntro(const std::string& filename);
	bool setLoop(const std::string& filename);

	bool playing();
	void stop();

	void pause();
	void resume();

	void setVolume(double volume);

	void tick();

	void garbageCollect();

private:
	void playIntro();
	void playLoop();

	std::shared_ptr<Gosu::Song> musicInst, introMusic, loopMusic;

	ReaderCache<std::shared_ptr<Gosu::Song>> songs;
};

#endif

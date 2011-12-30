/******************************
** Tsunagari Tile Engine     **
** resourcer.h               **
** Copyright 2011 OmegaSDG   **
******************************/

#ifndef RESOURCER_H
#define RESOURCER_H

#include <deque>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <libxml/parser.h>
#include <Python.h>

#include "common.h"
#include "sound.h"
#include "xml.h"

namespace Gosu {
	class Bitmap;
	class Buffer;
	class Image;
	class Sample;
	class Song;
}

class GameWindow;

using boost::shared_ptr;

// We hand out and manage Gosu resources in these forms:
typedef boost::shared_ptr<Gosu::Image> ImageRef;
typedef boost::shared_ptr<Sample> SampleRef;
typedef boost::shared_ptr<Gosu::Song> SongRef;
typedef boost::shared_ptr<XMLDoc> XMLRef;
typedef std::deque<ImageRef> TiledImage;
typedef boost::shared_ptr<TiledImage> TiledImageRef;
typedef boost::shared_ptr<std::string> StringRef;

//! This class provides the engine's resource handling and caching.
class Resourcer
{
public:
	Resourcer(GameWindow* window, const ClientValues* conf);
	~Resourcer();
	bool init(char** argv);

	//! Returns true if the world contains a resource by that name.
	bool resourceExists(const std::string& name) const;

	//! Requests an image resource from disk or cache.
	ImageRef getImage(const std::string& name);

	//! Requests an image resource from the cache and splits it into a
	//! number of tiles each with width and height w by h. Returns false if
	//! the source image wasn't found.
	bool getTiledImage(TiledImage& img, const std::string& name,
		int w, int h, bool tileable);

	//! Returns a sound object from disk or cache.
	SampleRef getSample(const std::string& name);

	//! Returns a music stream from disk or cache.
	SongRef getSong(const std::string& name);

	//! Requests an XML resource from disk or cache.
	XMLRef getXMLDoc(const std::string& name,
		const std::string& dtdFile);

	//! Requests a Python script be run from disk or cache.
	bool runPythonScript(const std::string& name);

	//! Requests a text resource from disk or cache.
	std::string getText(const std::string& name);

	//! Expunge old stuff from the cache.
	void garbageCollect();

private:
	template<class Res>
	struct CacheEntry
	{
		Res resource;
		int lastUsed;
		int memoryUsed;
	};


	// Resource maps.
	typedef boost::unordered_map<const std::string, CacheEntry<ImageRef> >
		ImageRefMap;
	typedef boost::unordered_map<const std::string, CacheEntry<TiledImageRef> >
		TiledImageMap;
	typedef boost::unordered_map<const std::string, CacheEntry<SampleRef> >
		SampleRefMap;
	typedef boost::unordered_map<const std::string, CacheEntry<SongRef> >
		SongRefMap;
	typedef boost::unordered_map<const std::string, CacheEntry<XMLRef> >
		XMLRefMap;
	typedef boost::unordered_map<const std::string, CacheEntry<PyCodeObject*> >
		CodeMap;
	typedef boost::unordered_map<const std::string, CacheEntry<StringRef> >
		TextRefMap;


	//! Garbage collect a map.
	template<class Map, class MapValue>
	void reclaim(Map& map);

	//! Reads an XML document from disk and parses it.
	XMLDoc* readXMLDocFromDisk(const std::string& name,
		const std::string& dtdFile) const;

	//! Read a string resource from disk.
	std::string readStringFromDisk(const std::string& name) const;

	//! Read a generic resource from disk.
	Gosu::Buffer* read(const std::string& name) const;

	//! Helper function
	std::string path(const std::string& entryName) const;


	GameWindow* window;
	const ClientValues* conf;

	// Caches that store processed, game-ready objects. Garbage collected.
	ImageRefMap images;
	TiledImageMap tiles;
	SampleRefMap samples;
	SongRefMap songs;
	XMLRefMap xmls;
	CodeMap codes;
	TextRefMap texts;
};

void exportResourcer();

#endif


/***************************************
** Tsunagari Tile Engine              **
** images.h                           **
** Copyright 2011-2015 PariahSoft LLC **
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

#ifndef IMAGES_H
#define IMAGES_H

#include <memory>
#include <string>

class Image
{
public:
	virtual ~Image() = default;

	virtual void draw(double dstX, double dstY, double z) = 0;
	virtual void drawSubrect(double dstX, double dstY, double z,
	                 double srcX, double srcY,
	                 double srcW, double srcH) = 0;

	virtual unsigned width() const = 0;
	virtual unsigned height() const = 0;

protected:
	Image() = default;

private:
	Image(const Image&) = delete;
	Image& operator=(const Image&) = delete;
};


class TiledImage
{
public:
	virtual ~TiledImage() = default;

	virtual size_t size() const = 0;

	virtual const std::shared_ptr<Image>& operator[](size_t n) const = 0;

protected:
	TiledImage() = default;

private:
	TiledImage(const TiledImage&) = delete;
	TiledImage& operator=(const TiledImage&) = delete;
};


class Images
{
public:
	//! Acquire the global Images object.
	static Images& instance();

	virtual ~Images() = default;

	//! Load an image from the file at the given path.
	virtual std::shared_ptr<Image> load(const std::string& path) = 0;

	//! Load an image of tiles from the file at the given path. Each tile
	//! with have width and heigh as specified.
	virtual std::shared_ptr<TiledImage> loadTiles(const std::string& path,
		unsigned tileW, unsigned tileH) = 0;

	//! Free images not recently used.
	virtual void garbageCollect() = 0;

protected:
	Images() = default;

private:
	Images(const Images&) = delete;
	Images& operator=(const Images&) = delete;
};

#endif

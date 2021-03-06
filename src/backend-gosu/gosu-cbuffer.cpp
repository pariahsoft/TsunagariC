/***************************************
** Tsunagari Tile Engine              **
** gosu-cbuffer.cpp                   **
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

#include <string.h>

#include "gosu-cbuffer.h"

GosuCBuffer::GosuCBuffer(const void* data, size_t size)
	: _data(data), _size(size)
{
}

size_t GosuCBuffer::size() const
{
	return _size;
}

void GosuCBuffer::resize(size_t)
{
	// NOOP
}

void GosuCBuffer::read(size_t offset, size_t length, void* destBuffer) const
{
	memcpy(destBuffer, (const char*)_data + offset, length);
}

void GosuCBuffer::write(size_t, size_t, const void*)
{
	// NOOP
}

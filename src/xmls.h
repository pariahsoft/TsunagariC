/***************************************
** Tsunagari Tile Engine              **
** xmls.h                              **
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

#ifndef XML_H
#define XML_H

#include <memory>
#include <string>

#include <libxml/tree.h>

#include "cache-template.cpp"

#ifndef LIBXML_TREE_ENABLED
	#error Tree must be enabled in libxml2
#endif

class XMLDoc;

class XMLNode {
public:
	XMLNode();
	XMLNode(XMLDoc* doc, xmlNode* node);

	XMLNode childrenNode() const;
	XMLNode next() const;

	bool is(const char* name) const;

	std::string content() const;
	bool intContent(int* i) const;
	bool doubleContent(double* d) const;

	bool hasAttr(const std::string& name) const;
	std::string attr(const std::string& name) const;
	bool intAttr(const std::string& name, int* i) const;
	bool doubleAttr(const std::string& name, double* d) const;

	//! Whether this is a valid node (non-NULL).
	operator bool() const;

private:
	XMLDoc* doc;
	xmlNode* node;
};

class XMLDoc {
public:
	XMLDoc();
	bool init(const std::string& path,
	          const std::string& data,
	          xmlDtd* dtd);

	XMLNode root();
	xmlNode* temporaryGetRoot() const;
	const std::string& path() const;

	//! Equivalent to doc::unique();
	bool unique() const;

	//! Equivalent to doc::use_count().
	long use_count() const;

	//! Signifies whether document is has been initialized, parsed
	//! correctly, and is valid.
	operator bool() const;

private:
	std::shared_ptr<xmlDoc> doc;
	std::string path_;
};

class XMLs {
public:
	//! Acquire the global XMLs object.
	static XMLs& instance();

	XMLs();
	~XMLs() = default;

	//! Load an XML document.
	std::shared_ptr<XMLDoc> load(const std::string& path,
		const std::string& dtdType);

	//! Free XML documents not recently used.
	void garbageCollect();

private:
	XMLs(const XMLs&) = delete;
	XMLs(XMLs&&) = delete;
	XMLs& operator=(const XMLs&) = delete;
	XMLs& operator=(XMLs&&) = delete;

	// We can't use a ReaderCache here because XMLDocs are constructed
	// with two arguments, but a ReaderCache only supports the use of
	// one.
	Cache<std::shared_ptr<XMLDoc>> documents;
};

#endif

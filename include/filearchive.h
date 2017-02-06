/*
    CIrrlicht - C Bindings for Irrlicht Engine

    Copyright (C) 2014- Danyal Zia (catofdanyal@yahoo.com)

    This software is provided 'as-is', without any express or
    implied warranty. In no event will the authors be held
    liable for any damages arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute
    it freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented;
       you must not claim that you wrote the original software.
       If you use this software in a product, an acknowledgment
       in the product documentation would be appreciated but
       is not required.

    2. Altered source versions must be plainly marked as such,
       and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any
       source distribution.
*/

#pragma once

#include "irrtypes.h"
#include "compileconfig.h"

//! FileSystemType: which Filesystem should be used for e.g. browsing
enum EFileSystemType
{
	FILESYSTEM_NATIVE = 0,	// Native OS FileSystem
	FILESYSTEM_VIRTUAL	// Virtual FileSystem
};

typedef enum EFileSystemType EFileSystemType;

//! Contains the different types of archives
enum E_FILE_ARCHIVE_TYPE
{
	//! A PKZIP archive
	EFAT_ZIP     = MAKE_CIRR_ID('Z','I','P', 0),

	//! A gzip archive
	EFAT_GZIP    = MAKE_CIRR_ID('g','z','i','p'),

	//! A virtual directory
	EFAT_FOLDER  = MAKE_CIRR_ID('f','l','d','r'),

	//! An ID Software PAK archive
	EFAT_PAK     = MAKE_CIRR_ID('P','A','K', 0),

	//! A Nebula Device archive
	EFAT_NPK     = MAKE_CIRR_ID('N','P','K', 0),

	//! A Tape ARchive
	EFAT_TAR     = MAKE_CIRR_ID('T','A','R', 0),

	//! A wad Archive, Quake2, Halflife
	EFAT_WAD     = MAKE_CIRR_ID('W','A','D', 0),

	//! The type of this archive is unknown
	EFAT_UNKNOWN = MAKE_CIRR_ID('u','n','k','n')
};

typedef enum E_FILE_ARCHIVE_TYPE E_FILE_ARCHIVE_TYPE;

struct irr_IFileArchive;
struct irr_IReadFile;
struct irr_IFileList;

typedef struct irr_IFileArchive irr_IFileArchive;
typedef struct irr_IReadFile irr_IReadFile;
typedef struct irr_IFileList irr_IFileList;

CIRRLICHT_API irr_IReadFile* irr_IFileArchive_createAndOpenFile(irr_IFileArchive* filearchive, const char* filename);
CIRRLICHT_API irr_IReadFile* irr_IFileArchive_createAndOpenFile2(irr_IFileArchive* filearchive, unsigned int index);
CIRRLICHT_API const irr_IFileList* irr_IFileArchive_getFileList(irr_IFileArchive* filearchive);
CIRRLICHT_API E_FILE_ARCHIVE_TYPE irr_IFileArchive_getType(irr_IFileArchive* filearchive);
CIRRLICHT_API const char* irr_IFileArchive_getArchiveName(irr_IFileArchive* filearchive);
CIRRLICHT_API void irr_IFileArchive_setPassword(irr_IFileArchive* filearchive, const char* pass);
CIRRLICHT_API const char* irr_IFileArchive_getPassword(irr_IFileArchive* filearchive);

struct irr_IArchiveLoader;
typedef struct irr_IArchiveLoader irr_IArchiveLoader;

CIRRLICHT_API bool irr_IArchiveLoader_isALoadableFileFormat(irr_IArchiveLoader* loader, const char* filename);
CIRRLICHT_API bool irr_IArchiveLoader_isALoadableFileFormat2(irr_IArchiveLoader* loader, irr_IReadFile* file);
CIRRLICHT_API bool irr_IArchiveLoader_isALoadableFileFormat3(irr_IArchiveLoader* loader, E_FILE_ARCHIVE_TYPE fileType);
CIRRLICHT_API irr_IFileArchive* irr_IArchiveLoader_createArchive(irr_IArchiveLoader* loader, const char* filename, bool ignoreCase, bool ignorePaths);
CIRRLICHT_API irr_IFileArchive* irr_IArchiveLoader_createArchive2(irr_IArchiveLoader* loader, irr_IReadFile* file, bool ignoreCase, bool ignorePaths);

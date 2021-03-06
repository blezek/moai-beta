// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"

#include <uslscore/USFilename.h>
#include <uslscore/USFileSys.h>
#include <uslscore/USFileStream.h>
#include <stdio.h>

//----------------------------------------------------------------//
void USFileStream::Close () {

	if ( this->mFile ) {
		fclose ( this->mFile );
	}
	
	this->mLength = 0;
	this->mFile = 0;
}

//----------------------------------------------------------------//
void USFileStream::Flush () {

	fflush ( this->mFile );
}

//----------------------------------------------------------------//
u32 USFileStream::GetCursor () {

	return ( u32 )ftell ( this->mFile );
}

//----------------------------------------------------------------//
FILE* USFileStream::GetFile () {

	return this->mFile;
}

//----------------------------------------------------------------//
u32 USFileStream::GetLength () {

	return this->mLength;
}

//----------------------------------------------------------------//
bool USFileStream::OpenRead ( cc8* filename ) {

	Close ();
	
	this->mFile = fopen ( filename, "rb" );
	if ( this->mFile ) {

		fseek ( this->mFile, 0, SEEK_END );
		this->mLength = ( u32 )ftell ( this->mFile );
		fseek ( this->mFile, 0, SEEK_SET );
	}

	return this->mFile != NULL;
}

//----------------------------------------------------------------//
bool USFileStream::OpenWrite ( cc8* filename, bool affirmPath ) {

	Close ();
	
	if ( affirmPath ) {
		USFileSys::AffirmPath ( USPathOps::GetPath ( filename, true ));
	}

	this->mFile = fopen ( filename, "wb" );
	return this->mFile != NULL;
}

//----------------------------------------------------------------//
u32 USFileStream::ReadBytes ( void* buffer, u32 size ) {

	return ( u32 )fread ( buffer, 1, size, this->mFile );
}

//----------------------------------------------------------------//
void USFileStream::Seek ( long offset, int origin ) {

	fseek ( this->mFile, offset, origin );
}

//----------------------------------------------------------------//
USFileStream::USFileStream () :
	mFile ( 0 ),
	mLength ( 0 ) {
}

//----------------------------------------------------------------//
USFileStream::~USFileStream () {
	Close ();
}

//----------------------------------------------------------------//
u32 USFileStream::WriteBytes ( const void* buffer, u32 size ) {

	u32 result = ( u32 )fwrite ( buffer, 1, size, this->mFile );
	
	u32 cursor = ( u32 )ftell ( this->mFile );
	if ( cursor > this->mLength ) {
		this->mLength = cursor;
	}

	return result;
}

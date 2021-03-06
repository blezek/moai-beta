// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <uslsext/USVertexFormatMgr.h>

//================================================================//
// USVertexFormatMgr
//================================================================//

//----------------------------------------------------------------//
const USVertexFormat& USVertexFormatMgr::GetPreset ( u32 presetID ) {

	assert ( presetID < TOTAL_PRESETS );
	return this->mFormats [ presetID ];
}

//----------------------------------------------------------------//
USVertexFormatMgr::USVertexFormatMgr () {

	USVertexFormat* format;
	
	format = &this->mFormats [ VTX_FMT_XYC ];
	
	format->Clear ();
	format->DeclareVertexArray ( GL_FLOAT, 2 );
	format->DeclareColorArray ( GL_UNSIGNED_BYTE );
	
	format = &this->mFormats [ VTX_FMT_XYUVC ];
	
	format->Clear ();
	format->DeclareVertexArray ( GL_FLOAT, 2 );
	format->DeclareTexCoordArray ( GL_FLOAT, 2 );
	format->DeclareColorArray ( GL_UNSIGNED_BYTE );
}

//----------------------------------------------------------------//
USVertexFormatMgr::~USVertexFormatMgr () {
}
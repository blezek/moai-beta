// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <uslscore/USLog.h>

#ifdef ANDROID
	#include <android/log.h>
#endif

//================================================================//
// USLog
//================================================================//

//----------------------------------------------------------------//
void USLog::Print ( cc8* format, ... ) {
	UNUSED ( format );

	//#ifdef _DEBUG

		va_list args;
		va_start ( args, format );	
		
		#ifdef ANDROID
			char str [ 1024 ];
			vsnprintf ( str, 1024, format, args );
			__android_log_print(ANDROID_LOG_ERROR,"Moai Debug", "%s",str);
		#else
			vprintf ( format, args );
		#endif
		
		va_end ( args );

	//#endif
}

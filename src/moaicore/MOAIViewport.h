// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIVIEWPORT_H
#define	MOAIVIEWPORT_H

//================================================================//
// MOAIViewport
//================================================================//
/**	@name	MOAIViewport
	@text	Viewport object.
*/
class MOAIViewport :
	public virtual USLuaObject,
	public USViewport {
private:

	//----------------------------------------------------------------//
	static int		_setOffset		( lua_State* L );
	static int		_setRotation	( lua_State* L );
	static int		_setScale		( lua_State* L );
	static int		_setSize		( lua_State* L );

public:
	
	DECL_LUA_FACTORY ( MOAIViewport )
	
	//----------------------------------------------------------------//
					MOAIViewport			();
					~MOAIViewport			();
	void			RegisterLuaClass		( USLuaState& state );
	void			RegisterLuaFuncs		( USLuaState& state );
	STLString		ToString				();
};

#endif

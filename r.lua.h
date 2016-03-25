#include <windef.h>
#include <iostream>
#include <vector>

typedef void(*Lua_pushstring)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_setfield)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_createtable)(/*SNIPPED FOR SECURITY*/);
typedef int(*Lua_error)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_pushcclosure)(/*SNIPPED FOR SECURITY*/);
typedef int(*Lua_pcall)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_createtable)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_pushlightuserdata)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_getfield)(/*SNIPPED FOR SECURITY*/);
typedef void*(*Lua_newuserdata)(/*SNIPPED FOR SECURITY*/);
typedef int(*Lua_setmetatable)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_pushnumber)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_settop)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_pushboolean)(/*SNIPPED FOR SECURITY*/);
typedef void(*Lua_pushinteger)(/*SNIPPED FOR SECURITY*/);

typedef int(*LSetProperty)(DWORD luaState);
//typedef int(*LGetProperty)(DWORD luaState);

typedef struct Vector3 { /*SNIPPED FOR SECURITY*/ };

typedef struct CFrame
{
	/*SNIPPED FOR SECURITY*/
};

typedef struct InstanceTable {
	/*SNIPPED FOR SECURITY*/
};

typedef struct ScanResults {
	DWORD failList[13];
	DWORD failCount;
};

//typedef int(__thiscall *SetMinutesAfterMidnight)(/*SNIPPED FOR SECURITY*/);
typedef int(__thiscall *SetCFrame)(/*SNIPPED FOR SECURITY*/);
typedef CFrame*(__thiscall *GetCFrame)(/*SNIPPED FOR SECURITY*/);
typedef int(__thiscall *PlaySoundInstance)(/*SNIPPED FOR SECURITY*/);
typedef int(__thiscall *StopSoundInstance)(/*SNIPPED FOR SECURITY*/);

class RLua {
	DWORD L;
	LSetProperty lSetProperty;
	//LGetProperty lGetProperty;
	ScanResults results;
	InstanceTable getInstanceTable(DWORD instance, DWORD offset);
	SetCFrame setCFrame;
	GetCFrame getCFrame;

public:
	//RLua(const DWORD lcvPtr);
	void initiate(const DWORD lcvPtr);
	DWORD getLuaState();
	ScanResults getInitResults();
	void setProperty(DWORD instance, const char* propName, const char* valueType, void* value);

	Lua_pushstring pushstring;
	Lua_setfield setfield;
	Lua_createtable createtable;
	Lua_error error;
	Lua_pushcclosure pushcclosure;
	Lua_pcall pcall;
	Lua_pushlightuserdata pushlightuserdata;
	Lua_pushnumber pushnumber;
	Lua_getfield getfield;
	Lua_newuserdata newuserdata;
	Lua_setmetatable setmetatable;
	Lua_settop settop;
	Lua_pushboolean pushboolean;
	Lua_pushinteger pushinteger;

	std::vector<DWORD> getChildren(DWORD instance);
	std::vector<DWORD> getRecursiveChildren(DWORD instance);
	DWORD getChildByName(DWORD instance, const char* name);
	DWORD getInstanceInHierarchy(DWORD gameInstance, char** names, DWORD size);
	std::vector<DWORD> getPlayers(DWORD gameInst);
	DWORD getPlayerByName(DWORD gameInstance, const char* name);
	DWORD getCharacterFromPlayer(DWORD player);
	//DWORD createInstance(char *instanceName, DWORD parent);
	void destroyInstance(DWORD instance); // naked
	void setObjectCFrame(DWORD instance, float x, float y, float z);
	void setObjectCFrame(DWORD instance, CFrame* cfStruct);
	CFrame* getObjectCFrame(DWORD instance);
	DWORD getLocalPlayer(DWORD gameInstance);
	void unanchorChildren(DWORD instance);
	void unlockChildren(DWORD instance);
	DWORD clearInstanceByName(DWORD instance, const char* name);
	DWORD clearInstanceByClass(DWORD instance, const char* cname);
	const char* getName(DWORD instance);
	const char* getClassName(DWORD instance);

	//SetMinutesAfterMidnight setMinutesAfterMidnight;
	PlaySoundInstance playSoundInstance;
	StopSoundInstance stopSoundInstance;

	DWORD setInstanceParent;
	DWORD getInstanceIDFromName;
};

DWORD createInstance(RLua& rLua, char *instanceName, DWORD parent);

#include <Windows.h>
#include "rlua.h"


using namespace std;


void RLua::initiate(const DWORD lcvPtr) {
	/* SNIPPED FOR SECURITY */
}

DWORD RLua::getLuaState() { return L; }

ScanResults RLua::getInitResults() { return results; }

void RLua::setProperty(DWORD instance, const char* propName, const char* valueType, void* value) {
	/* SNIPPED FOR SECURITY */
}

/* SNIPPED FOR SECURITY */

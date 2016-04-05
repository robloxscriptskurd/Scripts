#include <iostream>
#include <Windows.h>
#include "Injection.h"

using namespace std;

int main() {
	cout << "Searching for ROBLOX... " << endl;
	HWND hWindow = FindWindow(NULL, L"ROBLOX");
	if (!hWindow) {
		cerr << "ERROR: Failed to find ROBLOX. " << endl;
		system("PAUSE");
	}
	else {
		cout << "Found ROBLOX's hook! " << endl;
		InjectDLL("RobloxPlayerBeta.exe");
	}
	std::cin.get();
}

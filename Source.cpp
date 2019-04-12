#include <iostream>
#include <string>
#include <fstream>

#include "Auth.h"
#include "UserDB.h"

using namespace std;

int main()
{
	UsersDB udb;

	int u1 = udb.getLastUserID();
	
	cout << u1;
	system("pause");
	return 0;
}
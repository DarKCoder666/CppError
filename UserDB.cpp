#include <iostream>
#include <string>
#include <fstream>
#include <string>

#include "Auth.h"
#include "UserDB.h"

using namespace std;

void UsersDB::createUser(User user)
{
	string line = "\n" + to_string(user.getId()) + "  " + to_string(user.getRole()) + "  " + user.getLogin() + "  " + user.getPassword();
	ofstream file;
	file.open(UserDB::DBFilename, ios_base::app);
	file << line;
	file.close();
}

User UsersDB::getUserByLine(string userStr)
{
	bool flag = false;
	int paramNum = 0;
	string param = "";

	string login, password;
	int role, id;

	for (char& c : userStr)
	{
		if (c == ' ' && flag == false)
		{
			flag = true;
		}
		else if (c == ' ' && flag == true)
		{
			switch (paramNum)
			{
			case 0:
				id = stoi(param);
				break;
			case 1:
				role = stoi(param);
				break;
			case 2:
				login = param;
				break;
			case 3:
				password = param;
			}

			param = "";
			paramNum++;
			flag = false;
		}
		else {
			param += c;
		}
	}

	return User(login, password, role, id);
}

User UsersDB::getUserByLoginAndPassword(string login, string password)
{
	ifstream file;
	file.open(UserDB::DBFilename);
	string userStr;
	if (file.is_open())
	{
		while (getline(file, userStr))
		{
			User user = getUserByLine(userStr);
			if (user.getLogin() == login && user.getPassword() == password) {
				return user;
			}
		}
	}
}

int UsersDB::getLastUserID()
{
	ifstream file;
	file.open(UserDB::DBFilename);

	if (file.is_open()) {
		file.seekg(-1, ios_base::end);

		bool keepLooping = true;
		while (keepLooping) {
			char ch;
			file.get(ch);

			if ((int)file.tellg() <= 1) {
				file.seekg(0);
				keepLooping = false;
			}
			else if (ch == '\n') {
				keepLooping = false;
			}
			else {
				file.seekg(-2, ios_base::cur);
			}
		}

		string lastLine;
		getline(file, lastLine);

		if (!lastLine.size()) {
			return 0;
		}
		User lastUser = getUserByLine(lastLine);
		return lastUser.getId();
	}
}
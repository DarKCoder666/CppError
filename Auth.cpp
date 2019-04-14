#include <iostream>
#include <string>
#include <vector>

#include "Auth.h"

using namespace std;

/* USER class declaration */

int User::getId(){ return id; }
string User::getLogin(){ return login; }
string User::getPassword(){ return password; }
int User::getRole(){ return role; }

User::User(string login = "", string password = "", int role = 2, int id = NULL)
{
	this->id = (id == NULL) ? numberOfUsers++ : id;
	this->login = login;
	this->password = password;
	this->role = role;
}
int User::numberOfUsers = 0;

/* Auth class declaration */

void Auth::signup()
{
	cout << "\nLogin: ";
	cin >> login;
	cout << "\nPassword: ";
	cin >> password;
	cout << "\nRole(1 - admin; 2 - user): ";
	cin >> role;

	User newUser(login, password, role);
	users.insert(users.end(), newUser);
}

/*
Sign in method
Returns 1 if signed successfully, otherwise 0
*/
int Auth::signin()
{
	cout << "\nLogin: ";
	cin >> login;
	cout << "\nPassword: ";
	cin >> password;

	// Checking for existing user with such login and password
	for (int i = 0; i < User::numberOfUsers; i++)
	{
		if (users[i].getLogin() == login && users[i].getPassword() == password)
		{
			return 1;
		}
	}
	return 0;
}
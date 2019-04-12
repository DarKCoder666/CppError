#include <iostream>
#include <string>
#include <vector>

//#include "Auth.h"

using namespace std;

class User
{
private:
	string login, password;
	int role, id;
public:
	static int numberOfUsers;

	int getId(){ return id; }
	string getLogin(){ return login; }
	string getPassword(){ return password; }
	int getRole(){ return role; }

	User(string login = "", string password = "", int role = 2, int id = NULL)
	{
		this->id = (id == NULL) ? numberOfUsers++ : id;
		this->login = login;
		this->password = password;
		this->role = role;
	}
};
int User::numberOfUsers = 0;

class Auth
{
private:
	string login, password;
	int role;
	vector<User> users;
public:
	/*
	SignUp method
	*/
	void signUp()
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
	int signIn()
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
};

void initializeAuth()
{
	//int User::numberOfUsers = 10;
}
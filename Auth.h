#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User{
private:
	string login, password;
	int role, id;
public:
	static int numberOfUsers;

	User(string, string, int, int);
	int getId();
	int getRole();
	string getLogin();
	string getPassword();
};

class Auth{
	string login, password;
	int role;
	vector<User> users;
public:
	void signup();
	int signin();
};
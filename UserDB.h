#include <string>
using namespace std;

namespace UserDB {
	const string DBFilename = "users.txt";
}

class UsersDB {
public:
	void createUser(User);
	int getLastUserID();
	User getUserByLine(string);
	User getUserByLoginAndPassword(string, string);
};

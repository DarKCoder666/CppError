class UsersDB {
public:
	void createUser(User);
	int getLastUserID();
	User getUserByLine(string);
	User getUserByLoginAndPassword(string, string);
};

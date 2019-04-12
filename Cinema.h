#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Session {};

class Hole {
private:
	vector<Session> sessionsId;
	string name;
	int id, cinemaId;
public:

};

class Cinema
{
private:
	vector<Hole> holesId;
	string name;
	int id, ownerId;
public:
	static int numberOfCinemas;
};

int Cinema::numberOfCinemas = 0;

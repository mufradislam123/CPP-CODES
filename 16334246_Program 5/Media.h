#ifndef MEDIA_H
#define MEDIA_H
#include<iostream>
#include<string>
using namespace std;
class Media {
protected:
	string id;
	string name;
	int runningTime;
	
public:
	Media(string identifier = "", string username = "", int time = 0) : id{ identifier }, name{ username }, runningTime{ time }{

	}
	virtual string getType() const = 0;
	string getId() const {
		return id;
	}
	string getName() const {
		return name;
	}

	int getRunningTime() const {
		return runningTime;
	}
	void setId(string id) {
		this->id = id;
	}

	void setName(string name) {
		this->name = name;
	}
	void setRunningTime(int time) {
		runningTime = time;
	}

	virtual void ReadData(istream& is) {
		string identifier;
		string username;
		int time;

		if (!is.eof()) {
			is >> identifier;
			getline(is>>ws,username);
			is >> time;
			if (!is.fail()) {
				this->id = identifier;
				this->name = username;
				this->runningTime = time;
			}
		}
	}
	virtual void WriteData(ostream& os) {
		os << id << endl;
		os << name << endl;
		os << runningTime << endl;
	}
};
#endif
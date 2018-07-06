#ifndef STATUS_H_
#define STATUS_H_

#include "Post.h"

class Status :public Post {
private:
	string feelings [10] = {"sad", "mad", "happy", "determined"};
	int size = 4;
	int choice;
	string text;
	string feeling;
	string time;

public:
	Status();
	Status (string, int);
	void viewFeelings ();
	void addFeeling (int);
	void addStatus (string);
	//void edit ();
	virtual void view ();
	virtual ~Status();
};

#endif //STATUS_H_

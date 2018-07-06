#ifndef POLL_H_
#define POLL_H_

#include "Post.h"

class Poll : public Post {
private:
	string Question;
	string time;
	string *answers;
	int *votes;
	string** voters;
	int numberOfAnswers;

public:
	Poll();
	void addQuestion (string);
	void addAnswers (string);
	void removeAnswers (int);
	void addthisInt (int, int*&);
	void removethisInt (int, int, int*&);
	void upVote (string, int);
	void downVote (string, int);
	virtual void view ();
	//void edit ();
	virtual ~Poll();
};

#endif //POLL_H_

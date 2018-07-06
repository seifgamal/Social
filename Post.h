#ifndef POST_H_
#define POST_H_

#include "DateTime.h"
#include "Template.h"

class Post {

protected:
int numberOfLikers;
int numberOfDislikers;
int numberOfComments;
string *comments;
string *likers;
string *dislikers;
DateTime dateandtime;


public:
	Post();
	void like (string);
	void dislike (string);
	string viewComment (int);
	void addcomment (string);
	void deleteComment(int);
	int getNumberofComment ();
	int getNumberofLikers ();
	int getNumberofDislikers ();

	void edit (); //not sure yet!
	virtual void view () = 0;
	virtual ~Post();
};

#endif //POST_H_

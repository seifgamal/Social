#ifndef SOCIAL_MESSAGE_H
#define SOCIAL_MESSAGE_H

#include "DateTime.h"

class User;

class Message {
private:
    string text;
	User *sender;
    DateTime dateTime;

public:

    Message(string text, User *sender);

    User *getSender();
    string getText();
	void setDate(DateTime);

	string getMessage();
	DateTime getDateTime();

    friend ostream &operator<<(ostream &out, Message &M);
};


#endif //SOCIAL_MESSAGE_H



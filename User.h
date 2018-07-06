#ifndef USER_H
#define USER_H

#include "Poll.h"
#include "Photo.h"
#include "Status.h"
#include "Message.h"
#include "Notifications.h"

class System;

class User {

private:

	int ID;
    Notifications *notifications;
    string name, password, gender, email;
    DateTime birthDate;
    int friendsCount;
    User **friends;
    vector<Message> receivedMessages;
    vector<Message> sentMessages;

    int numberOfPosts;
    Post **posts;

    bool strongPassword(string password);
    bool validEmail(string email);
    bool validName(string name);


    void pushFriend(User *aUser); // send friend request => accept => add friend
public:

    User();

    Notifications *getNotifications();

    int findFriend(string email); // return index or -1 if not found

    void sendFriendRequest(User *aUser);
    void acceptFriend(User *aUser); // accept friend request from aUser
    void removeFriend(User *aUser); // remove friend from friends list

    void addPost (Post*);
    void removePost (int);
    Post* getPost (int);

    void sendMessage(User *aUser, Message newMessage);

    int getID ();
    void setID (int);
    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
    void setEmail(string email, System &currentSystem);
    string getEmail();
    void setGender(int);
    string getGender();
    void setBirthDate(DateTime birthDate);
    DateTime getBirthDate();
    int getFriendsCount();
    User* getFriend(int index);
    int getReceivedMessagesCount();
    Message & getReceivedMessage(int index);
    int getSentMessagesCount();
    Message & getSentMessage(int index);
    int getNumberOfPosts ();

    ~User();
};

#endif // USER_H

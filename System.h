#ifndef System_H
#define System_H

#include "User.h"
#include "Template.h"

class System {
private:
    User **users;
    int usersCount;
    User *loggedInUser;

    void mergeSort(User **arr, int N); // sort users by email
public:
    System(); // get data from file

    int findUser(string email); // binary search return index or -1 if not found
    vector <int> suggestedFriends (User *);
    User *getLoggedInUser();
    User *getUser(int index);

    void signUp(User *newUser);
    bool signIn(string email, string password);
    bool isSignedIn();
    void signOut();

    int getUsersCount();

    ~System();  // call write on file function
};

#endif //System_H

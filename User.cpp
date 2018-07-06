#include "User.h"
#include "System.h" // included in .cpp to avoid recursion

User::User() {
    posts = NULL;
    friends = NULL;
    notifications = new Notifications;
    friendsCount = 0;
    numberOfPosts = 0;
}

//friends functions

int User::findFriend(string email) {
    int lower = 0, upper = friendsCount - 1;

    while (lower <= upper) {
        int mid = (lower + upper) / 2;

        if (friends[mid]->getEmail() > email)
            upper = mid - 1;
        else if (friends[mid]->getEmail() < email)
            lower = mid + 1;
        else
            return mid;
    }
    return -1;
}

void User::sendFriendRequest(User *aUser) {
    if (findFriend(aUser->getEmail()) != -1)
        throw "User is already a friend.";
    if (aUser->getEmail() == email)
        throw "You can't add yourself.";
    if (aUser->getNotifications()->findFriendRequest(email) != -1)
        throw "Pending friend request.";

    aUser->getNotifications()->receiveFriendRequest(this);
}

void User::acceptFriend(User *aUser) {

    int index = notifications->findFriendRequest(aUser->getEmail());
    if (index == -1)
        throw "No friend request from this User.";

    notifications->acceptFriendRequest(index);

    aUser->notifications->receiveAcceptedFriend(this);

	pushFriend(aUser);
	aUser->pushFriend(this);
}

void User::pushFriend(User *aUser) {

    User **tmpFriends = new User *[friendsCount + 1];

    bool pushed = false;
    for (int i = 0; i <= friendsCount; i++) {
        if (!pushed && (i == friendsCount || friends[i]->email > aUser->email)) {
            tmpFriends[i] = aUser;
            pushed = true;
        }
        if (!pushed)
            tmpFriends[i] = friends[i];
        else if (i != friendsCount)
            tmpFriends[i + 1] = friends[i];
    }

    delete[] friends;
    friends = tmpFriends;

    friendsCount++;

}

void User::removeFriend(User *aUser) {

    int index = findFriend(aUser->email);

    if (index == -1)
        throw "Friend not found.";

    User **tmpFriends = new User *[friendsCount - 1];

    for (int i = 0; i < friendsCount; i++) {
        if (i == index)
            continue;
        if (i > index)
            tmpFriends[i - 1] = friends[i];
        else
            tmpFriends[i] = friends[i];
    }
    delete[] friends;
    friends = tmpFriends;
    friendsCount--;

}


//posts

void User::addPost(Post *newPost){

	Post** TmpPosts = new Post* [numberOfPosts+1];

	for (int i = 0; i < numberOfPosts; i++)
		TmpPosts[i] = posts [i];

	delete [] posts;

	posts = TmpPosts;


	posts [numberOfPosts] = newPost;

	++numberOfPosts;

}


//setters and getters

int User::getNumberOfPosts(){
	return numberOfPosts;
}

void User::sendMessage(User *aUser, Message newMessage) {
    sentMessages.push_back(newMessage);
    aUser->receivedMessages.push_back(newMessage);
    aUser->getNotifications()->receiveMessage();
}

int User::getFriendsCount() {
    return friendsCount;
}

int User::getReceivedMessagesCount() {
    return receivedMessages.size();
}

int User::getSentMessagesCount() {
    return sentMessages.size();
}

void User::setBirthDate(DateTime date) {
    birthDate = date;
}

void User::setPassword(string password) {
    if (!strongPassword(password)) {
        throw "Password is too weak";
    }
    this->password = password;
}

void User::setGender(int g) {
    if (g != 1 && g != 2) {
        throw "Wrong choice";
    }
    else if (g == 1)
        gender = "Male";
    else
        gender = "Female";
}

void User::setEmail(string email, System &currentSystem) {
    if (currentSystem.findUser(email) != -1)
        throw "Email already Exists";

    if (!validEmail(email))
        throw "Invalid Email";
    this->email = email;
}

void User::setName(string name) {
    if (!validName(name)) {
        throw "Invalid name";
    }
    this->name = name;
}

DateTime User::getBirthDate() {
    return birthDate;
}

string User::getPassword() {
    return password;
}

string User::getGender() {
    return gender;
}

string User::getEmail() {
    return email;
}

string User::getName() {
    return name;
}

int User::getID (){
	return ID;
}

void User::setID (int ID){
	this->ID = ID;
}

User* User::getFriend(int index) {
    return friends[index];
}

Post* User::getPost(int index){
	return posts [index];
}
Message &User::getReceivedMessage(int index) {
    if (!(0 <= index and index < receivedMessages.size()))
        throw "index out of boundary";

    return receivedMessages[index];
}

Message &User::getSentMessage(int index) {
    if (!(0 <= index and index < sentMessages.size()))
        throw "index out of boundary";

    return sentMessages[index];
}

Notifications *User::getNotifications() {
    return notifications;
}

//validation functions

bool User::validName(string name) {
    for (int i = 0, n = name.size(); i < n; i++)
        if (!isalpha(name[i]) && name[i] != ' ')
            return false;

    return name.size() != 0;
}

bool User::strongPassword(string P) {
    bool hasUpper = false, hasLower = 0, hasDigit = 0;
    for (int i = 0; i < P.size(); i++) {
        if (islower(P[i]))
            hasLower = true;
        else if (isupper(P[i]))
            hasUpper = true;
        else if (isdigit(P[i]))
            hasDigit = true;
    }
    return P.size() >= 8 && hasLower && hasUpper && hasDigit;
}

bool User::validEmail(string email) {
    int at = email.rfind('@');
    int com = email.rfind(".com");

    return at != -1 && com != -1 && (com - at) > 1 && email.find(' ') == -1;
}


User::~User() {

	for (int i = 0; i < friendsCount; i++)
	        friends[i]->removeFriend(this);

    delete[]friends;

   for (int i = 0; i < numberOfPosts; i++)
        delete posts[i];
    delete[]posts;
}

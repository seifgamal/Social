#include "Notifications.h"
#include "User.h"

Notifications::Notifications() {
    unreadMessagesCount = 0;
    friendRequestsCount = 0;
    acceptedRequestCount = 0;
    friendRequest = NULL;
    acceptedFriendRequest = NULL;
}

int Notifications::findFriendRequest(string email) {
    for (int i = 0; i < friendRequestsCount; i++)
        if (friendRequest[i]->getEmail() == email)
            return i;
    return -1;
}

int Notifications::getFriendRequestsCount() {
    return friendRequestsCount;
}
User *Notifications::getFriendRequest(int index) {
    if (!(0 <= index and index < friendRequestsCount))
        throw "Friend request out of boundary.";
    return friendRequest[index];
}
int Notifications::getAcceptedRequestCount() {
    return acceptedRequestCount;
}
User *Notifications::getAcceptedRequest(int index) {
    return acceptedFriendRequest[index];
}
int Notifications::getUnreadMessagesCount() {
    return unreadMessagesCount;
}

void Notifications::removeAcceptedRequests(int index) {
    if (!(0 <= index and index < acceptedRequestCount))
        throw "Accepted friend request out of boundary.";

    User **tmpFriendRequests = new User *[acceptedRequestCount - 1];
    for (int i = 0; i < acceptedRequestCount; i++) {
        if (i == index)
            continue;
        if (i > index)
            tmpFriendRequests[i - 1] = acceptedFriendRequest[i];
        else
            tmpFriendRequests[i] = acceptedFriendRequest[i];
    }
    delete[] acceptedFriendRequest;
    acceptedFriendRequest = tmpFriendRequests;
    acceptedRequestCount--;
}
void Notifications::acceptFriendRequest(int index) {
    if (!(0 <= index and index < friendRequestsCount))
        throw "Friend request out of boundary.";
    removeFriendRequest(index);
}
void Notifications::rejectFriendRequest(int index) {
    if (!(0 <= index and index < friendRequestsCount))
        throw "Friend request out of boundary.";
    removeFriendRequest(index);

}

void Notifications::receiveAcceptedFriend(User *aUser) {
    User ** tmpFriendRequests = new User *[acceptedRequestCount + 1];

    for (int i = 0; i < acceptedRequestCount; i++)
        tmpFriendRequests[i] = acceptedFriendRequest[i];

    delete[] acceptedFriendRequest;
    acceptedFriendRequest = tmpFriendRequests;
    acceptedFriendRequest[acceptedRequestCount] = aUser;
    acceptedRequestCount++;
}

void Notifications::removeFriendRequest(int index) {
    User **tmpFriendRequests = new User *[friendRequestsCount - 1];
    for (int i = 0; i < friendRequestsCount; i++) {
        if (i == index)
            continue;
        if (i > index)
            tmpFriendRequests[i - 1] = friendRequest[i];
        else
            tmpFriendRequests[i] = friendRequest[i];
    }
    delete[] friendRequest;
    friendRequest = tmpFriendRequests;
    friendRequestsCount--;
}

void Notifications::receiveFriendRequest(User *aUser) {
    User **tmpFriendRequests = new User *[friendRequestsCount + 1];

    for (int i = 0; i < friendRequestsCount; i++)
        tmpFriendRequests[i] = friendRequest[i];

    delete[] friendRequest;
    friendRequest = tmpFriendRequests;
    friendRequest[friendRequestsCount] = aUser;
    friendRequestsCount++;
}

void Notifications::receiveMessage() {
    unreadMessagesCount++;
}
void Notifications::clearUnreadMessages() {
    unreadMessagesCount = 0;
}
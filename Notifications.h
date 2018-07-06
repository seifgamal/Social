#ifndef SOCIAL_NOTIFICATIONS_H
#define SOCIAL_NOTIFICATIONS_H

#include <string>

class User;

class Notifications {
private:
    int friendRequestsCount;
    User **friendRequest;

    User **acceptedFriendRequest;
    int acceptedRequestCount;

    int unreadMessagesCount;

    void removeFriendRequest(int index);
public:
    Notifications();

    int findFriendRequest(std::string email);

    int getFriendRequestsCount();
    int getUnreadMessagesCount();
    int getAcceptedRequestCount();
    User *getAcceptedRequest(int index);
    User *getFriendRequest(int index);

    void removeAcceptedRequests(int index);

    void receiveFriendRequest(User *aUser);
    void receiveAcceptedFriend(User *aUser);
    void receiveMessage();

    void clearUnreadMessages();

    void rejectFriendRequest(int index);
    void acceptFriendRequest(int index);
};


#endif //SOCIAL_NOTIFICATIONS_H

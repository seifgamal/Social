#include "System.h"

System::System() : usersCount(0), users(NULL), loggedInUser(NULL) {

    // get data from file
}

User *System::getLoggedInUser() {
    return loggedInUser;
}

User *System::getUser(int index) {
    if (!(0 <= index && index < usersCount))
        throw "Out of boundary.";

    return users[index];
}

void System::mergeSort(User **arr, int N) {
    if (N < 2)
        return;
    int M = N / 2;
    mergeSort(arr, M);
    mergeSort(arr + M, N - M);

    User **tmp = new User *[N];
    int i = 0, j = M;
    for (int k = 0; k < N; ++k) {
        if (i == M)
            tmp[k] = arr[j++];
        else if (j == N)
            tmp[k] = arr[i++];
        else if (arr[i]->getEmail() <= arr[j]->getEmail())
            tmp[k] = arr[i++];
        else
            tmp[k] = arr[j++];
    }

    for (int k = 0; k < N; ++k)
        arr[k] = tmp[k];
    delete[] tmp;
}

int System::findUser(string email) {
    int lower = 0, upper = usersCount - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;

        if (users[mid]->getEmail() > email)
            upper = mid - 1;
        else if (users[mid]->getEmail() < email)
            lower = mid + 1;
        else
            return mid;
    }
    return -1;
}

vector <int> System:: suggestedFriends(User *rootUser){

	vector <int> suggested;

	int visited [usersCount];
	memset (visited, 0, sizeof visited);

	queue < User* > Q;

	Q.push (rootUser);

	visited [rootUser->getID()] = 1;

	while (!Q.empty()){

		User* p = Q.front();
		Q.pop();

		for (int i = 0; i < p->getFriendsCount(); i++){
			User *person = p->getFriend(i);
			if (!visited [person->getID()]){

				visited [person->getID()] = visited [p->getID()] + 1;

				if (visited [person->getID()] == 3)
					suggested.push_back (findUser(person->getEmail()));

				if (visited [person->getID()] == 2)
					Q.push(person);

			}
		}


	}

	return suggested;

}

int System::getUsersCount() {
    return usersCount;
}

void System::signUp(User *newUser) {

    User **newUsers = new User *[usersCount + 1];

    for (int i = 0; i < usersCount; i++)
        newUsers[i] = users[i];

    delete[] users;

    users = newUsers;

    users[usersCount++] = newUser;
    newUser->setID(usersCount);

    mergeSort(users, usersCount);

}

bool System::signIn(string email, string password) {
    int index = findUser(email);

    if (index == -1 || users[index]->getPassword() != password)
        return false;

    loggedInUser = users[index];
    return true;
}
bool System::isSignedIn() {
    return loggedInUser != NULL;
}
void System::signOut() {
    loggedInUser = NULL;
}

System::~System() {
    // call write on file function ..
    for (int i = 0; i < usersCount; i++)
        delete users[i];
    delete[]users;
}

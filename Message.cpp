#include "Message.h"
#include "User.h" // included in .cpp to avoid recursion

Message::Message(string text, User *sender) {
	this->text = text;
	this->sender = sender;
}

string Message::getMessage() {
	return "\nFrom " + sender->getName() + "\n" + text + "\n" + dateTime.timePassed() + " ago.";

}

User *Message::getSender() {
	return sender;
}
string Message::getText() {
	return text;
}
void Message::setDate(DateTime dateTime) {
	this->dateTime = dateTime;
}

DateTime Message::getDateTime() {
	return dateTime;
}

ostream &operator<<(ostream &out, Message &M) {
//	out << M.getMessage();

	out << "\nFrom " << M.sender->getName() << "\n" << M.text<< "\n" << M.dateTime.timePassed() << " ago.";


	return out;
}


#include "Status.h"

Status::Status() {

	choice = 0;
	text = "";

}

Status::Status(string text, int choice){

	this-> text = text;
	this->choice = choice;

}

void Status::viewFeelings(){

	for (int i = 0; i < size; i++)
		cout << feelings [i] << endl;

}

void Status::addFeeling (int idx){
	feeling += "Feeling " ;
	feeling += feelings [idx];
}

void Status::addStatus(string text){
	this->text = text;
	time = dateandtime.getDate();
	time += ' ' ;
	time += dateandtime.getTime();
}

void Status::view (){
	if (text.size())
		cout << text << endl;
	if (feeling.size())
		cout << feeling << endl;
	cout << time << endl;
}

Status::~Status() {
	// TODO Auto-generated destructor stub
}


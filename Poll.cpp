#include "Poll.h"

Poll::Poll() {

	answers = NULL;
	votes = NULL;
	numberOfAnswers= 0;
	voters = NULL;

}

void Poll::addQuestion(string Question){
	this->Question = Question;
	time = dateandtime.getDate();
	time += ' ';
	time += dateandtime.getTime();
}

void Poll:: addthisInt (int size, int *&p){

	int *tmp = new int [size+1];

	for (int i = 0; i < size; i++)
		tmp [i] = p[i];

	delete [] p;

	p = tmp;

}

void Poll:: removethisInt (int size, int idx, int *&p){

	int *tmp = new int [size-1];

	int j = 0;
	for (int i = 0; i < size; i++)
		if (i != idx){
			tmp [j] = p[i];
			++j;
		}


	delete [] p;

	p = tmp;


}

void Poll::addAnswers(string Answer){

	addCell(numberOfAnswers, *&answers);
	addCell (numberOfAnswers, *&votes);
	votes[numberOfAnswers] = 0;
	answers[numberOfAnswers] = Answer;
	++numberOfAnswers;
}

void Poll::upVote(string curUser, int idx){

	++votes[idx];

}

void Poll::downVote(string curUser, int idx){

	--votes[idx];

}

void Poll::removeAnswers(int idx){
	removeCell (numberOfAnswers, idx, *&answers);

	removethisInt (numberOfAnswers, idx, *&votes);
	--numberOfAnswers;

}

void Poll::view(){

	cout << Question << endl;

	for (int i = 0; i < numberOfAnswers; i++ )
		cout << answers[i] << ' '<< votes [i] << endl;
	cout << endl;
	cout << time;
}

Poll::~Poll() {

	delete [] answers;
	delete [] votes;
	delete [] voters;

}

/*
 * problems
 *
 * user might up vote and down vote many times
 * solution:
 * 2d dynamic array
 * each row represent answer number
 * each col represent the user who up voted
 *
 * note: user can't down vote an answer if he hasn't up voted it
 */

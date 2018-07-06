#include "Post.h"

Post::Post() {
	numberOfLikers = 0;
	numberOfDislikers = 0;
	numberOfComments = 0;
	comments = NULL;
	likers = NULL;
	dislikers = NULL;

}

void Post::like(string curUser){

	bool exist = 0;
	int idx;
	for (int i = 0; i < numberOfLikers; i++)
		if (likers[i] == curUser){
			exist = 1;
			break;
		}

	if (!exist){

		addCell (numberOfLikers, *&likers);

		likers [numberOfLikers] = curUser;

		++numberOfLikers;

	}

	exist = 0;
	for (int i = 0; i < numberOfDislikers; i++)
		if (dislikers[i] == curUser){
			idx = i;
			exist = 1;
			break;
		}

	if (exist){
		removeCell (numberOfDislikers, idx,*&dislikers );
		--numberOfDislikers;
	}


}

void Post::dislike(string curUser){

	bool exist = 0;
	int idx;

	for (int i = 0; i < numberOfDislikers; i++)
		if (dislikers[i] == curUser){
			exist = 1;
			break;
		}

	if (!exist){
		addCell (numberOfDislikers, *&dislikers);
		dislikers[numberOfDislikers] = curUser;
		++numberOfDislikers;
	}

	exist = 0;

	for (int i = 0; i < numberOfLikers; i++)
		if (likers[i] == curUser){
			exist = 1;
			idx = i;
			break;
		}

	if (exist){
		removeCell (numberOfLikers, idx, *&likers);
		--numberOfLikers;
	}

}

void Post::addcomment(string Comment){

	Comment += '\n';
	Comment += dateandtime.getDate();
	addCell (numberOfComments, *&comments);
	comments [numberOfComments] = Comment;
	++numberOfComments;

}

void Post::deleteComment (int idx){
	cout << numberOfComments << ' ' << idx <<  endl;
	removeCell (numberOfComments, idx, *&comments);
	--numberOfComments;

}

string Post::viewComment(int index){
	return comments[index];
}

int Post::getNumberofComment(){
	return numberOfComments;
}

int Post::getNumberofDislikers(){
	return numberOfDislikers;
}

int Post::getNumberofLikers(){
	return numberOfLikers;
}


Post::~Post() {

	delete [] comments;
	delete [] likers;
	delete [] dislikers;


}


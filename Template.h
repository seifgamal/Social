/*
 * Template.h
 *
 *  Created on: Dec 30, 2015
 *      Author: maryam
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include <bits/stdc++.h>

using namespace std;

template <class T1>

void addCell (int size, T1*& Tp){

	T1 *tmp = new T1 [size+1];

		for (int i = 0; i < size; i++)
			tmp [i] = Tp[i];

		delete [] Tp;

		Tp = tmp;

}

template <class T2>

void removeCell (int size, int idx, T2 *& Tp){

	T2 *tmp = new T2 [size-1];

		int j = 0;
		for (int i = 0; i < size; i++)
			if (i != idx){
				tmp [j] = Tp[i];
				++j;
			}


		delete [] Tp;

		Tp = tmp;

}






#endif /* TEMPLATE_H_ */

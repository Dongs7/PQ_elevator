

#ifndef _PriorityQueue_
#define _PriorityQueue_

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "Request.h"
using namespace std;


template <class T>
class PriorityQueue
{
public:
	//Default constructor
	PriorityQueue();

	//Copy Constructor
	PriorityQueue(const PriorityQueue &);

	//overload operator
	PriorityQueue & operator=(const PriorityQueue &);

	//Destructor
	~PriorityQueue();

	//Insert value in Priority Queue
	void insert(T);

	//Remove value from Priority Queue
	T remove();
	
	// Return value which is the highest priority
	T peek() const;

	//Check whether Priority queue is empty or not
	bool empty() const;

	//Check whether heap properties are satisfied
	bool properties() const;

	//Return number of values stored in Prioirity Queue
	int length() const;
	
private:
	// 
	void copyPQ(const PriorityQueue & );
	int top;
	
	//Return left and right child index
	int leftChildIndex(int);
	int rightChildIndex(int);
	
	int size;
	T *arr;

	//Bubble up
	void bup(int);
	
	//Bubble down
	void bdown(int);

	//Swap two values
	void swap(int,int);

};

#include "PriorityQueue.cpp"

#endif

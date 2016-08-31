// CMPT 225 FALL 2013 301008631 DONG-HYUN CHUNG
// Assignment #3

#ifdef _PriorityQueue_

#include "PriorityQueue.h"

// Default constructor to create empty priority queue with size 4
template <class T>
PriorityQueue<T>::PriorityQueue()
{
	size=4;
	arr = new T[size];
	top =0;
}

//Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	delete [] arr;
}

//Copy constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue & pq)
{
	copyPQ(pq);
}

//Overloaded operator
//Only copy the queue if it is a different object
//Code from J.Edgar from CMPT 225 class
template <class T>
PriorityQueue<T> & PriorityQueue<T>::operator=(const PriorityQueue & pq)
{
	if(this != &pq)
	{
		delete[] arr;
		copyPQ(pq);
	}
	return  *this;
}

//Insert value x into the Priority queue
//If queue is full, then double the size and insert values.
template <class T>
void PriorityQueue<T>::insert(T x)
{
	if(top == size)
	{
		//double the size
		size = 2 * size;
		T *temp = arr;
		arr = new T[size];
		//copy original values into the double sized priority queue
		for(int i =0; i<top; i++)
			arr[i] = temp[i];
		delete [] temp;
	}
	
	arr[top] = x;

	//if top is bigger than 0, then do bubble up
	//in order to maintain min heap property
	if (top>0)
		bup(top);

	//increment top
	top++;
}

//Return left child index (parent index * 2) + 1
template <class T>
int PriorityQueue<T>::leftChildIndex(int x)
{
	return (2*x)+1;
}

//Return right child index (parent index * 2) + 2
template <class T>
int PriorityQueue<T>::rightChildIndex(int x)
{
	
	return (2*x)+2;
}

//return highest priority value. Throw runtime error if Priority queue is empty
template <class T>
T PriorityQueue<T>::peek() const
{
	if(top == 0)
		throw runtime_error("Priority Queue is Empty");
	else
		return arr[0];
}

//Remove value from priority queue
//Throw runtime error if Priority queue is empty
template <class T>
T PriorityQueue<T>::remove()
{
	if(top == 0)
		throw runtime_error("Priority Queue is Empty");
	
		//copy root value to variable tmp
		T tmp = arr[0];
		
		//swap between root value and last indexed value
		arr[0] = arr[top-1];

		//decrement top
		top--;

		//if top is bigger than 0, then bubble down 
		//in order to maintain heap property
		if (top >0)
			bdown(0);
		
		return tmp;
}

//Code from J.Edgar from CMPT 225 class
template <class T>
void PriorityQueue<T>::copyPQ(const PriorityQueue & pq)
{
	top = pq.top;
	size = pq.size;
	arr = new T[size];
	for (int i=0; i < top; i++)
		arr[i] = pq.arr[i];
}

//Return true when Priority Queue is empty, false otherwise.
template <class T>
bool PriorityQueue<T>::empty() const
{
	if (top == 0)
		return true;
	else
		return false;
}

//Bubble up
//Since this is min heap, lower value has more priority.
//if inserted value has more priority than its parents' value,
//then swap those values and execute this process recursively.
template <class T>
void PriorityQueue<T>::bup(int x)
{
	int parent = (x-1)/2;
	if(x >0 && arr[parent] > arr[x])
	{
		swap(parent,x);
		bup(parent);
	}
	
}

//Bubble down
//If highest priority value removes from priority queue,
//we need to do some work in order to maintain heap property.
template <class T>
void PriorityQueue<T>::bdown(int x)
{
	int leftCindex = leftChildIndex(x);
	int rightCindex = rightChildIndex(x);
	int minIndex;

	//if right and left child is greater than the number of values stored in queue
	//return nothing
	if (rightCindex >= top)
	{
		if (leftCindex>=top)
			return;
		//otherwise, set minimumindex to leftchild index 
		else
			minIndex = leftCindex;
	}
	else
	{
		//if left child is smaller than right child
		if(arr[leftCindex] <= arr[rightCindex])
			// left child index will be minimum index
			minIndex = leftCindex;
			//otherwise, right child index will be.
		else
			minIndex = rightCindex;
	}
	
	//if root value is bigger than its smallest child value,
	//then, swap the value and do this process recursively.
	if(arr[x]>arr[minIndex])
	{
		swap(minIndex,x);
		x = minIndex;
		bdown(x);
	}

}

//Swap
template <class T>
void PriorityQueue<T>::swap( int x, int y)
{
		T tmp;
		tmp = arr[x];
		arr[x] = arr[y];
		arr[y]=tmp;
}

//Code from J.Edgar from CMPT 225 class
template <class T>
bool PriorityQueue<T>::properties() const
{
	for(int i=length()-1; i > 0; i--){
            if(arr[i] < arr[(i-1)/2]) return false;
      }
      return true;
}


//Return length
template <class T>
int PriorityQueue<T>::length() const
{
	return top;
}
#endif
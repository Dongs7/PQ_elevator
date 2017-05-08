

#include "PriorityQueue.h"

//Elevator method
void elevator(string infile,int x)
{
	// Priority queues that store elevator requests (objects of class Request)
	PriorityQueue<Request> up;
	PriorityQueue<Request> down;

	try
	{
		ifstream ist(infile.c_str());
		if(ist.fail()) throw runtime_error("File not found");
		
		//boolean variable to set true 
		bool check = true;
		
		//variable to store the value from text file
		int ReqFloor;
		
		// set initial distance to 0
		int distance=0;

		//variable to store total distance that elevator travelled 
		int distanceT=0;

		//variable to store previous floor information
		int prevF = 0;

		//variable to store current floor information
		int currentF = 0;

		
		//store value from text file
		ist >> ReqFloor;

		//if that value is 0, then insert the value into the UP priority queue
		if(ReqFloor == 0)
		{
			up.insert(Request(ReqFloor,x,check));
			cout << "going up" << endl;
		}
		//Else,
		else
		{
			//if the value is satisfied the condition, insert the value into the UP priority queue
			//Since elevator starts from ground floor(which is 0), print 0 first.
			if((currentF < ReqFloor) && (currentF != ReqFloor))
			{
				up.insert(Request(ReqFloor,x,check));
				cout << "going up" << endl;
			    cout << currentF << endl;
			}
		}

		//Execute code below first and then check the condition
		//if condition(up or down priority queue is not empty) satisfies, 
		//process loop until the condition fails.
		do
		{
			while(!up.empty())
			{
				//If it is not end of file, then
				if(!ist.eof())
				{
					ist >> ReqFloor;
					//if current floor is lower than requested floor, and if they are not the same then
					if((currentF < ReqFloor) && (currentF != ReqFloor))
						//store value into UP priority queue
						up.insert(Request(ReqFloor,x,check));

					//if current floor is higher than request floor
					//and request floor is not -1 and current
					//and requested floor is not the same, then 
					else if((currentF > ReqFloor) && (ReqFloor != -1) && (ReqFloor != currentF))
						//store value into DOWN priority queue
						down.insert(Request(ReqFloor,x,!check));
				}

				//when Request floor hits -1, 
				if(ReqFloor == -1)
				{
					//store current floor information to prevF variable
					prevF = currentF;
					//set new current floor information 
					currentF = up.peek().floor();
					
					//Calculate distance
					distance = abs(prevF - currentF);
					distanceT += distance;
					
					//remove requested floor from priority queue
					cout << up.remove().floor() << endl;

					//if UP priority queue is empty and DOWN priority queue is not empty, then
					if(up.empty() && !down.empty())
						cout << "going down"<<endl;
				}
			}
			
			while(!down.empty())
			{
				if(!ist.eof())
				{
					ist >> ReqFloor;
					if((currentF < ReqFloor) && (currentF != ReqFloor))
						up.insert(Request(ReqFloor,x,check));
					else if((currentF > ReqFloor) && (ReqFloor != -1) && (ReqFloor != currentF))
						down.insert(Request(ReqFloor,x,!check));
				}

				if(ReqFloor == -1)
				{
					prevF = currentF;
					currentF = down.peek().floor();
					distance = abs(prevF - currentF);
					distanceT += distance;
					cout << down.remove().floor() << endl;
					//if DOWN priority queue is empty and UP priority queue is not empty, then
					if(down.empty() && !up.empty())
						cout << "going up"<<endl;
				}
			}
			
		}while(!up.empty() || !down.empty()); // do-while loop condition

		cout << endl;
		cout << "Total distance : " << distanceT << endl;
		cout << endl;
		ist.close();

	//print runtime error if file is not found
	}catch(runtime_error re)
	{
		cout << re.what() << endl;
	}
}



void part2()
{
       cout << "INTEGER TEST" << endl;
       PriorityQueue<int> pq1;
      
       try{
              pq1.peek();
       }catch(runtime_error re){
              cout << re.what();
              cout << " -- empty -- (peek error) 01" << endl;
       }
 
       int arr1[] = {99,32,11,12};
       for(int i=0; i < sizeof(arr1)/sizeof(int); ++i){
              pq1.insert(arr1[i]);
       }
       cout << pq1.peek() <<  " -- 11 -- (peek)" << endl;
       cout << pq1.properties() <<  " -- 1 -- (properties - insert)" << endl;
       cout << pq1.length() <<  " -- 4 -- (length) 04" << endl;
       cout << pq1.empty() << " -- 0 -- (empty)" << endl;
       while(!pq1.empty()){
              cout << pq1.remove() << " ";
       }
       cout << "-- 11 12 32 99 -- (insert, remove)" << endl;
       cout << pq1.empty() << " -- 1 -- (empty)" << endl;
       try{
              pq1.remove();
       }catch(runtime_error re){
              cout << re.what();
              cout << " -- empty -- (remove error)" << endl;
       }
 
       int arr2[] = {37,91,13,54,42,32,63,55,99,72,18,33};
       for(int i=0; i < sizeof(arr2)/sizeof(int); ++i){
              pq1.insert(arr2[i]);
       }
 
       cout << pq1.properties() <<  " -- 1 -- (insert-properties)" << endl;
       cout << pq1.length() <<  " -- 12 -- (insert-length)" << endl;
      
       PriorityQueue<int> pq2(pq1);
      
       pq1.remove();
       cout << pq1.properties() <<  " -- 1 -- (remove-properties)" << endl;
       while(!pq1.empty()){
              pq1.remove();
       }
       cout << pq1.length() <<  " -- 0 -- (remove-length)" << endl;
 
       cout << pq2.peek() <<  " -- 13 -- (copy)" << endl;
       PriorityQueue<int> pq3;
 
       for(int i=0; i < 8; i++){
              pq3.insert(pq2.remove());
       }
 
       pq3 = pq2;
       pq2.insert(21);
       while(!pq2.empty()){
              cout << pq2.remove() << " ";
       }
       cout << "-- 21 63 72 91 99 -- (copy)" << endl;
 
       cout << pq3.remove() << " -- 63 -- (assign)" << endl;
       pq3.insert(21);
       pq3 = pq3;
       cout << pq3.remove() << " -- 21 -- (self assign) 14" << endl;
}

void part3(){
      cout << endl << "STRING TEST" << endl;
      PriorityQueue<string> pq1;
      string arr1[] = {"ape","cat","dog","ant","bat"};
      int n = 5;
      for(int i=0; i < n; ++i){
            pq1.insert(arr1[i]);
      }
      cout << pq1.properties() <<  " -- 1 -- (properties - insert)" << endl;
      pq1.remove();
      cout << pq1.properties() <<  " -- 1 -- (properties - remove)" << endl;
      while(!pq1.empty()){
            cout << pq1.remove() << " ";
      }
      cout << "-- ape bat cat dog -- (insert, remove)" << endl;
}

void part4(){
      cout << endl << "REQUEST TEST" << endl;
      Request rq1;
      Request rq2(3, 10, true);
      Request rq3(3, 10, false);
 
      cout << (rq2 == rq3) << " -- 0 -- (==)" << endl;
      cout << (rq2 != rq3) << " -- 1 -- (!=)" << endl;
      cout << (rq2 > rq3) << " -- 0 -- (>)" << endl;
      cout << (rq2 < rq3) << " -- 1 -- (<)" << endl;
      cout << (rq2 >= rq3) << " -- 0 -- (>=)" << endl;
      cout << (rq2 <= rq2) << " -- 1 -- (<=)" << endl;
}

void part5(){
     elevator("lift1.txt", 10);
     //elevator("lift2.txt", 10);
	 //elevator("lift3.txt", 20);
     //elevator("lift4.txt", 20);
}

int main()
{
	part2();
	part3();
	part4();
	part5();
	return 0;
};

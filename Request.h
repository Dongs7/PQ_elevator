// CMPT 225 FALL 2013 301008631 DONG-HYUN CHUNG
// Assignment #3

#include <iostream>

using namespace std;

// Request class
class Request 
{
	public:

	//Default constructor
	Request();															
	Request(int,int,bool);											
	int floor();

	//overload comparison operator
	bool  operator==(const Request &) const;
	bool  operator!=(const Request &) const;
	bool  operator>(const Request &) const;
	bool  operator<(const Request &) const;
	bool  operator>=(const Request &) const;
	bool  operator<=(const Request &) const;
private:

	int m_priority;
	int m_floor;
	int highF;
};

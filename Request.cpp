

#include "Request.h"

Request::Request()
{
	m_floor = 0;     // requested floor
	m_priority = 0; // current floor
}


Request::Request(int x,int y, bool z)
{
	m_floor = x;
	highF   = y;
	
	
	if(z == true) // if current floor is lower than req floor
		m_priority = m_floor;
	if(z == false) // vice versa
		m_priority = highF - m_floor;
}

int Request::floor()
{
	return m_floor;
}

//Overload comparison operator (==)
bool Request::operator==(const Request &rq ) const
{
	return m_priority == rq.m_priority;
}

//Overload comparison operator (!=)
bool Request::operator!=(const Request &rq ) const
{
	return m_priority != rq.m_priority;
}

//Overload comparison operator (>)
bool Request::operator>(const Request &rq ) const
{
	return m_priority > rq.m_priority;
}

//Overload comparison operator (<)
bool Request::operator<(const Request &rq ) const
{
	return m_priority < rq.m_priority;
}

//Overload comparison operator (>=)
bool Request::operator>=(const Request &rq ) const
{
	return m_priority >= rq.m_priority;
}

//Overload comparison operator (<=)
bool Request::operator<=(const Request &rq ) const
{
	return m_priority <= rq.m_priority;
}

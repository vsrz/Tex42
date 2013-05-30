
#ifndef UTILS_H
#define UTILS_H
#pragma once

#include <sstream>
#include <string>
#include <iostream>

template <class T> std::string toString( const T &t )
{
	std::ostringstream oss;
	oss << t;
	return std::string( oss.str() );

}

#endif

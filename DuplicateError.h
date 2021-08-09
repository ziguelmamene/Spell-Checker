#ifndef DUPLICATEERROR_H
#define DUPLICATEERROR_H

#include <stdexcept>
using namespace std;

template<typename T>
class DuplicateError :public logic_error {
public:
	DuplicateError(T err):logic_error("Duplicate Mystring: " + err) {
		
	}

};

#endif
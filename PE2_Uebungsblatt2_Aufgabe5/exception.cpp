/**
 * @file exception.cpp
 * @brief Exception-Handler
 */

#include "Exception.h"

using namespace std;

Exception::Exception(string error) {
	_error = error;
}

string Exception::toString() {
	return _error;
}
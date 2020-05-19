//
// Created by joshg on 19.05.2020.
//

#include "Exception.h"

using namespace std;

Exception::Exception(string error) {
	_error = error;
}

string Exception::toString() {
	return _error;
}
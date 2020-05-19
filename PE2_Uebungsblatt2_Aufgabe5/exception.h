#pragma once
/**
 * @file Exception.h
 * @brief Exception-Handler
 */

#ifndef PE2_HEAP_CPP_EXCEPTION_H
#define PE2_HEAP_CPP_EXCEPTION_H

#include <string>

class Exception {
private:
	std::string _error;

public:
	Exception(std::string error);
	std::string toString();
};

#endif //PE2_HEAP_CPP_EXCEPTION_H

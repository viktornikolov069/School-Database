#ifndef ECHO_H
#define ECHO_H
#include <string>
#include <iostream>

inline void echo(const std::string& text) { // I don't know if inlining this function is correct
									        // but otherwise the linker complained about function 
	std::cout << text << std::endl;		    // redefenition and this fixed it :D
	
}

#endif // !ECHO_H

#ifndef SNOOKER_H
#define SNOOKER_H

#include <string>
#include <python3.8/Python.h>

class snooker{
public:
	snooker();
	~snooker();
	std::string getItemFromJSON(std::string data, const char* item);
	std::string getDataFromAPI(const char* url);
	double *getASTFromMatch(const char* url);
private:


};


#endif

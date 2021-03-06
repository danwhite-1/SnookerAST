#ifndef SNOOKER_H
#define SNOOKER_H

#include <string>
#include <python3.8/Python.h>

class snookerUtils{
public:
	snookerUtils();
	~snookerUtils();
	static std::string getItemFromJSON(std::string data, const char* item);
	static std::string getDataFromAPI(const char* url);
private:
};


#endif

#ifndef SNOOKER_H
#define SNOOKER_H

#include <string>

class snooker{
public:
	snooker();
	~snooker();
	std::string getItemFromJSON(const char* data, const char* item);
	std::string getDataFromAPI(const char* url);
private:


};


#endif

#ifndef SNOOKERMATCH_H
#define SNOOKERMATCH_H

#include <string>
#include </home/daniel/SnookerAST/include/snookerUtils.h>
#include <python3.8/Python.h>

class snookerMatch
{
	public:
	snookerMatch();
	snookerMatch(std::string url);
	~snookerMatch();
	void initMatchInfo(std::string url);
	std::string outputAllData();
	double getASTFromMatch(const char* url, PLAYER player);
	
	private:
	std::string url;
	std::string player1ID, player2ID;
	std::string player1Score, player2Score; //Declared as string to reduce risk of type error
    double player1AST, player2AST;
	std::string eventID;
	std::string wstID;
};
#endif

#ifndef SNOOKERMATCH_H
#define SNOOKERMATCH_H

#include <string>
#include </home/daniel/SnookerAST/snookerUtils.h>
#include <python3.8/Python.h>

class snookerMatch
{
public:
	snookerMatch();
	~snookerMatch();
	double getASTFromMatch(const char* url, int player);
private:
	int player1ID;
	int player2ID;
	int Player1Score;
	int player2Score;
    double player1AST, player2AST;
	int eventID;
	int wstID;
};


#endif
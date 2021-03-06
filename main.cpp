#include </home/daniel/SnookerAST/snookerUtils.h>
#include </home/daniel/SnookerAST/snookerMatch.h>
#include <iostream>

int main(){
    
	Py_Initialize();

	//std::string tournamentData = snookerUtils::getDataFromAPI("http://api.snooker.org/?e=398");
	//std::string tournamentName = snookerUtils::getItemFromJSON(tournamentData, "Name");

	//std::cout << "Tournament Name: " << tournamentName << std::endl;

	snookerMatch sMatch;
	std::cout << "Got this far 0\n";
	
	double player1_ast = sMatch.getASTFromMatch("https://livescores.worldsnookerdata.com/Matches/Result/14156/765410/betvictor-european-masters-2020", 1);
	double player2_ast = sMatch.getASTFromMatch("https://livescores.worldsnookerdata.com/Matches/Result/14156/765410/betvictor-european-masters-2020", 2);

	std::cout << "Player 1 AST: " << player1_ast << "\nPlayer 2 AST: " << player2_ast << std::endl;

	Py_Finalize();
	
	return 0;
}
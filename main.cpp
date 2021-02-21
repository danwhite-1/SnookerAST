#include </home/daniel/SnookerAST/snooker.h>
#include <iostream>

int main(){
    
	Py_Initialize();

    snooker s;
	std::string tournamentData = s.getDataFromAPI("http://api.snooker.org/?e=398");
	std::string tournamentName = s.getItemFromJSON(tournamentData, "Name");
	//double* matchAST = s.getASTFromMatch("https://livescores.worldsnookerdata.com/Matches/Result/14156/765410/betvictor-european-masters-2020");

	std::cout << "Tournament name: " << tournamentName << std::endl;
	
	//std::cout << "Player 1 AST: " << matchAST[0] << "\t Player 2 AST: " << matchAST[1] << std::endl;

	Py_Finalize();
	
	return 0;
}
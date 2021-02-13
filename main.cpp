#include </home/daniel/Documents/snookerAST/snooker.h>
#include <iostream>

int main(){

	snooker s;
	std::string tournamentData = s.getDataFromAPI("http://api.snooker.org/?e=398");
	std::string tournamentName = s.getItemFromJSON(tournamentData, "Name");

	std::cout << "Tournament name: " << tournamentName << std::endl;

	return 0;
}

#include </home/daniel/SnookerAST/snooker.h>
#include <iostream>

int main(){
    Py_Initialize();

    snooker s;
	std::string tournamentData = s.getDataFromAPI("http://api.snooker.org/?e=398");
	std::string tournamentName = s.getItemFromJSON(tournamentData, "Name");

	std::cout << "Tournament name: " << tournamentName << std::endl;

	Py_Finalize();
	return 0;
}

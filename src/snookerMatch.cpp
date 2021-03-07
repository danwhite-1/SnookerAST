#include </home/daniel/SnookerAST/include/snookerMatch.h>
#include <iostream>

snookerMatch::snookerMatch()
{
    //constructor - this needs to do something
}

snookerMatch::~snookerMatch()
{
    //Destructor - needs to do something.
}

snookerMatch::snookerMatch(std::string url)
{
    initMatchInfo(url);
	//These need a different URL - should be contructed from wstID and eventID *crosses fingers*
	//URL = http://livescores.worldsnookerdata.com/Matches/Result/<Event::wstID>/<Match::wstID> Need to create snookerEvent to store Event::wstID
	std::string wst_url = "https://livescores.worldsnookerdata.com/Matches/Result/14164/815777"; //https is important here
	getASTFromMatch(wst_url.c_str(), PLAYER::ONE); //This can be improved, need to not call API twice
	getASTFromMatch(wst_url.c_str(), PLAYER::TWO);
}

void snookerMatch::initMatchInfo(std::string url)
{
	std::string match_info = snookerUtils::getDataFromAPI(url.c_str());
	player1ID = snookerUtils::getItemFromJSON(match_info, "Player1ID");
	player2ID = snookerUtils::getItemFromJSON(match_info, "Player2ID");
	player1Score = snookerUtils::getItemFromJSON(match_info, "Score1");
	player2Score = snookerUtils::getItemFromJSON(match_info, "Score2");
	eventID  = snookerUtils::getItemFromJSON(match_info, "EventID");
	wstID = snookerUtils::getItemFromJSON(match_info, "WorldSnookerID");
}

std::string snookerMatch::outputAllData()
{
	return "player1ID: " + player1ID + 
	       "\nPlayer2ID: " + player2ID +
		   "\nPlayer1Score: " + player1Score +
		   "\nPlayer2Score: " + player2Score +
		   "\nPlayer1AST: " + std::to_string(player1AST) +
		   "\nPlayer2AST: " + std::to_string(player2AST) +
		   "\nEventID: " + eventID +
		   "\nwstID: " + wstID + 
		   "\n";
}

double snookerMatch::getASTFromMatch(const char* url, PLAYER player)
{	
	PyObject *pName, *pModule, *pValue;
	
	//In order for import to work $PYTHONPATH = directory of snooker.py file
	pName = PyUnicode_FromString("snooker");
	pModule = PyImport_Import(pName);

	if ( pModule )
	{
		PyObject* pFunc = PyObject_GetAttrString(pModule, "getASTFromMatch");
		if ( pFunc && PyCallable_Check(pFunc) )
		{
			PyObject* tup = PyTuple_New(1);
			PyObject* py_url = PyUnicode_FromString(url);
			PyTuple_SetItem(tup, 0, py_url);
			pValue = PyObject_CallObject(pFunc, tup);
			std::string cValue = PyUnicode_AsUTF8(pValue);

			int colon_pos = cValue.find(':');
			double ast_p1 = stof(cValue.substr(0, colon_pos));
			double ast_p2 = stof(cValue.substr(colon_pos+1));
			double cValue_ret[2] = {ast_p1, ast_p2};
			
			//std::cout << "cValue[0] = " << cValue_ret[0] << std::endl;
			//std::cout << "cValue[1] = " << cValue_ret[1] << std::endl;
			
			if(player == ONE){
                player1AST = ast_p1;
				return ast_p1;
			}
			else
			{
                player2AST = ast_p2;
				return ast_p2;
			}
		}
		else
		{
			std::cout << "Something gone wrong";
			PyErr_PrintEx(0);
		}
	}
	else
	{
		std::cout << "Something else went wrong";
		PyErr_PrintEx(0);
	}
	
	PyErr_PrintEx(0);
}

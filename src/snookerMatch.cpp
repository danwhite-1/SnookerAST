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

double snookerMatch::getASTFromMatch(const char* url, int player)
{
    if( player != 1 && player != 2){
		return -1;
	}
	
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
			
			if(player == 1){
                player1AST = ast_p1;
				return ast_p1;
			}
			else
			{
                player2AST = ast_p2;
				return ast_p2;
			}
			//return cValue;
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

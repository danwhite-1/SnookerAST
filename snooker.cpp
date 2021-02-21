#include </home/daniel/SnookerAST/snooker.h>
#include <iostream>

snooker::snooker()
{
	//Constructor -- turn into namespace??
}

snooker::~snooker()
{
	//Destructor	
}


std::string snooker::getItemFromJSON(std::string _data, const char* item)
{
	const char* data = _data.c_str();

	PyObject *pName, *pModule, *pValue;	

	pName = PyUnicode_FromString("snooker");
	pModule = PyImport_Import(pName);

	if ( pModule )
	{
		PyObject* pFunc = PyObject_GetAttrString(pModule, "getItemFromJSON");
		if ( pFunc && PyCallable_Check(pFunc) )
		{
			PyObject* tup = PyTuple_New(2);	
			PyTuple_SetItem(tup, 0, PyUnicode_FromString(data));
			PyTuple_SetItem(tup, 1, PyUnicode_FromString(item));
			pValue = PyObject_CallObject(pFunc, tup);
			std::string cValue = PyUnicode_AsUTF8(pValue);
			Py_Finalize();
			return cValue.c_str();
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

	return "Well, Shit";
}

std::string snooker::getDataFromAPI(const char* url)
{
	PyObject *pName, *pModule, *pValue;	

	//In order for import to work $PYTHONPATH = directory of file you want
	pName = PyUnicode_FromString("snooker");
	pModule = PyImport_Import(pName);

	if ( pModule )
	{
		PyObject* pFunc = PyObject_GetAttrString(pModule, "getRequest");
		if ( pFunc && PyCallable_Check(pFunc) )
		{
			PyObject* tup = PyTuple_New(1);
			PyObject* py_url = PyUnicode_FromString(url);
			PyTuple_SetItem(tup, 0, py_url);
			pValue = PyObject_CallObject(pFunc, tup);
			std::string cValue = PyUnicode_AsUTF8(pValue);
			cValue = cValue.substr(1,cValue.length() - 2);
			return cValue;
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

	return "Well, shit";
}

double *snooker::getASTFromMatch(const char* url)
{
	std::cout << "Got this far -1";
	PyObject *pName, *pModule, *pValue;
	
	//In order for import to work $PYTHONPATH = directory of snooker.py file
	pName = PyUnicode_FromString("snooker");
	pModule = PyImport_Import(pName);

	std::cout << "Got this far 0";

	if ( pModule )
	{
		std::cout << "Got this far 1";
		PyObject* pFunc = PyObject_GetAttrString(pModule, "getASTFromMatch");
		std::cout << "Got this far 2";
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
			
			std::cout << "cValue[0] = " << cValue_ret[0] << std::endl;
			std::cout << "cValue[1] = " << cValue_ret[1] << std::endl;

			return cValue_ret;
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


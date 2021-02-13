#include </home/daniel/Documents/snookerAST/snooker.h>
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
	Py_Initialize();

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
	Py_Finalize();

	return "Well, Shit";
}

std::string snooker::getDataFromAPI(const char* url)
{
	//std::string url = "http://api.snooker.org/?e=398";
	Py_Initialize();

	PyObject *pName, *pModule, *pValue;	

	//In order for import to work $PYTHONPATH = directory of file you want
	//Pass in "snooker" as argv[1] when executing
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
			Py_Finalize();
			//std::cout << cValue.c_str();
			//return "Hello";
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
	Py_Finalize();

	return "Well, shit";
}

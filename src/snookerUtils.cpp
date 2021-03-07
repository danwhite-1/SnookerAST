#include </home/daniel/SnookerAST/include/snookerUtils.h>
#include <iostream>

snookerUtils::snookerUtils()
{
	//Constructor -- turn into namespace??
}

snookerUtils::~snookerUtils()
{
	//Destructor	
}


std::string snookerUtils::getItemFromJSON(std::string _data, const char* item)
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

std::string snookerUtils::getDataFromAPI(const char* url)
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

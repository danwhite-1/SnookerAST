#include <iostream>
//#include <python3.6m/pyhelper.hpp>
#include <python3.6m/Python.h>

int main()
{
	Py_Initialize();

	PyObject *pName, *pModule;	

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
			PyTuple_SetItem(tup, 0, PyUnicode_FromString("url"));
			PyObject* pValue = PyObject_CallObject(pFunc, tup);
			std::cout << "getRequest = " << PyUnicode_AsUTF8(pValue) << std::endl;
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

	std::cout << std::endl;

	return 0;
}

#include <Python.h>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Py_Initialize();
    FILE* file;
//    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    wchar_t* _argv[argc];
    for(int i=0; i<argc; i++){
        printf(argv[i]);
        printf("\n");
        wchar_t *arg = Py_DecodeLocale(argv[i], NULL);
        _argv[i] = arg;
    }

//    Py_SetProgramName(program);

    PySys_SetArgv(argc, _argv);
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("./test.py"));

    file = fopen("test.py","r");
    PyRun_SimpleFile(file, "test");
    Py_Finalize();
    return 0;
}

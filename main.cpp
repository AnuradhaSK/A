#include <Python.h>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout<<"start"<<endl;
    Py_Initialize();
    FILE* file;
//    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    wchar_t* _argv[argc];
    for(int i=0; i<argc; i++){
//        printf(argv[i]);
//        printf("\n");
        wchar_t *arg = Py_DecodeLocale(argv[i], NULL);
        _argv[i] = arg;
    }

//    Py_SetProgramName(program);

    PySys_SetArgv(argc, _argv);
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");

    //uncomment below to run graphsage code
//    PyList_Append(path, PyUnicode_FromString("./GraphSAGE/graphsage/"));
//    file = fopen("./GraphSAGE/graphsage/supervised_train.py","r");
//    PyRun_SimpleFile(file, "./GraphSAGE/graphsage/supervised_train.py");.


    PyList_Append(path, PyUnicode_FromString("."));
    file = fopen("./test.py","r");
    PyRun_SimpleFile(file, "./test.py");
    fclose(file);
    Py_Finalize();
    cout<<"Done"<<endl;
//    return 0;
}

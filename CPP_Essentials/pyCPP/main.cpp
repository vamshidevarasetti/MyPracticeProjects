#include <Python.h>
#include <iostream>
using namespace std;

int main() {
    Py_Initialize();

    // Add current directory (or custom path) to sys.path
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");  
    // Or give full path: sys.path.append("/home/you/projects/")

    PyObject* pName = PyUnicode_DecodeFSDefault("mymath");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "add");
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* args = PyTuple_Pack(2, PyLong_FromLong(5), PyLong_FromLong(7));
            PyObject* result = PyObject_CallObject(pFunc, args);
            Py_DECREF(args);

            if (result != nullptr) {
                cout << "Result of add(5,7) = " << PyLong_AsLong(result) << endl;
                Py_DECREF(result);
            } else {
                PyErr_Print();
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        cerr << "Failed to load mymath.py" << endl;
    }

    Py_Finalize();
    return 0;
}

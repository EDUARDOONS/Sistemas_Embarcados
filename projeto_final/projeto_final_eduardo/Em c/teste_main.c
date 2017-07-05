/*
  file: teste_main.c
*/
#include <stdio.h>
#include <python2.7/Python.h>

int main(){

    

    
    FILE *python;
    

    Py_Initialize();
    
   
    python = fopen("codigo_camera.py", "r");
    PyRun_SimpleFile(python, "codigo_camera.py");

    Py_Finalize();


    return 0;
}
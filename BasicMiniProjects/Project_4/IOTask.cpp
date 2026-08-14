#include "IOTask.h"
#include <fstream>
#include <string>
#include <iostream>

void IOTask::execute()
{
    std::ofstream archivoSalida("datos.txt");

    for (int i = 0; i < 1000000; i++)
    {
        archivoSalida << "Esta es la linea numero " << i << "\n";
    }

    archivoSalida.close();

    std::ifstream archivoEntrada("datos.txt");

    if (!archivoEntrada.is_open())
    {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }

    std::string linea;

    while (std::getline(archivoEntrada, linea))
    {
    }

    archivoEntrada.close();
}
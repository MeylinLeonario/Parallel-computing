#include "CPUTask.h"

bool esPrimo(int numero)
{
    if (numero < 2)
        return false;

    for (int i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
            return false;
    }

    return true;
}

void CPUTask::execute()
{
    int cantidadPrimos = 0;

    for (int i = 2; i <= 1000000; i++)
    {
        if (esPrimo(i))
        {
            cantidadPrimos++;
        }
    }
}
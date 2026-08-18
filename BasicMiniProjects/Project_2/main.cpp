#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void funcionLenta()
{
    for (int i = 0; i < 1000000; ++i)
    {
        // Simulación de una operación lenta
        volatile int x = i * i;
    }
}

int medirTiempo(void (*tarea)())
{
    auto start = high_resolution_clock::now();
    tarea();

    auto end = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(end-start);
    return duracion.count();
}

int main()
{
    int result = medirTiempo(funcionLenta);
    cout << "Tiempo de ejecucion: " << result << " microsegundos" << endl;
    return 0;
}
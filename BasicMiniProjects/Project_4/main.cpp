#include "IOTask.h"
#include "CPUTask.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

int main(){
    IOTask ioTask;
    CPUTask cpuTask;
    
    auto start = high_resolution_clock::now();
    ioTask.execute();
    cpuTask.execute();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);

    std::cout << "Tiempo siendo secuencial: " << duration.count() << " micosegundos." << std::endl;

    auto startParallel = high_resolution_clock::now();
    
    std::thread hiloIO(&IOTask::execute, &ioTask);
    std::thread hiloCPU(&CPUTask::execute, &cpuTask);

    hiloIO.join();
    hiloCPU.join();

    auto stopParallel = high_resolution_clock::now();

    auto durationParallel =
        duration_cast<microseconds>(stopParallel - startParallel);

    std::cout << "Tiempo en paralelo: "
            << durationParallel.count()
            << " microsegundos.";

    return 0;
}
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void tareaA() {
    std::cout << "Estoy ejecutando la tarea A" <<std::endl;
    int sum = 0;
    for (int i = 0; i < 100000000; i++){
        sum += i;
    }
}

void tareaB() {
    std::cout << "Estoy ejecutando la tarea B" <<std::endl;
    int sum = 0;
    for (int i = 0; i < 100000000; i++){
        sum += i*i;
    }
}

int main() {
    auto start = high_resolution_clock::now();

    std::cout << "========= SECUENCIAL ========" << std::endl;
    tareaA();
    tareaB();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);

    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
    
    
    std::cout << "======== CONCURRENTE ========" << std::endl;
    auto start2 = high_resolution_clock::now();

    thread t1(tareaA);
    thread t2(tareaB);

    t1.join();
    t2.join();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);

    std::cout << "Time taken: " << duration2.count() << " microseconds" << std::endl;
    return 0;
}
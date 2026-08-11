#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void funcionMatematica(int N){
    volatile int suma = 0;

    for (int i = 0; i < N; i++){
        suma += i ^ 2;
    }
}

int main() {
    auto start = high_resolution_clock::now();

    int n = 100000000000000;
    funcionMatematica(n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);

    cout << "La duración final fue: " << duration.count() << " microsegundos." << endl;
    return 0;
}
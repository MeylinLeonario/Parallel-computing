#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void tarea1(int id){
    cout << "Tarea " << id << endl;
}

void tarea2(int number){
    int suma = 0;
    suma += number;
}

int main(){
    vector<thread> threads;

    for (int i= 0; i< 5; i++){
        threads.emplace_back(tarea1, i); // Crea un thread que ejecute tarea1(i) y mételo al final del vector
        threads.emplace_back(tarea2,i);
    }

    for (auto& t : threads){
        t.join();
    }

    return 0;
}
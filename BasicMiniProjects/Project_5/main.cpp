#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void thread1(){
    int suma = 0;

    while (true){
        suma++;
        cout << suma << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
}

void thread2(){
    for (int i = 0; i < 10; i++){
        cout << "Hola!" << endl;
    }
}

void thread3(){
    while (true){
        cout << "sigo vivo" << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
}

int main() {
    thread t1(thread1);
    thread t2(thread2);
    thread t3(thread3);

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
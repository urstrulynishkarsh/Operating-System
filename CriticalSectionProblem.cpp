#include<iostream>
#include<thread>
#include<mutex> // Include mutex for synchronization

int counting = 0;
using namespace std;



void taskA() {
    for(int i = 0; i < 10000; i++) {
        counting += 1;
    }
}

int main() {
    thread t1(taskA);
    thread t2(taskA);

    t1.join();
    t2.join();

    cout << counting << endl;

    return 0;
}
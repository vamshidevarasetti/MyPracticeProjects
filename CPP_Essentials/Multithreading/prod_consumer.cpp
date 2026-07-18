#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <chrono>
#include <thread>

using namespace std;

queue <int> buffer;
int MAX_SIZE = 5;
condition_variable cv;
mutex mtx;

void producer(void){
    int value = 0;
    while(true){
        unique_lock<mutex> lock(mtx); 
        cv.wait(lock, [] {return (buffer.size() < MAX_SIZE);});

        buffer.push(value);
        cout<<"buffer inserted value " <<value<<endl;
        value++;

        if(buffer.size() == MAX_SIZE){
            lock.unlock();
            cv.notify_one();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        
    }
}

void consumer(void){
    while(true){
        unique_lock<mutex> lock(mtx); 
        cv.wait(lock, [](){return (!buffer.empty());});

        int value = buffer.front();
        cout<<"buffer front " <<value<<endl;
        buffer.pop();
        
        if(buffer.empty()){
            lock.unlock();
            cv.notify_one();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        
    }
}

int main(){
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
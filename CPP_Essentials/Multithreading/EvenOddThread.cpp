#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;



int count = 0;
mutex mtx;
condition_variable cv;
int MAX_COUNT = 10;


void oddthread()
{
    while(count < MAX_COUNT){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&](){return count%2 == 1;});
        cout<< "odd number : "<<count<<endl;
        ++count;
        lock.unlock();
        cv.notify_one();
    }
    
}

void eventhread()
{
    while(count < MAX_COUNT){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&](){return count%2 == 0;});
        cout<< "even number : "<<count<<endl;
        ++count;
        lock.unlock();
        cv.notify_one();
    }
}

int main(){
    thread t1(oddthread);
    thread t2(eventhread);

    t1.join();
    t2.join();

    return 0;
}
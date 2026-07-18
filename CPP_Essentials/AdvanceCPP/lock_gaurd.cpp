#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

void work(int &count, mutex &mtx)
{
    for (int i = 0; i < 1E6; i++)
    {
        //unique_lock<mutex> guard(mtx);
        lock_guard<mutex> lock(mtx);
        ++count;
    }
}

int main()
{
    int count = 0;

    mutex mtx;

    auto dowork1= [&](){work(count, mtx);};

    thread t1(dowork1);
    thread t2(work, ref(count), ref(mtx));

    t1.join();
    t2.join();

    cout << count << endl;

    return 0;
}
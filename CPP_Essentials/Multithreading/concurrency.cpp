#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <iomanip>

using namespace std;

mutex g_mtx;

int work(int id)
{
    unique_lock<mutex> lock(g_mtx);
    cout << "Starting " << id << endl;
    lock.unlock();

    this_thread::sleep_for(chrono::seconds(3));

    return id;
}

int main()
{
    vector<shared_future<int>> futures;
    const int CONCURRENCY = thread::hardware_concurrency();

    for(int i = 0; i < CONCURRENCY; i++)
    {
        shared_future<int> f = async(launch::async, work, i).share();
        futures.push_back(f);
    }

    for(auto f: futures)
    {
        cout << "Returned: " << f.get() << endl;
    }

    return 0;
}
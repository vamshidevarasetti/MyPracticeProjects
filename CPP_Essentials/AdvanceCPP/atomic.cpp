#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

void work(atomic<int>* count)
{
    for (int i = 0; i < 1E6; ++i)
    {
        ++(*count);  // Atomic increment
    }
}

int main()
{
    atomic<int> count{0};

    thread t1(work, &count);
    thread t2(work, &count);

    t1.join();
    t2.join();

    cout << "Final count: " << count << endl;

    return 0;
}

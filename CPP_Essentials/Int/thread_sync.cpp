#include <iostream>
#include <thread>
using namespace std;

class Counter {
    int count = 0;
public:
    void increment() {
        for (int i = 0; i < 10000; ++i)
            ++count;
    }

    int get() const { return count; }
};

int main() {
    Counter c;
    thread t1(&Counter::increment, &c);
    thread t2(&Counter::increment, &c);
    t1.join(); t2.join();
    cout << c.get() << endl;
}

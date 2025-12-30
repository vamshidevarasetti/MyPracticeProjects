#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int counter = 0;
bool done1 = false;
bool done2 = false;
std::mutex mtx;
std::condition_variable cv1, cv2;

void worker3(){
    for(int i=0;i<100;++i){
        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    std::cout << "Worker3: Counter is " << counter << std::endl;
        std::lock_guard<std::mutex> lock(mtx);
        done2 = true;

        cv2.notify_one();
}


void worker4(){
    std::unique_lock<std::mutex> lock(mtx);
    cv2.wait(lock, [](){return done2==true;});
    for(int i=0;i<100;++i){
        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    std::cout << "Worker4: Counter is " << counter << std::endl;
}


void worker1() {
    // Simulate work
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        ++counter;
    }
    std::cout << "Worker1: Counter is " << counter << std::endl;
    // Notify worker2
    std::lock_guard<std::mutex> lock(mtx);
    done1 = true;

    cv1.notify_one();  // Signal waiting thread
}

void worker2() {
    std::unique_lock<std::mutex> lock(mtx);
    cv1.wait(lock, [] { return done1; });  // Wait until done is true

    // Proceed after worker1 signals
    //std::cout << "before Worker2: Counter is " << counter << std::endl;

    // Simulate work
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        ++counter;
    }
    std::cout << "Worker2: Counter is " << counter << std::endl;
    
}

int main() {
    std::thread t1(worker1);
    std::thread t2(worker2);
    std::thread t3(worker3);
    std::thread t4(worker4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
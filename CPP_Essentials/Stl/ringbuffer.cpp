#include <iostream> 
#include <vector> 
#include <optional> 

template <typename T> 
class RingBuffer { 
private: 
    std::vector<T> buffer; 
    size_t head = 0; 
    size_t tail = 0; 
    size_t capacity; 
    bool full = false; 
public: 
    explicit RingBuffer(size_t size) : buffer(size), capacity(size) {} 


    bool push(const T& item) { 
        if (full) return false;  // Buffer full 
        buffer[head] = item; 
        head = (head + 1) % capacity; 
        full = (head == tail); 
        return true; 
    } 

    std::optional<T> pop() { 
        if (isEmpty()) return std::nullopt; 
        T item = buffer[tail]; 
        tail = (tail + 1) % capacity; 
        full = false; 
        return item; 
    } 

    bool isEmpty() const { 
        return (!full && head == tail); 
    } 

    bool isFull() const { 
        return full; 
    } 
    
    size_t size() const { 
        if (full) return capacity; 
        if (head >= tail) return head - tail; 
        return capacity + head - tail; 
    } 
}; 

 

 

 

int main() { 

    RingBuffer<int> rb(5); 

  

    rb.push(10); 

    rb.push(20); 

    rb.push(30); 

  

    while (!rb.isEmpty()) { 

        auto val = rb.pop(); 

        if (val) std::cout << "Popped: " << *val << std::endl; 

    } 

  

    return 0; 

} 

 
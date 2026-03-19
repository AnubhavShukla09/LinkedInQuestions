#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

class BoundedBlockingQueue {
private:
    queue<int> q;              // store elements
    int capacity;              // max size of queue
    mutex m;                   // lock for synchronization
    condition_variable notFull;   // signal when space available
    condition_variable notEmpty;  // signal when element available

public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }

    // add element to queue (wait if full)
    void enqueue(int element) {
        unique_lock<mutex> lock(m);

        // wait until queue has space
        notFull.wait(lock, [&]() {
            return q.size() < capacity;
        });

        q.push(element);   // insert element

        notEmpty.notify_one(); // notify waiting dequeue
    }

    // remove element from queue (wait if empty)
    int dequeue() {
        unique_lock<mutex> lock(m);

        // wait until queue not empty
        notEmpty.wait(lock, [&]() {
            return !q.empty();
        });

        int val = q.front();
        q.pop();

        notFull.notify_one(); // notify waiting enqueue

        return val;
    }

    // return current size
    int size() {
        unique_lock<mutex> lock(m);
        return q.size();
    }
};

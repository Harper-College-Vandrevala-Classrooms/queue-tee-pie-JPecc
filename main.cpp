#include <iostream>
#include <string>

using namespace std;

class Cutie {
public:
    virtual string description() = 0;     // All cuties need to have a description of what makes them cute.
    virtual int cuteness_rating() = 0;   // All cuties get a cuteness rating out of ten.
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }

    int cuteness_rating() override {
        return 11; // This puppy gets an 11 / 10 for its cuteness. Such a good boy!
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A tiny kitten with fluffy fur";
    }

    int cuteness_rating() override {
        return 10;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A small pygmy marmoset clinging to a branch";
    }

    int cuteness_rating() override {
        return 9;
    }
};

class QueueTees {
private:
    Cutie** queue;
    int max_size;
    int front;
    int rear;
    int current_size;

public:
    QueueTees(int size = 10) : max_size(size), front(0), rear(-1), current_size(0) {
        queue = new Cutie*[max_size];
    }

    QueueTees() {
        delete[] queue;
    }

    void enqueue(Cutie& cutie) {
        if (current_size == max_size) {
            cout << "The queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % max_size;
        queue[rear] = &cutie;
        current_size++;
    }

    Cutie* dequeue() {
        if (current_size == 0) {
            cout << "The queue is empty. Cannot dequeue." << endl;
            return nullptr;
        }
        Cutie* removed = queue[front];
        front = (front + 1) % max_size;
        current_size--;
        return removed;
    }

    int size() {
        return current_size;
    }
};

int main() {
    // Create a bunch of objects that conform to the Cutie interface
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    // Create a queue data structure
    QueueTees queue(3); // Setting the max size to 3 for demonstration

    // The size of the queue should equal zero since there are no objects in it
    cout << "Initial queue size: " << queue.size() << endl;

    // Add the cuties to the queue
    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    // The size of the queue should equal three since there are three objects in it
    cout << "Queue size after enqueuing three objects: " << queue.size() << endl;

    // The first dequeue should return the puppy
    Cutie* first = queue.dequeue();
    if (first) {
        cout << "Dequeued: " << first->description() << " with cuteness rating: " << first->cuteness_rating() << endl;
    }

    // The second dequeue should return the kitty
    Cutie* second = queue.dequeue();
    if (second) {
        cout << "Dequeued: " << second->description() << " with cuteness rating: " << second->cuteness_rating() << endl;
    }

    // The third dequeue should return the pygmy marmoset
    Cutie* third = queue.dequeue();
    if (third) {
        cout << "Dequeued: " << third->description() << " with cuteness rating: " << third->cuteness_rating() << endl;
    }

    return 0;
}

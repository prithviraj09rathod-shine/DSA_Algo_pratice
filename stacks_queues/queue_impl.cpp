#include <iostream>
using namespace std;

class Queue {
private:
    /**
     * @brief Index of the front element in the queue.
     *
     * Points to the position of the first element to be dequeued.
     * Updated after each dequeue operation.
     */
    int front, rear, currSize;
    int size;
    int* arr;
public:
    Queue(int c) {
        size = c;
        front = currSize = 0;
        rear = size - 1;
        arr = new int[size];
    } 
    ~Queue() {
        delete[] arr;
    }
    /**
     * @brief Adds an item to the end of the queue.
     * If the queue is full, it prints an error message.
     * Otherwise, it adds the item and updates the rear index and currSize.
     * @param item The item to be added to the queue.
     * @return void
     */
 
    void enqueue(int item) {
        if (currSize == size) {
            cout << "Queue Overflow\n";
            return;
        }
        //rear+1 bcoz we want to add the new item at the end of the queue       
        rear = (rear + 1) % size; //assume circular queue and wrap around
        arr[rear] = item;
        currSize++;
    }
    int dequeue() {
        if (currSize == 0) {
            cout << "Queue Underflow\n";
            exit(EXIT_FAILURE);
        }
        int item = arr[front];
        front = (front + 1) % size; //assume circular queue and wrap around
        currSize--;
        return item;
    }
    int getFront() {
        if (currSize == 0) {    
            cout << "Queue is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }
    int getRear() {
        if (currSize == 0) {
            cout << "Queue is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[rear];
    }
    bool isEmpty() {
        return currSize == 0;
    }
    bool isFull() {
        return currSize == size;
    }
    int getcurrSize() {
        return currSize;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }
        for (int i = 0; i < currSize; i++) {
            cout << arr[(front + i) % size] << " ";
        }   
        cout << endl;
    }
    void printEnqueue(int item) {
        enqueue(item);
        cout << "Item " << item << " enqueued\n";
    }

    void printDequeue() {
        int item = dequeue();
        cout << "Item " << item << " dequeued\n";
    }
    void printFront() {
        int item = getFront();
        cout << "Front item: " << item << endl;
    }
    void printRear() {
        int item = getRear();
        cout << "Rear item: " << item << endl;
    }
    void printIsEmpty() {
        cout << "Is queue empty? " << (isEmpty() ? "Yes" : "No") << endl;
    }
    void printIsFull() {
        cout << "Is queue full? " << (isFull() ? "Yes" : "No") << endl;
    }
    void printcurrSize() {
        cout << "Queue currSize: " << getcurrSize() << endl;
    }
    void printDisplay() {
        display();
        cout << "Queue displayed\n";
    }
};  

int main() {
    Queue q(5);
    q.printEnqueue(10);
    q.printEnqueue(20);
    q.printEnqueue(30);
    
    q.printFront();
    q.printRear();
    
    q.printDequeue();
    
    q.printDisplay();
    
    q.printcurrSize();
    q.printIsEmpty();
    q.printIsFull();
    
    return 0;
}

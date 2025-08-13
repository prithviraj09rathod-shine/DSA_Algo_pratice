#include<iostream>
//#include Deque
using namespace std;
#define MAX 100

class Deque {
    int arr[MAX];
    int front, rear, size;
public:
    Deque(int size){
        front=-1, rear=-1;
        this->size = size;
    }       
    bool isFull() {
        return (size == MAX || (front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front);
    }
    bool isEmpty() {
        return (size == 0 || front == -1);
    }
    void insertFront(int data) {
        if (isFull()) {
            cout << "Deque is full" << endl;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1; // Circular decrement
        } else {
            front = (front - 1 + MAX) % MAX; // Circular increment
        }
        arr[front] = data;
        size++;
        cout << "Inserted at front: " << data << endl;
    }
    void insertRear(int data) {
        if (isFull()) {
            cout << "Deque is full" << endl;
        }
        if (rear == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0; // Circular increment
        } else {
            rear = (rear + 1) % MAX; // Circular increment
        }
        arr[rear] = data;
        size++;
        cout << "Inserted at rear: " << data << endl;
    }
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
        }
        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1; // Deque is now empty
        } else {
            front = (front + 1) % MAX; // Circular increment
        }
        size--;
    }
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1; // Deque is now empty
        } else if (rear == 0) {
            rear = MAX - 1; // Circular decrement
        } else {
            rear = (rear - 1 + MAX) % MAX; // Circular decrement
        }
        size--;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1; // or throw an exception
        }
        return arr[front];
    }
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1; // or throw an exception
        }
        return arr[rear];
    }
    int getSize() {
        return size;
    }
};

int main() {
    Deque dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    cout << "Front element: " << dq.getFront() << endl; // Should print 5
    cout << "Rear element: " << dq.getRear() << endl; // Should print 20
    cout << "Deque size: " << dq.getSize() << endl; // Should print 3
    dq.deleteFront();
    cout << "Front element after deletion: " << dq.getFront() << endl; // Should print 10
    dq.deleteRear();
    cout << "Rear element after deletion: " << dq.getRear() << endl; // Should print 10
    return 0;
}
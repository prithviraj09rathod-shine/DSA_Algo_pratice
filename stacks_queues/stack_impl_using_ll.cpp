#include<iostream>
using namespace std;

class stack {
  struct Node {
    int data;
    Node* next;
  };
  Node* topNode;    
public:
  stack() : topNode(nullptr) {}     
    void push(int data) {
        Node* newNode = new Node{data, topNode};
        topNode = newNode;
        //or can be written as:
        //newNode = new Node(data); // temp node to insert
        //newNode->next = topNode;
        //topNode = newNode; 
        cout << "Element pushed: " << data << endl;
    }
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }       
    int top() { 
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return -1; // or throw an exception
        }
        return topNode->data;
    }
    bool isEmpty() {
        return topNode == nullptr;
    }
    int size() {
        int count = 0;
        Node* current = topNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};      

int main() {
    stack s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.top() << endl; // Should print 20
    cout << "Stack size: " << s.size() << endl; // Should print 2
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Should print 10
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Should print No
    return 0;
}   
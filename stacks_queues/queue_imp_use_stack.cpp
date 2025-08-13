#include <bits/stdc++.h>

using namespace std;

struct Queue {
  stack < int > stack1, stack2;
  
  // Push elements in queue
  void Push(int data) {
    // Pop out all elements from the stack stack1
    while (!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }
    // Insert the desired element in the stack stack1
    cout << "The element pushed is " << data << endl;
    stack1.push(data);
    // Pop out elements from the stack stack2 and push them into the stack stack1
    while (!stack2.empty()) {
      stack1.push(stack2.top());
      stack2.pop();
    }
  }
  // Pop the element from the Queue
  int Pop() {
    if (stack1.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = stack1.top();
    stack1.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (stack1.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return stack1.top();
  }
  // Return the size of the Queue
  int size() {
    return stack1.size();
  }
};
int main() {
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
}
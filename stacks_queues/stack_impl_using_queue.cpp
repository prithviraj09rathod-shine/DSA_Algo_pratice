#include<iostream>
#include <queue>

using namespace std;

class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);//push the new element at the end of the queue
      //move all the elements which are before the new element(i.e x) to the back of the queue
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }//this will make the new element at the front of the queue and rearranges all existing elements
      //so that the new element is at the top of the stack
      cout << "Element pushed: " << x << endl;
    }

  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}

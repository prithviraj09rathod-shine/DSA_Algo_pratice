#include <iostream>
using namespace std;

class stack{
    int size;
    int top;
    int *arr;
public:
    stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }
    ~stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top >= size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    } 

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            exit(EXIT_FAILURE);
        }
        int x = arr[top + 1];
        top--;
        return x;  
    }

    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == size - 1;
    }   
    int Top() {
        if (top < 0) {
            cout << "Stack is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
           
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
  int getSize() {
    return top + 1;
  } 
  
    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    int getCapacity() {
        return size;
    }
    int getTop() {
        if (top < 0) {
            cout << "Stack is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    int getTopIndex() {
        return top;
    }
    void clear() {
        top = -1;
    }
    void resize(int newSize) {
        if (newSize <= size) {
            cout << "New size must be greater than current size\n";
         
        }
        int* newArr = new int[newSize];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size = newSize;
    }
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void reverse() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            
        }
        int* temp = new int[size];
        int index = 0;
        for (int i = top; i >= 0; i--) {
            temp[index++] = arr[i];
        }
        for (int i = 0; i < index; i++) {
            arr[i] = temp[i];
        }
        top = index - 1;
        delete[] temp;
    }
    void swap(int index1, int index2) {
        if (index1 < 0 || index2 < 0 || index1 > top || index2 > top) {
            cout << "Invalid indices\n";
            
        }
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    void sort() {
        if (isEmpty()) {
            cout << "Stack is empty\n";

        }
        for (int i = 0; i <= top; i++) {
            for (int j = i + 1; j <= top; j++) {
                if (arr[i] > arr[j]) {
                    swap(i, j);
                }
            }
        }
    }
    void unique() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        int* temp = new int[size];
        int index = 0;
        for (int i = 0; i <= top; i++) {
            bool found = false;
            for (int j = 0; j < index; j++) {
                if (temp[j] == arr[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                temp[index++] = arr[i];
            }
        }
        delete[] arr;
        arr = temp;
        top = index - 1;
    }
    void printReverse() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[top - i] << " ";
        }
        cout << endl;
    }
    void printTop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }
    void printBottom() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Bottom element: " << arr[0] << endl;
    }
    void printMiddle() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        if (top % 2 == 0) {
            cout << "Middle element: " << arr[top / 2] << endl;
        } else {
            cout << "Middle elements: " << arr[top / 2] << " and " << arr[top / 2 + 1] << endl;
        }
    }
    void printAll() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }               
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void printCapacity() {
        cout << "Stack capacity: " << size << endl;
    }
    void printSize() {
        cout << "Stack size: " << top + 1 << endl;
    }
    void printTopIndex() {
        cout << "Top index: " << top << endl;
    }
    void printIsEmpty() {
        cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;
    }
    void printIsFull() {
        cout << "Is stack full? " << (isFull() ? "Yes" :    "No") << endl;
    }
    void printClear() {
        clear();
        cout << "Stack cleared\n";
    }
    void printResize(int newSize) {
        resize(newSize);
        cout << "Stack resized to " << newSize << endl;
    }
    void printReverseStack() {
        reverse();
        cout << "Stack reversed\n";
    }
    void printSwap(int index1, int index2) {
        swap(index1, index2);
        cout << "Elements at indices " << index1 << " and " << index2 << " swapped\n";
    }
    void printSort() {
        sort();
        cout << "Stack sorted\n";
    }
    void printUnique() {
        unique();
        cout << "Unique elements in stack\n";
    }
    void printPrintReverse() {
        printReverse();
        cout << "Stack printed in reverse order\n";
    }
    void printPrintTop() {
        printTop();
        cout << "Top element printed\n";
    }
    void printPrintBottom() {
        printBottom();
        cout << "Bottom element printed\n";
    }
    void printPrintMiddle() {
        printMiddle();
        cout << "Middle element(s) printed\n";
    }
    void printPrintAll() {
        printAll();
        cout << "All elements printed\n";
    }
    void printPrintCapacity() { 
        printCapacity();
        cout << "Stack capacity printed\n";
    }
    void printPrintSize() {
        printSize();            
        cout << "Stack size printed\n";
    }
    void printPrintTopIndex() {
        printTopIndex();
        cout << "Top index printed\n";
    }
    void printPrintIsEmpty() {
        printIsEmpty();
        cout << "Is stack empty printed\n";
    }
    void printPrintIsFull() {
        printIsFull();
        cout << "Is stack full printed\n";
    }
    void printPrintClear() {
        printClear();      
    } 

    

};      

int main() {
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.Top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.Top() << endl;

    s.display();
    
    s.printSize();
    s.printCapacity();
    s.printIsEmpty();
    s.printIsFull();
    
    return 0;
}
#include <iostream>
using namespace std;
template <class T>

class stack {
    struct node {
        T item;
        node *next;
    };
    node *top, *cur;

public:
    stack() {
        top = NULL;
    }

    void push(T newItem) {
        node *newItemPtr = new node;
        if(newItemPtr == NULL) {
            cout << "Stack push cannot allocate memory: " << endl;
        }
        else {
            newItemPtr->item = newItem;
            newItemPtr->next = top;
            top = newItemPtr;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack empty on pop(): " << endl;
        }
        else {
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void pop(T &stackTop) {
        if(isEmpty()) {
            cout << "Stack empty on pop(): " << endl;
        }
        else {
            stackTop = top->item;
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void getTop(T &stackTop) {
        if(isEmpty()) {
            cout << "Stack empty on getTop(): " << endl;
        }
        else {
            stackTop = top->item;
        }
    }

    void display() {
        cur = top;
        cout << "\nItems in the stack : " << endl;
        cout << "[";
        while(cur != NULL) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]" << endl;
    }
};

int main() {

    stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    s.display();

    int x = 0;
    s.getTop(x);
    s.display();

    cout << x << endl;
    return 0;
}
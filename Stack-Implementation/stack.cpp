#include <iostream>
using namespace std;
const int MAX_SIZE = 5;

template <class T> 

class stack {
private:
    int top;
    T item[MAX_SIZE];
public:
    stack():top (-1) {}

    void push(T Element) {

        if(top >= MAX_SIZE - 1) {
            cout << "Stack full on push" << endl;
        }
        else {
            item[++top] = Element;
        }
    }

    bool isEmpty() {
        return top < 0;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack empty on pop: " << endl;
        }
        else {
            top--;
        }
    }

    void pop(T & Element) {
        if(isEmpty()) {
            cout << "Stack empty on pop: " << endl;
        }
        else {
            Element = item[top];
            top--;
        }
    }

    void getTop(T & stackTop) {
        if(isEmpty()) {
            cout << "Stack empty on getTop: " << endl;
        }
        else {
            stackTop = item[top];
            cout << stackTop << endl;
        }
    }

    void print() {
        cout << "[";
        for(int i = top; i >= 0; i--) {
            cout << item[i] << " ";
        }
        cout << "]";
        cout << endl;
    }

};

int main()
{
    int x = 0;
    int y = 0;
	stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.push(60);

    s.print();
    s.getTop(x);
    s.pop(y);
    s.getTop(x);
    cout << y << endl;
    cout << x << endl;

    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    

    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);

    s.print();

	return 0;
}


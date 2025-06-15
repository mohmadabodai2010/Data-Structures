#include <iostream>
#include <assert.h>

using namespace std;
template <class t>

class arrayQueueType
{
    int rear;
    int front;
    int count;
    t *arr;
    t maxSize;
public:
    arrayQueueType(t size){
        if (size <= 0)maxSize = 100;
        else maxSize = size;

        arr = new t[maxSize];
        front = 0;
        rear = maxSize - 1;
        count = 0;
    }

    int isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == maxSize;
    }

    void enQueue(t Element){
        if(isFull()){
            cout << "Queue Full can't Enqueue ...!"<< endl;
        }
        else{
            rear = (rear + 1) % maxSize;
            arr[rear] = Element;
            count++;
        }
    }

    void deQueue(){
        if(isEmpty()){
            cout << "Queue is Empty can't Dequeue ...!" << endl;
        }
        else {
            front = (front + 1) % maxSize;
            count--;
        }
    }

    int frontQueue(){
        assert(!isEmpty());
        return arr[front];
    }

    int rearQueue(){
        assert(!isEmpty());
        return arr[rear];
    }

    void printQueue(){
        for(size_t i = front; i != rear; i = (i+1)%maxSize){
            cout << arr[i] << " ";
        }
        cout << arr[rear] << " ";
    }

    int queueSearch(t element){
        int pos = -1;
        if(!isEmpty()){
            for(int i = front; i != rear; i = (i+1) % maxSize){
                if(arr[i] == element){
                    pos = i;
                    break;
                }
            }
            if(pos == -1){
                if(arr[rear] == element){
                    pos = rear;
                }
            }
        }
        else
            cout << "Queue is Empty ...! " << endl;
        return pos;
    }

};

int main(){
    arrayQueueType<int>q1(5);
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);
    q1.enQueue(60);
    q1.deQueue();
    q1.deQueue();
    q1.deQueue();

    // q1.printQueue();

    q1.enQueue(70);
    q1.enQueue(80);
    q1.printQueue();
    cout << q1.queueSearch(40) << endl;
    
    return 0;
}
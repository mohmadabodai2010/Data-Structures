#include <iostream>
#include <assert.h>
const int MAX_SIZE = 10;

using namespace std;
template <class t>

class arrayQueueType
{
    int rear;
    int front;
    int count;
    t arr[MAX_SIZE];
public:
    arrayQueueType(){
        front = 0;
        rear = MAX_SIZE - 1;
        count = 0;
    }

    int isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == MAX_SIZE;
    }

    void enQueue(t Element){
        if(isFull()){
            cout << "Queue Full can't Enqueue ...!"<< endl;
        }
        else{
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = Element;
            count++;
        }
    }

    void deQueue(){
        if(isEmpty()){
            cout << "Queue is Empty can't Dequeue ...!" << endl;
        }
        else {
            front = (front + 1) % MAX_SIZE;
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
        for(size_t i = front; i != rear; i = (i+1)%MAX_SIZE){
            cout << arr[i] << " ";
        }
        cout << arr[rear] << " ";
    }

    int queueSearch(t element){
        int pos = -1;
        if(!isEmpty()){
            for(int i = front; i != rear; i = (i+1) % MAX_SIZE){
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
    arrayQueueType<int>q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);
    q1.enQueue(60);
    q1.deQueue();

    q1.printQueue();

    cout << q1.queueSearch(30) << endl;
    
    return 0;
}
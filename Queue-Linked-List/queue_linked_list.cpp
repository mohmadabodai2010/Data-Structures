#include <iostream>

using namespace std;

class linkedQueue{
private:
    struct Node{
        int item;
        Node *next;
    };
    Node *frontPtr;
    Node *rearPtr;
    int length;
public:
    linkedQueue(){
        frontPtr = rearPtr = NULL;
        length = 0;
    }
    
    bool isEmpty(){
        return length == 0;
    }

    void enQueue(int element){
        if(isEmpty()){
            frontPtr = new Node;
            frontPtr ->item = element;
            frontPtr ->next = NULL;
            rearPtr = frontPtr;
            length++;
        }
        else{
            Node *newPtr = new Node;
            newPtr ->item = element;
            newPtr ->next = NULL;
            rearPtr ->next = newPtr;
            rearPtr = newPtr;
            length++;
        }
    }

    void deQueue(){
        if(isEmpty()){
            cout << "Empty Queue, Cannot Dequeue...!" << endl;
        }
        else{
            Node *tempPtr = frontPtr;
            if(frontPtr == rearPtr){
                frontPtr = NULL;
                rearPtr = NULL;
                length--;
            }
            else{
                frontPtr = frontPtr ->next;
                tempPtr ->next = NULL;
                delete tempPtr; // or free(tempPtr)
                length--;
            }
        }
    }

    int getFront(){
        if(isEmpty()){
            cout << "Empty Queue, Cannot Dequeue...!" << endl;
        }
        else{
            return frontPtr->item;
        }
    }

    int getRear(){
        if(isEmpty()){
            cout << "Empty Queue, Cannot Dequeue...!" << endl;
        }
        else{
            return rearPtr->item;
        }
    }

    void getFront(int &element){
        if(isEmpty()){
            cout << "Empty Queue, Cannot Dequeue...!" << endl;
        }
        else{
            element = frontPtr->item;
        }
    }

    void display(){
        Node *curPtr = frontPtr;
        cout << "Items in the Queue : " << endl;
        while (curPtr != NULL)
        {
            cout << curPtr->item << " ";
            curPtr = curPtr->next;
        }
        
    }

    void clearQueue(){
        Node *current;
        while (frontPtr != NULL)
        {
            current = frontPtr;
            frontPtr = frontPtr->next;
            delete current;
        }
        rearPtr = NULL;
        length = 0;
        
    }

    int getSize(){
        return length;
    }
};


int main(){
    linkedQueue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    cout << q1.getFront();
    cout << q1.getRear();

    q1.display();
}
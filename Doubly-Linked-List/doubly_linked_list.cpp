#include<iostream>

using namespace std;

class linkedList{
    struct Node{
        int item;
        Node *prev;
        Node *next;
    };
    Node *first;
    Node *last;
    int length;
public:
    linkedList(){
        first = last = NULL;
        length = 0;
    }

    bool isEmpty(){
        return length == 0;
    }

    void insertFirst(int element){
        Node *newNode = new Node();
        newNode->item = element;
        if(length == 0){
            first = last = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else{
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;
        }
        length++;
    }

    void insertLast(int element){
        Node *newNode = new Node();
        newNode->item = element;
        if(length == 0){
            first = last = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else{
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    void insertAtPos(int pos, int element){
        if(pos < 0 || pos > length){
            cout << "Out of Range...!" << endl;
        }
        else{
            Node *newNode = new Node();
            newNode->item = element;
            if(pos == 0){
                insertFirst(element);
            }
            else if(pos == length){
                insertLast(element);
            }
            else{
                Node *Cur = first;
                for(size_t i = 1; i < pos; i++){
                    Cur = Cur->next;
                }
                newNode->next = Cur->next;
                newNode->prev = Cur;
                Cur->next = newNode;
                Cur->next->prev = newNode;
                length++;
            }
        }
    }

    void removeFirst(){
        if(isEmpty()){
            cout << "The linked list is Empty...!" << endl;
        }
        else if(length == 1){
            delete first;
            first = last = NULL;
            length--;
        }
        else{
            Node *temp = first;
            first = temp->next;
            first->prev = NULL;
            delete temp;
            length--;
        }
    }

    void removeLast(){
        if(isEmpty()){
            cout << "The linked list is Empty...!" << endl;
        }
        else if(length == 1){
            delete first;
            first = last = NULL;
            length--;
        }
        else{
            Node *temp = last;
            last = temp->prev;
            last->next = NULL;
            delete temp;
            length--;
        }
    }

    void remove(int element){
        Node *prev;
        if(isEmpty()){
            cout << "The linked list is Empty...!" << endl;
        }
        else if(first->item == element){
            removeFirst();
        }
        else{
            Node *temp = first->next;
            while(temp != NULL)
            {
                if(temp->item == element){
                    break;
                }
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "not found...!" << endl;
            }
            else if(temp->next == NULL){
                removeLast();
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                length--;
            }
        }
    }

    void reverse(){
        Node *Curr = last;
        while (Curr != NULL)
        {
            cout << Curr->item << " ";
            Curr = Curr->prev;
        }
        cout << endl;
    }

    void print(){
        Node *Cur = first;
        while (Cur != NULL)
        {
            cout << Cur->item << " ";
            Cur = Cur->next;
        }
        cout << endl;
    }

};

int main(){
    linkedList dl;
    dl.insertFirst(10);
    dl.insertAtPos(1, 20);
    dl.insertAtPos(2, 30);
    dl.insertAtPos(3, 40);
    dl.insertLast(50);
    dl.print();
    dl.reverse();
}
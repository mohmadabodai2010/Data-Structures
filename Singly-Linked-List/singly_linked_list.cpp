#include<iostream>

using namespace std;

class linkedList{
    struct Node{
        int item;
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
            newNode->next = NULL;
        }
        else{
            newNode->next = first;
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
        }
        else{
            last->next = newNode;
            newNode->next = NULL;
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
                Cur->next = newNode;
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
            Node *temp = first->next;
            Node *prev = first;
            while (temp != last)
            {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = NULL;
            last = prev;
            length--;
        }
    }

    void removeAtPos(int pos){
        Node *temp;
        Node *prev;
        if(isEmpty()){
            cout << "The linked list is Empty...!" << endl;
        }
        else if(pos == 0){
            temp = first;
            first = first->next;
            delete temp;
            length--;
            if(length == 0){
                last = NULL;
            }
        }
        else{
            temp = first->next;
            prev = first;
            for(size_t i = 1; i < pos; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "not found...!" << endl;
            }
            else {
            prev->next = temp->next;
            if(last == temp){
                last = prev;
            }
            delete temp;
            length--;
            }
        }
    }

    void remove(int element){
        Node *temp;
        Node *prev;
        if(isEmpty()){
            cout << "The linked list is Empty...!" << endl;
        }
        else if(first->item == element){
            temp = first;
            first = first->next;
            delete temp;
            length--;
            if(length == 0){
                last = NULL;
            }
        }
        else{
            temp = first->next;
            prev = first;
            while(temp != NULL)
            {
                if(temp->item == element){
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "not found...!" << endl;
            }
            else {
            prev->next = temp->next;
            if(last == temp){
                last = prev;
            }
            delete temp;
            length--;
            }
        }
    }

    void reverse(){
        Node *prev, *next, *curr;
        prev = NULL;
        curr = first;
        next = curr->next;
        while(next != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        first = prev;
    }

    int search(int element){
        Node *curr = first;
        int pos = 0;
        while(curr != NULL){
            if(curr->item == element){
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1;
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
    linkedList l;
    // l.insertFirst(10);
    // l.insertLast(20);
    // l.insertLast(30);
    // l.print();
    // l.insertAtPos(1, 15);
    // l.print();
    // l.insertFirst(0);
    // l.insertLast(40);
    // l.print();
    // l.removeFirst();
    // l.removeLast();
    // l.removeAtPos(2);
    // l.remove(15);
    // l.print();
    l.insertFirst(10);
    l.insertLast(40);
    l.insertLast(50);
    l.insertAtPos(1, 20);
    l.print();
    l.reverse();
    l.print();
    cout << l.search(40) << endl;

}
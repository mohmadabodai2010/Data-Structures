#include <iostream>

using namespace std;

class arrayList {
    int *arr;
    int maxSize;
    int length;
public:
    arrayList(int s){
        if(s < 0){
            maxSize = 10;
        }
        else{
            maxSize = s;
            length = 0;
            arr = new int[maxSize];
        }
    }

    bool isEmpty(){
        return length == 0;
    }

    bool isFull(){
        return length == maxSize;
    }

    int getSize(){
        return length;
    }

    void print(){
        for(size_t i = 0; i < length; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertAtEnd(int element){
        if(isFull()){
            cout << "The List is Full can't Insert ...!" << endl;
        }
        else{
            arr[length] = element;
            length++;
        }
    }

    void insertAtPos(int pos, int element){
        if(isFull()){
            cout << "List is Full ...!" << endl;
        }
        else if(pos < 0 || pos > length){
            cout << "Out of Range ...!" << endl;
        }
        else{
            for(size_t i = length; i > pos; i--){
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            length++;
        }
    }

    int search(int element){
        for(size_t i = 0; i < length; i++){
            if(arr[i] == element){
                return i;
            }
            else{
                return -1;
            }
        }
    }

    void removeAtPos(int pos){
        if(isEmpty()){
            cout << "List is Empty ...!" << endl;
        }
        else if(pos < 0 || pos > length){
            cout << "Out of Range ...!" << endl;
        }
        else{
            for(size_t i = pos; i < length; i++){
                arr[i] = arr[i + 1];
            }
        }
    }
};

int main(){
    arrayList ar(100);

    ar.insertAtPos(0, 10);
    ar.insertAtPos(1, 20);
    ar.insertAtEnd(30);
    ar.print();
}
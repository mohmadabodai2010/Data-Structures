#include <iostream>
#include <string>
#include <stack>
using namespace std;




bool Pair(char ope, char cls){
    if (ope == '(' && cls == ')'){
        return true;
    }
    else if (ope == '[' && cls == ']'){
        return true;
    }
    else if (ope == '{' && cls == '}'){
        return true;
    }
    else {
        return false;
    }
}
bool Balanced(string exp ){
    stack<char> op ;
    for(char i : exp){
        if (i == '(' || i == '[' || i == '{'){
            op.push(i);
        }
        else if (i == ')' || i == ']' || i == '}') {
            if (op.empty() || !Pair(op.top(), i)){
                return false;
            }
            else {
                op.pop();
            }
        }
    }
    return op.empty()?true:false;
}

int main() {
    string expression;
    cout << "Enter an Expression: " << endl;
    cin >> expression;
    if(Balanced(expression)){
        cout << "Balanced: " << endl;
    }
    else{
        cout << "Not Balanced: " << endl;
    }
}

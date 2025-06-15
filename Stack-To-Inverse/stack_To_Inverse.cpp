#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> stackToInverse(stack<int> &s){
	stack<int> inverse = s;
	while (!s.empty())
	{
		s.pop();
	}
	
	while (!inverse.empty())
	{
		s.push(inverse.top());
		inverse.pop();
	}
	for(int i = 0; i < inverse.size(); i++){
		cout << " " << inverse.top() ;
		inverse.pop();
	}

	return inverse;
}


int main()
{
    stack<int> firstStack;
	stack<int> secondStack;
	int Size = 0;
	int number = 0;
	cout << "Enter the Size of Stack: " << endl;
	cin >> Size;

	cout << "Enter the Number to the Stack: " << endl;
	for(int i = 0; i < Size; i++){
		cin >> number;
		firstStack.push(number);
		
	}
	
	secondStack = firstStack;

	cout << "The Items of the Stack Befor the Inverse are: " << endl;
	cout << "[";
	for(int i = 0; i < Size; i++){
		cout << " " << secondStack.top();
		secondStack.pop();
	}
	cout << " ]" << endl;

	stackToInverse(firstStack);

	cout << "The Items of the Stack After the Inverse are: " << endl;
	cout << "[";
	for(int i = 0; i < Size; i++){
		cout << " " << firstStack.top() ;
		firstStack.pop();
	}
	cout << " ]" << endl;
	return 0;
}

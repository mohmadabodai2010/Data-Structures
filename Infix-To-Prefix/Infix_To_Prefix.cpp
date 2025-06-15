#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}


string InfixToPrefix(string expression)
{
	stack<char> S;
	stack<char> p;
    string prefix = "";
	for (int i = expression.length()-1; i >= 0 ; i--) {

		if (expression[i] == ' ' || expression[i] == ',') continue;

		if(IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != ')' && HasHigherPrecedence(S.top(), expression[i]))
			{
				p.push(S.top());
				S.pop();
			}
			S.push(expression[i]);
		}

		else if (IsOperand(expression[i]))
		{
			p.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == '(')
		{
			while (!S.empty() && S.top() != ')') {
				p.push(S.top());
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.empty()) {
		p.push(S.top());
		S.pop();
	}

    while (!p.empty())
    {
        prefix += p.top();
        p.pop();
    }
    
	return prefix;
}



double valueOfPrefix(string exp){
	stack<double> s;
	double firsNumber = 0;
	double scondeNumber = 0;
	double sum = 0;
	double cast = 0;

	for (int i = exp.length()-1; i >= 0; i--) {

		if (exp[i] == ' ' || exp[i] == ',') continue;

		else if( IsOperand(exp[i]) )
		{
			string c(1, exp[i]);
			cast = (double)  stoi(c);
			//cout << "\nThe cast is: " << cast << "\n";
			s.push(cast);
		}
		else if(IsOperator(exp[i]))
		{
			firsNumber = s.top();
			s.pop();
			scondeNumber = s.top();
			s.pop();

			if(exp[i] == '*'){
				sum = firsNumber * scondeNumber;
				s.push(sum);
			}
			else if(exp[i] == '/'){
				sum = firsNumber / scondeNumber;
				s.push(sum);
			}
			else if(exp[i] == '+'){
				sum = firsNumber + scondeNumber;
				s.push(sum);
			}
			else if(exp[i] == '-'){
				sum = firsNumber - scondeNumber;
				s.push(sum);
			}
		}
	}
	return sum;
}

int main()
{
	string expression = "((3+2)/6)-7";
	//cout << "Enter Infix Expression \n";
	//getline(cin, expression);
	string prefix = InfixToPrefix(expression);
	cout << "Output = " << prefix << "\n" << "The sum of prefix is: " << valueOfPrefix(prefix) << "\n";
	return 0;
}
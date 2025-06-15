#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
	if (ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}

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


double valueOfPostfix(string exp)
{
	stack<double> s;
	double firsNumber = 0.0;
	double scondeNumber = 0.0;
	double sum = 0.0;
	double cast = 0;

	for (unsigned int i = 0; i < exp.length(); i++) {

		if (exp[i] == ' ' || exp[i] == ',') continue;

		else if (IsOperand(exp[i]))
		{
			string c(1, exp[i]);
			cast = (double)  stoi(c);
			//cout << "The cast is: " << cast << "\n";
			s.push(cast);
		}

		else if (IsOperator(exp[i]))
		{
			scondeNumber = s.top();
			s.pop();
			firsNumber = s.top();
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

string infixToPostfix(string s) {

	stack<char> st;
	string ans = "";

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];

		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			ans += ch;

		else if (ch == '(')
			st.push('(');

		else if (ch == ')') {
			while (st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty() && prec(s[i]) <= prec(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	return ans;
}

int main() {
	string s1 = "(3+2)+7/2*((7+3)*2)";
	string s2 = "(2+4+((4+5)*6))/5";
	string s3 = "3+(8/2)-5";
	string postfix = infixToPostfix(s1);
	cout << "Output = " << postfix << "\n" << "The sum of postfix is: " << valueOfPostfix(postfix) << "\n" << endl;
	return 0;
}
#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;
double cal(double a, double b, char op);

int main()
{
	string str; // 입력 문자열
	int n; // 피연산자 수
	stack<double> s; // 피연산자를 담을 스택
	double alphabet[26]; // 피연산자에 해당하는 숫자를 저장할 배열

	cin >> n;
	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < n; i++)
		cin >> alphabet[i]; 

	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') // 피연산자일 경우 숫자로 변환하여 스택에 push
		{
			s.push(alphabet[str[i] - 'A']);
		}
		else // 연산자인 경우 스택의 위의 두 수를 뽑아 순서를 뒤집어 연산 후 다시 push
		{
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();
			s.push(cal(a, b, str[i]));
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << '\n';

	return 0;
}

double cal(double a, double b, char op)
{
	double res = 0.;
	switch (op)
	{
	case '+':
		res = b + a;
		break;
	case '-':
		res = b - a;
		break;
	case '*':
		res = b * a;
		break;
	case '/':
		res = b / a;
		break;
	}
	return res;
}
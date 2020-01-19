#include<iostream>
#include<string>
using namespace std;

struct Stack
{
	int size;
	int data[10000];

	Stack() // 생성자
	{
		size = 0;
	}

	void push(int n)
	{
		data[size] = n;
		size++;
	}

	bool empty()
	{
		if (!size) return true;
		else return false;
	}

	int pop()
	{
		if (empty()) return -1;
		else
		{
			size--;
			return data[size];
		}
	}

	int top()
	{
		if (empty()) return -1;
		else
		{
			return data[size - 1];
		}
	}
};

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);     // NULL -> nullptr  사용가능
	cout.tie(NULL);
	
	int n;

	cin >> n;

	Stack s;
	

	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "top")
		{
			cout << s.top() << '\n';
		}
		else if (cmd == "size")
		{
			cout << s.size << '\n';
		}
		else if (cmd == "empty")
		{
			cout << s.empty() << '\n';
		}
		else if (cmd == "pop")
		{
			cout << s.pop() << '\n';
			
		}
	}
	return 0;
}
#include<iostream>
#include<string>

using namespace std;

struct Queue
{
	int begin;
	int end;
	int data[10000]; // N (1 ¡Â N ¡Â 10,000)

	Queue()
	{
		begin = 0;
		end = 0;
	}
public:
	void pop()
	{
		if (empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << data[begin] << '\n';
			data[begin] = 0;
			begin++;
		}
	}
	void push(int n)
	{
		data[end++] = n;
	}

	void size()
	{
		cout << end - begin << '\n';
	}

	bool empty()
	{
		if (begin == end) return true;
		else return false;
	}
	
	void front()
	{
		if (empty())
			cout << -1 << '\n';
		else
			cout << data[begin] << '\n';
	}

	void back()
	{
		if (empty())
			cout << -1 << '\n';
		else
			cout << data[end - 1] << '\n';
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // test case
	Queue q;

	cin >> n;
	cin.ignore();

	while (n--)
	{
		string cmd;
		
		cin >> cmd;

		if (cmd == "push")
		{
			int input;
			cin >> input;
			q.push(input);
		}
		else if (cmd == "pop")
		{
			q.pop();
		}
		else if (cmd == "size")
		{
			q.size();
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (cmd == "front")
		{
			q.front();
		}
		else if (cmd == "back")
		{
			q.back();
		}
	}

	return 0;
}
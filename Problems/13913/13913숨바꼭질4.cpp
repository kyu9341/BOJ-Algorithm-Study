#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
int sec[MAX + 1];
int record[MAX + 1]; // 어디를 거쳐갔는지 기록할 배열
stack<int> s;
int n, k;

void print_record(int k)
{
	if (record[k] == -1) // 처음 위치를 찾으면
	{
		s.push(n); // 수빈이의 위치
		while (!s.empty())
		{
			cout << s.top() << ' '; // 스택을 비우며 모두 출력
			s.pop();
		}
		cout << '\n';
		return;
	}
	s.push(k); // 스택에 넣어 뒤집이 출력
	print_record(record[k]);
}

int main(void)
{
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	sec[n] = 0; // 수빈이의 위치에서 시작
	record[n] = -1; // 초기 위치 설정 0으로하면 0부터 시작하는 경우에 예외발생

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node - 1 >= 0)
		{
			if (check[node - 1] == false) // x - 1의 경우
			{
				q.push(node - 1);
				check[node - 1] = true;
				sec[node - 1] = sec[node] + 1;
				record[node - 1] = node; // 이전 위치를 기록한다.
			}
		}
		if (node + 1 <= MAX)
		{
			if (check[node + 1] == false) // x + 1의 경우
			{
				q.push(node + 1);
				check[node + 1] = true;
				sec[node + 1] = sec[node] + 1;
				record[node + 1] = node;
			}
		}
		if (node * 2 <= MAX)
		{
			if (check[node * 2] == false) // x * 2의 경우
			{
				q.push(node * 2);
				check[node * 2] = true;
				sec[node * 2] = sec[node] + 1;
				record[node * 2] = node;
			}
		}

	}

	cout << sec[k] << '\n';
	print_record(k);
}

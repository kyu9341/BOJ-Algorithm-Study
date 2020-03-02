#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
bool check[1501][1501];

struct stone
{
	int a, b, c;
};

bool ok = false;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stone s;
	cin >> s.a >> s.b >> s.c;
	
	queue<stone> q;
	q.push(s);
	check[s.a][s.b] = true;

	if ((s.a + s.b + s.c) % 3 != 0) // 모두 더해서 3으로 나누어 떨어지지 않으면 답을 구할 수 없음
	{
		cout << 0 << '\n';
		return 0;
	}

	while (!q.empty())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (a == b && b == c) // 모두 같은 수로 만든 경우
		{
			ok = true;
			break;
		}

		if (a > b && check[a - b][b * 2] == false && a - b > 0)
		{
			s.a = a - b;
			s.b = b * 2;
			s.c = c;
			q.push(s);
			check[a - b][b * 2] = true;
		}
		if (a < b && check[a * 2][b - a] == false && b - a > 0)
		{
			s.a = a * 2;
			s.b = b - a;
			s.c = c;
			q.push(s);
			check[a * 2][b - a] = true;
		}
		if (b > c && check[b - c][c * 2] == false && b - c > 0)
		{
			s.a = a;
			s.b = b - c;
			s.c = c * 2;
			q.push(s);
			check[b - c][c * 2] = true;
		}
		if (b < c && check[b * 2][c - b] == false && c - b > 0)
		{
			s.a = a;
			s.b = b * 2;
			s.c = c - b;
			q.push(s);
			check[b * 2][c - b] = true;
		}
		if (a > c && check[a - c][c * 2] == false && a - c > 0)
		{
			s.a = a - c;
			s.b = b;
			s.c = c * 2;
			q.push(s);
			check[a - c][c * 2] = true;
		}
		if (a < c && check[a * 2][c - a] == false && c - a > 0)
		{
			s.a = a * 2;
			s.b = b;
			s.c = c - a;
			q.push(s);
			check[a * 2][c - a] = true;
		}
	}

	if (ok) cout << 1 << '\n';
	else cout << 0 << '\n';
}
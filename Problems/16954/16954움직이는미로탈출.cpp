#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int a[8][8];
bool check[8][8];
int dx[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };

void printA() // 벽의 이동 확인
{
	cout << '\n';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void move() // 벽을 이동시키는 함수
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			if (i == 0)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			char input;
			cin >> input;
			if (input == '.') a[i][j] = 0; // . : 0, # : 1로 변환
			else a[i][j] = 1;
		}
	pair<int, int> start = make_pair(7, 0); // 시작 지점
	pair<int, int> end = make_pair(0, 7); // 목표 지점

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	q.push(start); // 가장 아래 칸

	while (!q.empty() || !nq.empty()) // 두 큐가 모두 비워질 때까지
	{
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (a[x][y] == 1) continue; // 캐릭터의 위치에 벽이 온 경우

			if (x == end.first && y == end.second) // 목표 지점에 도달한 경우
			{
				cout << 1 << '\n';
				return 0;
			}

			nq.push(make_pair(x, y)); // 제자리에 위치하는 경우

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) // 범위 내에서
				{
					if (a[nx][ny] == 0) // 다음 좌표가 빈 칸인 경우
					{
						nq.push(make_pair(nx, ny)); // 8방향 추가
					}
				}
			}

		} // 1초가 모두 끝난 후
		move(); // 벽 이동

		while (!nq.empty())
		{
			int x = nq.front().first;
			int y = nq.front().second;
			nq.pop();
			 
			if (a[x][y] == 1) continue;  // 캐릭터의 위치에 벽이 온 경우

			if (x == end.first && y == end.second) // 목표 지점에 도달한 경우
			{
				cout << 1 << '\n';
				return 0;
			}

			q.push(make_pair(x, y));

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
				{
					if (a[nx][ny] == 0) // 다음 좌표가 빈 칸인 경우
					{
						q.push(make_pair(nx, ny)); // 8방향 추가
					}
				}
			}

		} // 1초가 끝난 후
		move(); // 벽 이동

	}

	cout << 0 << '\n';
}
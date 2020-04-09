#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100001;
int a[MAX];

int tree[MAX * 4];

int init(int start, int end, int node) // 세그먼트 트리 구성
{	// 리프 노드에 a의 해당 인덱스의 수가 홀수라면 1, 짝수라면 0을 넣는다.
	if (start == end) return tree[node] = a[start] % 2 == 0 ? 0 : 1;
	int mid = (start + end) >> 1;
	// 홀수의 개수를 각 노드에 저장 (구간에서 홀수의 개수를 빼면 짝수의 개수)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);	
}

void update(int start, int end, int node, int index, int x, int value)
{	// 새로 입력된 수가 이전 수와 홀짝이 다른 경우만 실행
	if (start > index || index > end) return;
	if (x % 2 == 0) tree[node]--; // 짝수라면 홀수의 개수를 1감소
	else tree[node]++; // 홀수라면 1증가
	if (start == end)
	{	// 홀짝을 변경
		tree[node] = value;
		return;
	}
	int mid = (start + end) >> 1;

	update(start, mid, node * 2, index, x, value);
	update(mid + 1, end, node * 2 + 1, index, x, value);

}

int query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node]; // 홀수의 개수를 리턴
	int mid = (start + end) >> 1;
	
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	init(1, n, 1);

	cin >> m;
	while (m--)
	{
		int q, index, x, left, right;
		cin >> q;
		if (q == 1)
		{
			cin >> index >> x;
			// 홀짝이 다른 경우만 update
			if (a[index] % 2 == 0 && x % 2 == 1) update(1, n, 1, index, x, 1); // 홀수로 바뀐 경우
			else if (a[index] % 2 == 1 && x % 2 == 0) update(1, n, 1, index, x, 0); // 짝수로 바뀐 경우
			a[index] = x;
		}
		if (q == 2)
		{
			cin >> left >> right;
			int num = right - left + 1;
			// 구간에서 홀수의 개수를 빼면 짝수의 개수
			cout << num - query(1, n, 1, left, right) << '\n';
		}
		if (q == 3)
		{
			cin >> left >> right;
			// 홀수의 개수
			cout << query(1, n, 1, left, right) << '\n';
		}
	}

}
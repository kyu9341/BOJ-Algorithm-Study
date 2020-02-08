#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void next_permutation(vector<int> &a, int n)
{
	int i = n - 1; // 배열의 마지막 인덱스
	while (i >  0 && a[i] <= a[i - 1]) i--; // 내림차순이 되기 직전의 인덱스가 i가 됨.
	if (i == 0)
	{
		cout << -1; // 마지막 순열인 경우 -1
		return;
	}
	int j = n - 1;
	while (a[j] <= a[i - 1]) j--; // a[i] 보다 큰 가장 뒤쪽의 a[j]를 찾는다
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) // i 뒤를 오른차순으로 정렬
	{
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}

	for (int k = 0; k < n; k++)
		cout << a[k] << ' ';
	cout << '\n';
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	next_permutation(a, n);
}
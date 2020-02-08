#include<iostream>

using namespace std;
int a[10];
void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		go(index + 1, i + 1, n, m); // 다음 반복을 시작할 수를 지정
	}				// 항상 더 큰 수가 뒤에 옴
}

void go2(int index, int selected, int n, int m) // go2 : index라는 수를 결과에 포함할건지 말지를 결정
//  index : 실제 자연수 // selected : , 지금까지 선택한 수의 개수
{		
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > n) return; // index가 n보다 커지는 경우 리턴
	a[selected] = index;		// index를 결과에 추가하는 경우
	go2(index + 1, selected + 1, n, m);
	a[selected] = 0;			// index를 결과에 추가하지 않는 경우
	go2(index + 1, selected, n, m);
}


int main(void)
{
	int n, m;
	cin >> n >> m;

	go2(1, 0, n, m);
	// go(0, 1, n, m);
}
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int ans = 0;
deque<int> q;

void moveLeft(deque<int> &q) { // 2번 연산
	q.push_back(q.front());
	q.pop_front();
}
void moveRight(deque<int> &q) { // 3번 연산
	q.push_front(q.back());
	q.pop_back();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;


	vector<int> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i];

	for (int i = 1; i <= n; i++) 
		q.push_back(i);
	
	for (int i = 0; i < m; i++) {
		if (q.front() == v[i]) {
			q.pop_front();
		}
		else {
			int cntLeft = 0;
			deque<int> tmpDq = q;
			while (tmpDq.front() != v[i]) {
				moveLeft(tmpDq);
				cntLeft++;
			}
			tmpDq = q;
			int cntRight = 0;
			while (tmpDq.front() != v[i]) {
				moveRight(tmpDq);
				cntRight++;
			}

			if (cntLeft > cntRight) {
				ans += cntRight;
				while (q.front() != v[i]) {
					moveRight(q);
				}
				q.pop_front();
			}
			else {
				ans += cntLeft;
				while (q.front() != v[i]) {
					moveLeft(q);
				}
				q.pop_front();
			}
		}
	}

	cout << ans << '\n';


}
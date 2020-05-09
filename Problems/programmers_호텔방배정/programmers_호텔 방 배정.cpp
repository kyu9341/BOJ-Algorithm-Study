#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;
typedef long long ll;
map<ll, ll> m;

ll getParent(ll x) {
	if (m[x] == 0) return x; // ���� ���� ����ִ� ���
	return m[x] = getParent(m[x]); // ���� �� ���� ���ö� ���� Ȯ��
}


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++) {
		ll now = room_number[i];
		if (m[now] == 0) { // ���ϴ� ���ȣ ������ ������ ���
			answer.push_back(now);
			m[now] = getParent(now + 1);  // ���� ���� ��ġ ����
		}
		else { // �Ұ����� ���
			ll next = getParent(now); // ���� �̾����� �� ���� ��ȣ�� ã�´�.
			answer.push_back(next);
			m[next] = getParent(next + 1); // ã�� ���� ���� ���� ��ġ ����
		}
	}

	return answer;
}

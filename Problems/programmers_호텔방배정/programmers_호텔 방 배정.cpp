#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;
typedef long long ll;
map<ll, ll> m;

ll getParent(ll x) {
	if (m[x] == 0) return x; // 다음 방이 비어있는 경우
	return m[x] = getParent(m[x]); // 다음 빈 방이 나올때 까지 확인
}


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++) {
		ll now = room_number[i];
		if (m[now] == 0) { // 원하는 방번호 배정이 가능한 경우
			answer.push_back(now);
			m[now] = getParent(now + 1);  // 다음 방의 위치 저장
		}
		else { // 불가능한 경우
			ll next = getParent(now); // 다음 이어지는 빈 방의 번호를 찾는다.
			answer.push_back(next);
			m[next] = getParent(next + 1); // 찾은 방의 다음 방의 위치 저장
		}
	}

	return answer;
}

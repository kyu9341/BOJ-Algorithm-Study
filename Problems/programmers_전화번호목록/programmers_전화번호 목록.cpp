#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	// 문자열 정렬
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++) {
		// 정렬된 상태이므로 바로 다음 문자열이 현재 문자열로 시작하는지 확인
		if (phone_book[i].size() <= phone_book[i + 1].size()) {
			if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
				answer = false;
				break;
			}
		}
	}
	return answer;
}
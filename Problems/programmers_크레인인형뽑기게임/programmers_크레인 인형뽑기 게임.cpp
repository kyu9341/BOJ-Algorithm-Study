#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			int now = board[j][moves[i] - 1];  // 집게의 현재 위치
			if (now != 0) { // 인형을 만난 경우
				if (!s.empty() && s.top() == now) { // 바구니에 같은 인형이 연속으로 담기는 경우
					s.pop();
					answer += 2; // 2개 터짐
				}
				else {
					s.push(now);
				}
				board[j][moves[i] - 1] = 0; // 인형을 뽑은 자리는 0으로 채움
				break;
			}
		}
	}

	return answer;
}

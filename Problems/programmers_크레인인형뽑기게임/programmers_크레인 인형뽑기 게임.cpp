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
			int now = board[j][moves[i] - 1];  // ������ ���� ��ġ
			if (now != 0) { // ������ ���� ���
				if (!s.empty() && s.top() == now) { // �ٱ��Ͽ� ���� ������ �������� ���� ���
					s.pop();
					answer += 2; // 2�� ����
				}
				else {
					s.push(now);
				}
				board[j][moves[i] - 1] = 0; // ������ ���� �ڸ��� 0���� ä��
				break;
			}
		}
	}

	return answer;
}

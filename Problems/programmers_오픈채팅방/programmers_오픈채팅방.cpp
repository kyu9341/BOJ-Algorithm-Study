#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;
vector<bool> check;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	unordered_map<string, string> hash_map;
	vector<string> order;

	for (int i = 0; i < record.size(); i++) {
		string tmp = "";
		vector<string> v;
		for (int j = 0; j < record[i].size(); j++) {
			// ���� �Ǵ� ���ڿ��� ���������� ��� ����
			if (record[i][j] == ' ' || j == record[i].size() - 1) {
				if (j == record[i].size() - 1) v.push_back(tmp + record[i][j]);
				else v.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += record[i][j];
			}
		}
		if (v[0] == "Enter") { // Enter
			check.push_back(true);
			order.push_back(v[1]);
			hash_map[v[1]] = v[2]; // �ؽ��ʿ� uid�� Ű������ �ϰ� nickname�� ���������� ����

		}
		else if (v[0] == "Leave") { // Leave
			check.push_back(false);
			order.push_back(v[1]);
		}
		else { // Change
			hash_map[v[1]] = v[2];
		}
	}

	for (int i = 0; i < order.size(); i++) {
		string inout = check[i] == 1 ? "���� ���Խ��ϴ�." : "���� �������ϴ�.";
		answer.push_back(hash_map[order[i]] + inout);
	}

	return answer;
}

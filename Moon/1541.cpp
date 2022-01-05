// https://www.acmicpc.net/problem/1541
// Greedy_2 [01/05]

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<int> split(string input, vector<string> &op);

int main(void)
{
	int i;
	int j = 1;
	string equation;
	vector<string> operators;
	
	getline(cin, equation);	
	vector<int> splittedNums = split(equation, operators);
	
	int result = splittedNums[0];

	while (j < splittedNums.size())
	{
		// �����ڰ� - + �� ���, �ٽ� -�� ���� ������ +�� -�� ����� �� �ּڰ��� ����
		// - (10 + 20 + 30) -40 
		if (operators[j].compare("+")==0 && operators[j-1].compare("-")==0)
		{
			result -= splittedNums[j];

			// ������ ���Ұ� �ƴ��� Ȯ��
			while (operators[j].compare("+") == 0 && j < splittedNums.size() - 1)
			{
				j++;
				result -= splittedNums[j];
			}
		}
		else  // �̿��� ��쿡�� �����ڴ�� ������� ���
		{
			if (operators[j].compare("+") == 0) {
				result += splittedNums[j];
			}
			else if(operators[j].compare("-") == 0){
				result -= splittedNums[j];
			}
		}
		j++;
	}

	cout << result;
	
	return 0;
}

// string input�� numbers�� op ���Ϳ� ���� �и��ؼ� �����ϴ� �Լ�
vector<int> split(string input, vector<string> &op)
{
	vector<int> numbers;

	regex words_regex("[^\\s+-]+"); // ����ǥ����
	auto words_begin = sregex_iterator(input.begin(), input.end(), words_regex);
	auto words_end = sregex_iterator();
	for (sregex_iterator i = words_begin; i != words_end; ++i)
	{
		numbers.push_back(stoi((*i).str())); // ���ڵ� ����
	}

	regex ops_regex("[+-]+"); // ����ǥ����
	auto ops_begin = sregex_iterator(input.begin(), input.end(), ops_regex);
	auto ops_end = sregex_iterator();
	
	op.push_back("0"); // �����ڿ� ������ �ε��� ���߱� ���� ù ��° ���� �߰�
	for (sregex_iterator i = ops_begin; i != ops_end; ++i)
	{
		op.push_back((*i).str()); // �����ڵ� ����
	}

	return numbers;
}
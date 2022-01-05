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
		// 연산자가 - + 인 경우, 다시 -가 나올 때까지 +는 -로 계산할 때 최솟값을 가짐
		// - (10 + 20 + 30) -40 
		if (operators[j].compare("+")==0 && operators[j-1].compare("-")==0)
		{
			result -= splittedNums[j];

			// 마지막 원소가 아닌지 확인
			while (operators[j].compare("+") == 0 && j < splittedNums.size() - 1)
			{
				j++;
				result -= splittedNums[j];
			}
		}
		else  // 이외의 경우에는 연산자대로 순서대로 계산
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

// string input을 numbers와 op 벡터에 각각 분리해서 저장하는 함수
vector<int> split(string input, vector<string> &op)
{
	vector<int> numbers;

	regex words_regex("[^\\s+-]+"); // 정규표현식
	auto words_begin = sregex_iterator(input.begin(), input.end(), words_regex);
	auto words_end = sregex_iterator();
	for (sregex_iterator i = words_begin; i != words_end; ++i)
	{
		numbers.push_back(stoi((*i).str())); // 숫자들 저장
	}

	regex ops_regex("[+-]+"); // 정규표현식
	auto ops_begin = sregex_iterator(input.begin(), input.end(), ops_regex);
	auto ops_end = sregex_iterator();
	
	op.push_back("0"); // 연산자와 숫자의 인덱스 맞추기 위해 첫 번째 원소 추가
	for (sregex_iterator i = ops_begin; i != ops_end; ++i)
	{
		op.push_back((*i).str()); // 연산자들 저장
	}

	return numbers;
}
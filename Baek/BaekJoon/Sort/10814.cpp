#include <bits/stdc++.h>

using namespace std;

class Member{
public: 
	int index;
	int age;
	string name;

	bool operator <(Member &member) 
	{
		if (this->age == member.age)
		{
			return this->index < member.index;
		}
		else
		{
			return this->age < member.age;
		}
	}
};

int main()
{
	int number;
	cin >> number;

	int age;
	string name;

	vector<Member> memberVec;

	for (int i = 0; i < number; i++)
	{
		cin >> age >> name;
		Member member = { i, age, name };

		memberVec.push_back(member);
	}

	sort(memberVec.begin(), memberVec.end());

	for (int i = 0; i < number; i++)
	{
		printf("%d %s\n", memberVec[i].age, memberVec[i].name.c_str());
	}
}
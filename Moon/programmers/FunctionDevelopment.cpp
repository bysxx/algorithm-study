#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    unsigned int i = 0;
    int maximum; // 이전까지의 작업 기간의 최댓값
    int completedTasks = 1; // 베포될 수 있는 기능의 수

    vector<int> leftDays; // 각 Task를 완료하는데 필요한 작업 일수
    vector<int> answer;

    for (i = 0; i < progresses.size(); i++)
    {
        // 각 Task를 완료하는데 필요한 작업 일수 계산
        leftDays.push_back((int)ceil((100.0 - progresses[i]) / speeds[i]));
    }

    maximum = leftDays[0];

    for (i = 1; i < leftDays.size(); i++)
    {
        // 해당 Task의 작업 기간이 maximum보다 더 큰 경우
        if (leftDays[i] > maximum) 
        {
            answer.push_back(completedTasks); // 한번에 베포할 수 있는 Task의 수를 answer 벡터에 추가
            maximum = leftDays[i];
            completedTasks = 1; // 완료 Task는 1로 초기화
            if (i == leftDays.size() - 1) {
                answer.push_back(completedTasks);
            }
        }
        // 마지막 원소인 경우
        else if (i == leftDays.size() - 1)
        {
            completedTasks++;
            answer.push_back(completedTasks);
        }

        else // 해당 Task의 작업 기간이 이전까지의 작업 기간의 최댓값보다 더 작은 경우
        {
            completedTasks++;  // 같이 베포가 가능하므로 완료 Task + 1
        }
    }

    return answer;
}

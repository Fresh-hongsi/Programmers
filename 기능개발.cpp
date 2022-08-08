//deque

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> dq;


    for (int i = 0; i < progresses.size(); i++)
    {
        int temp = 0; //각 작업이 몇일 소요되는 지 저장할 값
        int difference = 100 - progresses[i]; //100% 도달까지 남은 잔량 계산
        
        if (difference % speeds[i] == 0) 
        {
            temp = difference / speeds[i];
        }
        else
        {
            temp = difference / speeds[i] + 1;
        }

        dq.push_back(temp); //덱에 각 작업이 완료되기까지의 날짜를 넣어줌
    }

    int cur = 0; //현재 참조하고 있는 인덱스

    while (!dq.empty())
    {
        for (int i = 0; i < dq.size(); i++) //하루가 지날 때마다 모든 작업의 작업 완료 날짜를 하루 줄여줌
        {
            dq[i] -= 1;
        }

        if (dq[cur] <= 0) //만약 가장 앞에 있는 요소가 작업이 완료되어있다면 -> 작업이 완료된 모든 연속적인 작업들을 pop해줌
        {
            int ans = 0; //한번에 처리할 수 있는 작업의 양

            while (!dq.empty() && dq[cur] <= 0) //덱이 비지 않을 때까지 작업을 다 처리하고 pop해줌
            {

                dq.pop_front();
                ans++; //한번에 처리할 수 있는 양 증가시켜줌
                
            }
            answer.push_back(ans); //정답 배열에 ans값 넣어줌
        }
    }
    return answer;
}

int main(void)
{
    vector<int> progresses;
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);

    vector<int> speeds;
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);

    vector<int> answer = solution(progresses, speeds);

    for (auto& i : answer)
    {
        cout << i << endl;
    }

}

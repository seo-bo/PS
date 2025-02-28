#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    startday--;
    int n = schedules.size();
    auto cal = [&] (int a)
    {
      return a / 100 * 60 + a % 100;  
    };
    for(int i =0; i<n;++i)
    {
        auto v = timelogs[i];
        int pivot = cal(schedules[i]) + 10;
        bool check = true;
        int x = startday;
        int idx = 0;
        for (int j =0; j< 7; ++j)
        {
            if(x == 5 || x == 6)
            {
                idx++;
                x = (x+1) % 7;
                continue;
            }
            if(cal(v[idx]) > pivot)
            {
                check = false;
                break;
            }
            idx++;
            x = (x+1) % 7;
        }
        if(check)
        {
            answer++;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, cnt = 1;
    map<string,int>mm;
    for(auto & i : want)
    {
        mm[i] = cnt++;
    }
    int day = discount.size();
    vector<vector<int>>prefix(cnt+1,vector<int>(day + 15,0));
    for(int i =1; i<=day;++i)
    {
        if(mm.find(discount[i-1]) == mm.end())
        {
            continue;
        }
        int pivot = mm[discount[i-1]];
        prefix[pivot][i]++;
        prefix[pivot][i + 10]--;
    }
    for(int i =1; i< cnt;++i)
    {
        for(int j = 1; j<=day;++j)
        {
            prefix[i][j] += prefix[i][j-1];
        }
    }
    for(int i =1; i<= day;++i)
    {
        bool check = true;
        for(int j =1; j <cnt; ++j)
        {
            if(prefix[j][i] < number[j-1])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            answer++;
        }
    }
    return answer;
}
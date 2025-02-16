#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(string s) { // 카카오는 왜 자꾸 되도 않는 파싱문제를 내는거임?
    vector<int> answer;
    int cnt = 0;
    map<int,int>mm;
    vector<vector<int>>ok;
    vector<int>temp;
    string tt;
    for(auto & i : s)
    {
        if(isdigit(i))
        {
            tt += i;
        }
        else if(i == '}')
        {
            if(!tt.empty())
            {
                temp.push_back(stoi(tt));
                tt = "";
            }
            if(!temp.empty())
            {
                ok.push_back(temp);
                temp.clear();
            }
        }
        else if(i == ',')
        {
            if(!tt.empty())
            {
                temp.push_back(stoi(tt));
                tt = "";
            }
        }
    }
    sort(ok.begin(),ok.end(), [&] (vector<int>&a, vector<int>&b)
         {
            return (int)a.size() < (int)b.size();
         });
    for(auto & i : ok)
    {
        for(auto & j : i)
        {
            if(mm.find(j) == mm.end())
            {
                mm[j] = cnt++;
                answer.push_back(j);
            }
        }
    }
    return answer;
}
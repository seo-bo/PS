#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i =l ;i<=r;++i)
    {
        string str = to_string(i);
        bool flag = true;
        for(auto & j : str)
        {
            if(j == '0' || j == '5')
            {
                continue;
            }
            flag = false;
            break;
        }
        if(flag)
        {
            answer.push_back(stoi(str));
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty())
    {
        answer = {-1};
    }
    return answer;
}
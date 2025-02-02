#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int>m;
    for(auto & i : keymap)
    {
        int len = i.size();
        for(int j = 1; j<=len;++j)
        {
            char pivot = i[j-1];
            if(m.find(pivot) == m.end())
            {
                m[pivot] = j;
            }
            else
            {
                m[pivot] = min(m[pivot],j);
            }
        }
    }
    for(auto & i : targets)
    {
        int temp = 0;
        for(auto & j : i)
        {
            if(m.find(j) == m.end())
            {
                temp = -1;
                break;
            }
            temp += m[j];
        }
        answer.push_back(temp);
    }
    return answer;
}
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int>mm;
    for(int i =0; i<(int)s.size();++i)
    {
        if(mm.find(s[i]) == mm.end())
        {
            answer.push_back(-1);
            mm[s[i]]=i;
        }
        else
        {
            answer.push_back(i - mm[s[i]]);
            mm[s[i]] = i;
        }
    }
    return answer;
}
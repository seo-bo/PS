#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int>mm;
    for(int i =0; i<name.size();++i)
    {
        mm[name[i]] = yearning[i];
    }
    for(auto & i : photo)
    {
        int temp = 0;
        for(auto & j : i)
        {
            temp += mm[j];
        }
        answer.push_back(temp);
    }
    return answer;
}
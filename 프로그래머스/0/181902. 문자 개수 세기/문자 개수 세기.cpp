#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    map<char,int>mm;
    for(char i = 'A'; i<='Z';++i)
    {
        mm[i] = 0;
    }
    for(char i = 'a'; i<='z';++i)
    {
        mm[i] = 0;
    }
    for(auto & i : my_string)
    {
        mm[i]++;
    }
    for(auto & [_,a]:mm)
    {
        answer.push_back(a);
    }
    return answer;
}
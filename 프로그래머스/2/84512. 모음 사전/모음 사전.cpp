#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string word) {
    int answer = 0;
    map<char,int>mm = {{'A',0},{'E',1},{'I',2},{'O',3},{'U',4}};
    vector<int>v = {781,156,31,6,1};
    for(int i =0; i<(int)word.size();++i)
    {
        answer += mm[word[i]] * v[i] + 1;
    }
    return answer;
}
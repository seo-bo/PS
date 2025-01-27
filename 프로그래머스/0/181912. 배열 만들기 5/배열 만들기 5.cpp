#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(auto & i : intStrs)
    {
        string str;
        for(int j = s; j < s + l;++j)
        {
            str += i[j];
        }
        int a = stoi(str);
        if(a > k)
        {
            answer.push_back(a);
        }
    }
    return answer;
}
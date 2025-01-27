#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string str;
    for(int i =0,cnt =1;i <(int)my_str.size();++i,cnt++)
    {
        str += my_str[i];
        if(cnt == n)
        {
            answer.push_back(str);
            str = "";
            cnt = 0;
        }
    }
    if(!str.empty())
    {
        answer.push_back(str);
    }
    return answer;
}
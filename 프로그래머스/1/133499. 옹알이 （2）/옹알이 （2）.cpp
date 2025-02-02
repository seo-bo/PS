#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    map<char,int>mm = {{'a',3},{'y',2},{'w',3},{'m',2}};
    map<char,string>ss = {{'a',"aya"},{'y',"ye"},{'w',"woo"},{'m',"ma"}};
    for(auto & i : babbling)
    {
        int idx = 0, len = i.size();
        bool flag = true;
        string pre = "";
        while(idx < len)
        {
            char pivot = i[idx];
            if(i.substr(idx,mm[pivot]) == ss[pivot] && pre != ss[pivot])
            {
                pre = ss[pivot];
                idx += mm[pivot];
            }
            else
            {
                flag = false;
                break;
            }
        }
        answer += (flag);
    }
    return answer;
}
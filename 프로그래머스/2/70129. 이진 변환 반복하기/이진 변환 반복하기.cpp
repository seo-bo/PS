#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    int i = 0;
    for(;s != "1" ;++i)
    {
        int len = 0;
        for(auto & j : s)
        {
            if(j == '1')
            {
                len++;
            }
            else
            {
                answer[1]++;
            }
        }
        bool flag = true;
        s = "";
        for(int j = 25; j>=0;--j)
        {
            if(len & (1<< j))
            {
                if(flag)
                {
                    flag = false;
                }
                s += '1';
            }
            else
            {
                if(!flag)
                {
                    s += '0';
                }
            }
        }
    }
    answer[0] = i;
    return answer;
}
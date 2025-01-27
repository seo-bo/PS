#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;
    map<string,string>mm = {{"zero","0"},{"one","1"},{"two","2"},{"three","3"},{"four","4"},{"five","5"},{"six","6"},{"seven","7"}
                            ,{"eight","8"},{"nine","9"}};
    string temp = "";
    string ans = "";
    for(auto & i : s)
    {
        if('a' <= i && i <= 'z')
        {
            temp += i;
            if(mm.find(temp) != mm.end())
            {
                ans += mm[temp];
                temp = "";   
            }
            continue;
        }
        ans += i;
    }
    ans += temp;
    return stoi(ans);
}
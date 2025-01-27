#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(string numbers) {
    map<string,char>mm ={{"zero",'0'},{"one",'1'},{"two",'2'},{"three",'3'},{"four",'4'},{"five",'5'},{"six",'6'},{"seven",'7'},{"eight",'8'},{"nine",'9'}};
    string str = "",ans = "";
    for(auto & i : numbers)
    {
        str += i;
        if(mm.find(str) != mm.end())
        {
            ans += mm[str];
            str = "";
        }
    }
    if(mm.find(str) != mm.end())
    {
        ans += mm[str];
    }
    return stoll(ans);
}
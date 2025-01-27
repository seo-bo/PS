#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string my_string) {
    string answer = "";
    set<char>s;
    for(auto & i : my_string)
    {
        if (s.find(i) != s.end())
        {
            continue;
        }
        answer += i;
        s.insert(i);
    }
    return answer;
}
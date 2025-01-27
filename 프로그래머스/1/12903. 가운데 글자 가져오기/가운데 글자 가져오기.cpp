#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    if(len & 1)
    {
        return answer += s[len/2];
    }
    else
    {
       answer += s[len/2-1];
       answer += s[len/ 2]; 
        return answer;
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    int n = pat.size(), m = myString.size(), idx = -1;
    for(int i =0; i<= m - n;++i)
    {
        if(myString.substr(i,n) == pat)
        {
            idx = i+n;
        }
    }
    for(int i =0; i<idx;++i)
    {
        answer += myString[i];
    }    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for(int i =0; i<(int)s.size();++i)
    {
        if(isalpha(s[i]))
        {
            s[i] = (idx & 1) ? tolower(s[i]) : toupper(s[i]);
            idx++;
        }
        else
        {
            idx = 0;
        }
    }
    return s;
}
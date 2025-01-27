#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    int len = overwrite_string.size();
    for(int i = 0; i<len;++i,++s)
    {
        answer[s] = overwrite_string[i];
    }
    return answer;
}
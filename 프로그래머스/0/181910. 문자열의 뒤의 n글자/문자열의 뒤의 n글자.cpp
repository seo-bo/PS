#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int len = my_string.size();
    for(int i = len - n; i <len;++i)
    {
        answer.push_back(my_string[i]);
    }
    return answer;
}
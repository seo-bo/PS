#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int a = str1.size(), b = str2.size();
    for(int i =0 ;i<a;++i)
    {
        answer += str1[i];
        answer += str2[i];
    }
    return answer;
}
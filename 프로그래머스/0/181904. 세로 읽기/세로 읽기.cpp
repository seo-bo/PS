#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    int n = my_string.size();
    for(int i =0; i<n;++i)
    {
        if(i % m == c-1)
        {
            answer += my_string[i];
        }
    }
    return answer;
}
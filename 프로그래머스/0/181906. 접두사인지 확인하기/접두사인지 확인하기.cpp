#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    int len = is_prefix.size();
    if(my_string.substr(0,len) == is_prefix)
    {
        return 1;
    }
    return answer;
}
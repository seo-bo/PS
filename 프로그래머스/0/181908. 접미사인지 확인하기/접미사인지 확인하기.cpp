#include <bits/stdc++.h>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    reverse(my_string.begin(),my_string.end());
    reverse(is_suffix.begin(),is_suffix.end());
    int len = is_suffix.size();
    if(my_string.substr(0,len) == is_suffix)
    {
        return 1;
    }
    return answer;
}
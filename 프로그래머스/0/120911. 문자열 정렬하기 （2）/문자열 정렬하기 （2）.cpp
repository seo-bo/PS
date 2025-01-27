#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    transform(my_string.begin(),my_string.end(),my_string.begin(), ::tolower);
    sort(my_string.begin(),my_string.end());
    return my_string;
}
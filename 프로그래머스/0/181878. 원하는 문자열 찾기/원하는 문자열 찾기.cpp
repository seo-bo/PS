#include <bits/stdc++.h>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    transform(myString.begin(),myString.end(),myString.begin(), ::tolower);
    transform(pat.begin(),pat.end(),pat.begin(), ::tolower);
    return (myString.find(pat) == string::npos) ? 0 : 1;
}
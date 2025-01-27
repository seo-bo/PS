#include<bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string aa = to_string(a), bb= to_string(b);
    return max(stoll(bb + aa),stoll(aa + bb));
}
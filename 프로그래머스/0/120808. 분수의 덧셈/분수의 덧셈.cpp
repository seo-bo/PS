#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n1, int d1, int n2, int d2) {
    vector<int> answer;
    int l = lcm(d1,d2);
    n1 *= l / d1, n2 *= l / d2;
    int n = n1 + n2, g = gcd(n,l);
    answer = {n / g, l / g};
    return answer;
}
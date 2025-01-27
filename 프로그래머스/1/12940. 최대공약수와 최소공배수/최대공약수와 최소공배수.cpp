#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer = {gcd(n,m),lcm(n,m)};
    return answer;
}
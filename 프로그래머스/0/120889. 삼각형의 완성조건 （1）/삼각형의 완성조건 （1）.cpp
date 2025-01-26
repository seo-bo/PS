#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(),sides.end());
    if(sides[2] < sides[0] + sides[1])
    {
        return 1;
    }
    return 2;
}
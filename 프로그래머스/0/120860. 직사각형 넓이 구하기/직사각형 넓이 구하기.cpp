#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    sort(dots.begin(),dots.end());
    return abs(dots[0][0] -dots[2][0]) * abs(dots[0][1] - dots[1][1]);
}
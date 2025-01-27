#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    int answer = 0;
    int a = date1[0] * 365 + date1[1] * 32 + date1[2];
    int b = date2[0] * 365 + date2[1] * 32 + date2[2];
    return a < b;
}
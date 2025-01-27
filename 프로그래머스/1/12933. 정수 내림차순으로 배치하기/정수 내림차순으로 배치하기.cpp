#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    sort(str.rbegin(),str.rend());
    return stoll(str);
}
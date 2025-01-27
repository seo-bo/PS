#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = 0;
    return (flag) ? (a+b) : (a-b);
}
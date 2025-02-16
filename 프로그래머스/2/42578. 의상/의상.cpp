#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int>mm;
    for(auto & i : clothes)
    {
        mm[i[1]]++;
    }
    for(auto & [a,b] : mm)
    {
        answer *= b + 1;
    }
    return answer - 1;
}
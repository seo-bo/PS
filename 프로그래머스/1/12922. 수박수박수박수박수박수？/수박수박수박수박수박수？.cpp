#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string>v={"수","박"};
    for(int i =0; i<n;++i)
    {
         answer += v[i & 1];
    }
    return answer;
}
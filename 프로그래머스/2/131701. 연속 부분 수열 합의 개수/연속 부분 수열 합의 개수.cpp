#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int>s;
    int n = elements.size() * 2;
    for(int i =0; i<n/2;++i)
    {
        elements.push_back(elements[i]);
    }
    for(int i =0; i<n;++i)
    {
        int temp = 0;
        for(int j =i, cnt = 0;j <n && cnt < n/2; ++j,++cnt)
        {
            temp += elements[j];
            s.insert(temp);
        }
    }
    return (int)s.size();
}
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main(void) 
{
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; ++i) 
    {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int end = 0;
    int size = v.size();
    for (int i = 0; i < size; ++i) 
    {
        if (v[i] > end + 1) 
        {
            break;
        }
        end += v[i];
    }
    cout << end + 1;
    return 0;
}

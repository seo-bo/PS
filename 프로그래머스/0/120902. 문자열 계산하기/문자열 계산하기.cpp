#include <bits/stdc++.h>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    stringstream ss(my_string);
    string str;
    deque<string>dq;
    while(ss >> str)
    {
        dq.push_back(str);
        if((int)dq.size() == 3)
        {
            int a = stoi(dq.front());
            dq.pop_front();
            string b = dq.front();
            dq.pop_front();
            int c = stoi(dq.front());
            dq.pop_front();
            if(b == "+")
            {
                dq.push_back(to_string(a + c));
            }
            else
            {
                dq.push_back(to_string(a - c));
            }
        }
    }
    return stoi(dq[0]);
}
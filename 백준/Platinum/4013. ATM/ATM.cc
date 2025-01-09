#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
// 코드 확인용
#define MAX_N 500'005

using namespace std;

vector<int> adj[MAX_N];
int N;

stack<int> stk;
bool finished[MAX_N];
int labels[MAX_N];
int label_cnt = 0;

int sccs[MAX_N];
int scc_cnt = 0;

vector<int> graph[MAX_N];
int in_degs[MAX_N];
int cash[MAX_N];

int dp[MAX_N];
int S;

int SCC(int cur) {
    label_cnt++;
    labels[cur] = label_cnt;
    int parent = label_cnt;
    stk.push(cur);

    for (int nxt : adj[cur]) {
        if (labels[nxt] == 0) {
            parent = min(parent, SCC(nxt));
        }
        else if (!finished[nxt]) {
            parent = min(parent, labels[nxt]);
        }
    }

    if (labels[cur] == parent) {
        scc_cnt++;
        while (!stk.empty()) {
            int p = stk.top();
            stk.pop();
            finished[p] = true;
            sccs[p] = scc_cnt;
            if (p == cur) {
                break;
            }
        }
    }

    return parent;
}

void MakeGraph(int cur) {
    for (int nxt : adj[cur]) {
        if (sccs[cur] != sccs[nxt]) {
            graph[sccs[cur]].push_back(sccs[nxt]);
            in_degs[sccs[nxt]]++;
        }
    }
}

void TopologySort() {
    queue<int> q;
    for (int i = 1; i <= scc_cnt; i++) {
        if (in_degs[i] == 0) {
            q.push(i);
        }
    }

    bool is_reachable[MAX_N] = { false, };
    is_reachable[sccs[S]] = true;

    dp[sccs[S]] = cash[sccs[S]];

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : graph[cur]) {
            if (is_reachable[cur]) {
                dp[nxt] = max(dp[nxt], dp[cur] + cash[nxt]);
                is_reachable[nxt] = true;
            }
            in_degs[nxt]--;
            if (in_degs[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        if (!finished[i]) {
            SCC(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        MakeGraph(i);
    }

    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        cash[sccs[i]] += c;
    }

    int P;
    cin >> S >> P;

    TopologySort();

    int ans = 0;

    while (P--) {
        int restaurant;
        cin >> restaurant;
        ans = max(ans, dp[sccs[restaurant]]);
    }

    cout << ans;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector <int> a[100008];
int trace[100008];

void dfs(int u)
{
    for (auto v: a[u])
    {
        if (!trace[v])
        {
            trace[v] = u;
            dfs(v);
        }
    }
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("DFS.inp", "r", stdin);
    // freopen("DFS.out", "w", stdout);

    memset(trace, 0, sizeof(trace));

    int n, m, s, t, u, v;

    cin >> n >> m;


    while(m--) cin >> u >> v,
               a[u].push_back(v);

    cin >> s >> t;
    
    for (int i = 1; i <= n; i++) 
        sort(a[i].begin(), a[i].end());

    stack <int> stk;
    stk.push(t);

    trace[s] = -1;
    dfs(s);

    while (t != s)
    {
        t = trace[t];
        stk.push(t);
    }

    cout << stk.size() << "\n";

    while (!stk.empty())
        cout << stk.top() << " ",
        stk.pop();

    return 0;
}
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, low[MAXN], number[MAXN], bridge = 0, cnt = 0;
vector<int> adj[MAXN];

void add(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}

void dfs(int u, int m)
{
    low[u] = number[u] = ++cnt;
    int cnt_2 = 0;

    for (auto v: adj[u])
    {
        if (v == m && !cnt_2)
        {
            cnt_2++;
            continue;
        }
        if (!number[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= number[v])
                bridge++;
        } 
        else 
            low[u] = min(low[u], number[v]);
    }   
}


int main()
{
    FIO ;

    freopen("BRIDTOUR.inp", "r", stdin);
    freopen("BRIDTOUR.out", "w", stdout);   

    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        add(adj, u, v);
    }
 
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        add(adj, u, v);
    }       

    dfs(1, 0);

    cout << bridge;
    return 0;
}
    
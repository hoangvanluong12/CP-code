#include <bits/stdc++.h>

using namespace std;

int trace[5008];
vector <int> a[5008];

void add(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}


void dfs(int u)
{
    for(auto v: a[u])
    {
        if (!trace[v])
        {
            trace[v] = 1;
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("COMNET.inp","r",stdin);
    // freopen("COMNET.out","w",stdout);
    
    int n, m;
    cin >> n >> m;
    
    int u, v;
    
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(a, u, v);    
    }


    dfs(1);
    
    int cnt = 0;

    vector <pair<int,int>> res;

    for(int i = 2; i <= n; ++i)
        if (trace[i] == 0)
        {
            trace[i] = 1;
            res.push_back({1, i});
            cnt++;
            dfs(i);
        }

    cout << cnt << "\n";

    for(int i = 0; i < cnt; ++i)
        cout << res[i].first << " " << res[i].second << "\n";

    return 0;
}
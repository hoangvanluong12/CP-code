#include <bits/stdc++.h>
#define FOR(a, b) for(int a = 1; a <= b; a++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m, k, escape[100008], min_time[100008]; 
queue<int> q;
vector<int> a[100008];

void bfs(int s)
{
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v: a[u])
            if(min_time[v] > min_time[u] + 1)
                q.push(v),
                min_time[v] = min_time[u] + 1;
    }
}

int main()
{
    FIO;
    freopen("EVA.inp", "r", stdin);
    freopen("EVA.out", "w", stdout);

    memset(min_time, 9000000, sizeof min_time);

    cin >> n >> k;
    int u, v;
    FOR(i, k)
        cin >> escape[i],
        min_time[escape[i]] = 0;

    cin >> m;
    FOR(i, m)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    FOR(i, k) bfs(escape[i]);
    FOR(i, n) cout << min_time[i] << " ";
    
    return 0;
}        
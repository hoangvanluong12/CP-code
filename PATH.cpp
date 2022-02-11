#include<bits/stdc++.h>
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define oo 100000000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, a[102][102], trace[102][102];
    cin >> n >> m >> k;

    int u, v, w;
    FOR(u, n) FOR(v, n)
        a[u][v] = (u == v) ? 0 : oo;

    while(m--)
    {
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
        trace[u][v] = v;
        trace[v][u] = u;
    }

    FOR(k, n) FOR(u, n) FOR(v, n)
        if(a[u][v] > a[u][k] + a[k][v])
        {
            a[u][v] = a[u][k] + a[k][v];
            trace[u][v] = trace[u][k];
        }

    int query;
    while(k--)
    {
        cin >> query >> u >> v;

        if(u == v)
        {
            if(!query)
                cout << 0;
            else
                cout << 2 << " " << u << " " << v;
            cout << "\n";
            continue;
        }

        if(query)
        {
            queue<int> q;
            q.push(u);
            while(u != v) { u = trace[u][v]; q.push(u); }
            cout << q.size();
            while(q.size()) { cout << " " << q.front(); q.pop(); }
        }
        else cout << a[u][v];
        cout << "\n";
    }
    return 0;
}

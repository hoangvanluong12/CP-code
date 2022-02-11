#include <bits/stdc++.h>

using namespace std;

void add(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
}

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;
    s -= 1;
    
    vector<int> a[100000];
    int u, v;

    for (int i = 0; i < m; i++) 
    {
        cin >> u >> v;
        add(a, u - 1, v - 1);
    }

    vector<int> trace(n, -1), d(n, 0);
    vector<bool> stable(n, false);
    queue<int> q;
    q.push(s);
    trace[s] = s;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int v: a[u]) 
        {
            if (trace[v] != u) 
            {
                if (trace[v] < 0)
                {
                    q.push(v);
                    trace[v] = u;
                    d[v] = d[u] + 1;
                    stable[v] = stable[u];
                } 
                else if (d[u] + 1 == d[v]) 
                    stable[v] = true;
            }
        }    
    }

    int res = 0;
    for (bool t: stable) 
        res += (t) ? 1 : 0;

    cout << res;

    return 0;
}
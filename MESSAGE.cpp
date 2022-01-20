#include <bits/stdc++.h>

using namespace std;

// Bai nay thuc chat la tim so thanh phan lien thong

vector<int> a[36];
int component = 0,
    visited[36];

void bfs(int s)
{
    ++component;

    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(q.size())
    {
        int u = q.front();
        q.pop();
        
        for(auto v: a[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int u = 1; u <= n; u++)
        if(!visited[u])
            bfs(u);
    
    cout << component;
    return 0;
}
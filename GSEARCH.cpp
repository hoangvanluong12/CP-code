#include <bits/stdc++.h>

using namespace std;

int components = 0,
    p[100008],
    trace[100008];

vector<int> a[100008];
bool visited[100008];

void bfs(int s)
{
    ++components;

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
                p[v] = u;
            }
        }
    }
}

void dfs(int s)
{ 
    for(auto v: a[s])
    {
        if(!trace[v])
        {
            trace[v] = s;
            dfs(v);
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, s, t;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {   
        cin >> u >> v;
        a[u].push_back(v);
        // a[v].push_back(u);
    }
    cin >> s >> t;

    // request 1:
    fill_n(visited, n + 2, false);
    fill_n(p, n + 2, -1);

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
            bfs(i);
    }

    cout << components << "\n";

    // request 2:
    int shortest_path = 0;
    for(int u = t; u != -1; u = p[u])
        shortest_path++;

    cout << shortest_path << "\n";


    // shortest_path with path

    // vector<int> path;
    // for(int u = t; u != -1; u = p[u])
    //     path.push_back(u);

    // reverse(path.begin(), path.end());
    // cout << path.size() << "\n";

    // request 3: 
    for(int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());

    fill_n(trace, n + 2, 0);
    
    vector<int> paths;

    trace[s] = -1;
    dfs(s);
    paths.push_back(t);
    
    while(t != s)
    {
        t = trace[t];
        paths.push_back(t);
    }

    reverse(paths.begin(), paths.end());

    cout << paths.size() << "\n";
    
    for(auto u: paths)
        cout << u << " ";

    return 0;
}   
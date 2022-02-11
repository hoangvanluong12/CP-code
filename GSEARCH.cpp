// #include <bits/stdc++.h>

// using namespace std;

// int components = 0,
//     p[100008],
//     trace[100008];

// vector<int> a[100008];
// bool visited[100008];

// void bfs(int s)
// {
//     ++components;

//     queue<int> q;
//     q.push(s);
//     visited[s] = true;

//     while(q.size())
//     {
//         int u = q.front();
//         q.pop();

//         for(auto v: a[u])
//         {
//             if(!visited[v])
//             {
//                 visited[v] = true;
//                 q.push(v);
//                 p[v] = u;
//             }
//         }
//     }
// }

// void dfs(int s)
// { 
//     for(auto v: a[s])
//     {
//         if(!trace[v])
//         {
//             trace[v] = s;
//             dfs(v);
//         }
//     }
    
// }


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m, u, v, s, t;

//     cin >> n >> m;

//     for(int i = 0; i < m; i++)
//     {   
//         cin >> u >> v;
//         a[u].push_back(v);
//         // a[v].push_back(u);
//     }
//     cin >> s >> t;

//     // request 1:
//     fill_n(visited, n + 2, false);
//     fill_n(p, n + 2, -1);

//     for(int i = 1; i <= n; i++)
//     {
//         if(!visited[i])
//             bfs(i);
//     }

//     cout << components << "\n";

//     // request 2:
//     int shortest_path = 0;
//     for(int u = t; u != -1; u = p[u])
//         shortest_path++;

//     cout << shortest_path << "\n";


//     // shortest_path with path

//     // vector<int> path;
//     // for(int u = t; u != -1; u = p[u])
//     //     path.push_back(u);

//     // reverse(path.begin(), path.end());
//     // cout << path.size() << "\n";

//     // request 3: 
//     for(int i = 1; i <= n; i++)
//         sort(a[i].begin(), a[i].end());

//     fill_n(trace, n + 2, 0);
    
//     vector<int> paths;

//     trace[s] = -1;
//     dfs(s);
//     paths.push_back(t);
    
//     while(t != s)
//     {
//         t = trace[t];
//         paths.push_back(t);
//     }

//     reverse(paths.begin(), paths.end());

//     cout << paths.size() << "\n";
    
//     for(auto u: paths)
//         cout << u << " ";

//     return 0;
// }   

#include <bits/stdc++.h>

using namespace std;

vector<int> a[100008], b[100008];
bool visited[100008];
int trace[100008],
    component = 0;


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

void bfs2(int s)
{
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while(q.size())
    {
        int u = q.front();
        q.pop();

        for(auto v: b[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                trace[v] = u;
                q.push(v);
            }
        }
    }
}

void dfs(int s)
{
    for(auto v: b[s])
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

    while(m--)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        b[u].push_back(v);
    }
    cin >> s >> t;

    // request 1
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            bfs(i);

    cout << component << "\n";

    // request 2

    fill_n(trace, n + 2, -1);

    fill_n(visited, n + 2, false);

    bfs2(s);

    vector<int> path1;
    int shortest = 0;
    if (trace[t] == -1) 
        cout << 0 <<"\n";
    else
    {
        shortest = 1;
        for(int v = t; trace[v] != -1; v = trace[v])
        {
            //path1.push_back(v);
            shortest++;
        }
    }
    //reverse(path1.begin(), path1.end());

    cout << shortest << "\n";

    //for(auto v: path1)
    //   cout << v << " ";

    // request 3

    for(int i = 1; i <= n; i++)
        sort(b[i].begin(), b[i].end());

    fill_n(trace, n + 2, 0);

    trace[s] = -1;
    dfs(s);
    
    if(!trace[t])
        cout << 0 << "\n";
    else 
    {
        vector<int> path2;
        while(t != s)
        {
            path2.push_back(t);
            t = trace[t];
        }
        path2.push_back(s);
        reverse(path2.begin(), path2.end());
        cout << path2.size() << "\n";
        for(auto v: path2)
            cout << v << " ";
    }
    
    return 0;
}
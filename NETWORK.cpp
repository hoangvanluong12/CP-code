#include <bits/stdc++.h>

using namespace std;

vector<int> a[108];
// int trace[108];
int visited[108];
void dfs(int s)
{
    for(auto v: a[s])
    {
        if(!visited[v])
        {
            visited[v] = true;
            // trace[v] = s;
            dfs(v);
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    fill_n(visited, n + 2, false);

    // trace[1] = -1;
    dfs(1);

    // if(visited[k])
    //     cout << "Yes";
    // else 
    //     cout << "No";

    cout << ( visited[k] ? "Yes" : "No");
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> a[100000], result;
int component = 0, res = 0;
bool visited[100000];

void bfs(int s)
{
    int cnt = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> node;
    node.push_back(s);
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
                node.push_back(v);

            }
        }
    }
    /*
    sort(node.begin(), node.end());
    cout << node.size() << "\n";
    for(int v: node)
        cout << v << " ";
    cout << "\n";
    */
    if(res < node.size())
    {
        res = node.size();

        result.clear();
        for(int v: node)
            result.push_back(v);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    fill_n(visited, n + 2, false);

    for(int s = 1; s <= n; s++)
    {
        if(!visited[s])
        {
            bfs(s);
        }
    }

    cout << result.size() << "\n";
    for(int v: result)
        cout << v << " ";

    return 0;
}

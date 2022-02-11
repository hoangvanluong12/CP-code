#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
vector<int> a[100008];
int low[100008], visited[100008], last_component[100008];

stack<int> st;

int component_count, res;

void visit(int u)
{
    low[u] = visited[u] = ++cnt;

    for (int i = 0, v; v = a[u][i]; i++)
    {
        if (visited[v]) 
            low[u] = min(low[u], visited[v]);
        else 
        { 
            st.push(u);
            visit(v); 
            
            low[u] = min(low[u], low[v]);
            
            if (low[v] >= visited[u]) 
            {
                int curr = 0;
                component_count++;
                do 
                {
                    v = st.top(); 
                    st.pop();
                    
                    if (last_component[v] < component_count)
                        curr++;
                    last_component[v] = max(last_component[v], component_count);
                } 
                while (u != v);

                res = max(res, curr);
            }
        }
    }
    st.push(u);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SAFENET.inp", "r", stdin);
    freopen("SAFENET.out", "w", stdout);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        a[i].push_back(0);


    for(int i = 1; i <= n; i++)
        if (!visited[i]) 
            visit(i);

    cout << max(res, 1);
    return 0;
}

#include <bits/stdc++.h>
const int MAX_LEN = 300008;
using namespace std; 

vector<int> a[MAX_LEN];
int low[MAX_LEN], number[MAX_LEN], cnt = 0;
vector<int> adjacent(MAX_LEN,1);

void dfs(int u, int p)
{
    int child = 0;
    low[u] = number[u] = ++cnt;

    for(int v: a[u]) 
    {
        if(p != v)
        {
            if(number[v]) 
                low[u] = min(low[u], number[v]);
            else
            {
                dfs(v, u);
                child++; 
                low[u] = min(low[u], low[v]);

                if(u == p)
                {
                    if(child > 2) 
                        adjacent[u] = child;
                }
                else if(low[v] >= number[u]) 
                {
                    adjacent[u]++;
                }    
            }
        }
    }    
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("CAPITAL.inp", "r", stdin);
    freopen("CAPITAL.out", "w", stdout);

    int n,m;
 
    cin >> n >> m;
    int u,v;    
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v); 
        a[v].push_back(u);
    }

    
    for(int i = 1;i <= n;i++) 
        if(!number[i]) 
            dfs(i,i); 

    int cmax = 0, c = 0;
    for(int i = 1;i <= n;i++) 
        if(adjacent[i]) 
        {
            if(adjacent[i] > cmax)
            {
                c = i;
                cmax = adjacent[i];
            }
        }

    cout << cmax << " " << c; 
    return 0;
}
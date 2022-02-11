#include <bits/stdc++.h>

using namespace std;

const int maxN = 300008;

vector<int> a[maxN];
int n, m, 
	number[maxN], low[maxN], parent[maxN], children[maxN], 
	cnt, articulation_point, bridge;
bool IsCut[maxN];

void add(vector<int> a[], int u, int v)
{
	a[u].push_back(v);
	a[v].push_back(u);
}

void DFS(int u)
{
	cnt++;
	number[u] = cnt;
    low[u] = n + 1;

	int v;

	for(long unsigned int i = 0; i < a[u].size(); ++i)
	{
		v = a[u][i];
		if (v == parent[u])
			continue;
		if (!parent[v])
		{
			children[u]++;
			parent[v] = u;
			DFS(v);
			low[u] = min(low[u], low[v]);
		}
		else	
			low[u] = min(low[u], number[v]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    freopen("DFSGRAPH.inp", "r", stdin);
    freopen("DFSGRAPH.out", "w", stdout);

	cin >> n >> m;

	int i, u, v;
    for(i = 1; i <= m; i++) 
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
        if (!parent[i]) 
        {
            parent[i] = -1;
            DFS(i);
        }
    
    for(v = 1; v <= n; v++) 
    {
        u = parent[v];
        if (u != -1 && low[v] >= number[v]) 
            bridge++;
    }

    for( v = 1; v <= n; v++)
        if (parent[v] != -1) 
        {
            u = parent[v];
            if (low[v] >= number[u])
                IsCut[u] = IsCut[u] || (parent[u] != -1) || (children[u] >= 2);
        }
    
    for(i = 1; i <= n; i++)
        if (IsCut[i]) 
            articulation_point++;

    cout << articulation_point << " " << bridge; 

	return 0;
}
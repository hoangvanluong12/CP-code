#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<int> a[1000008];
int visited[1000008];
void add(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
}

int main()
{
	FIO ;

	// freopen("BFS.inp", "r", stdin);
	// freopen("BFS.out", "w", stdout);

	int n, m;
    cin >> n >> m;

    int u, v;
    
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(a, u, v);
    }
	int s, t;
    cin >> s >> t;


	for(int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());

    
    visited[s] = 1;

    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v: a[u])
        {
            if(!visited[v])
            {
                visited[v] = visited[u] + 1;
				q.push(v);
            }
        }
    }

	cout << visited[t];


	return 0;
}
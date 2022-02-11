#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000008;
const int maxM = 1000008;


int adjacency[maxM], head[maxN], linker[maxM], number[maxN], low[maxN];
bool check[maxN];
stack<int> s;

vector<int> trace[100008];

int n, m, res, cnt, cnt_2 = 0;

void DFS(int u) 
{
    number[u] = ++cnt;
    low[u] = INT32_MAX;
    s.push(u);

    int i = head[u], v;

    while (i) 
	{
        v = adjacency[i];
        if (check[v]) 
		{
            if (number[v] > 0)
                low[u] = min(low[u], number[v]);
            else 
			{
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
        i = linker[i];
    }


    if (low[u] >= number[u]) 
	{
        res++;
        cnt_2++;
        do
		{
            v = s.top();
            check[v] = false;
            s.pop();
            trace[cnt_2].push_back(v);
        } while (v != u);
        reverse(trace[cnt_2].begin(), trace[cnt_2].end());
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("MNET.inp", "r", stdin);
    freopen("MNET.out", "w", stdout);


	cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++) 
	{
		cin >> u >> v;
        adjacency[i] = v;
        linker[i] = head[u];
        head[u] = i;
    }

    for(int i = 1; i <= n; i++)
        check[i] = true;

    cnt = 0;
    res = 0;

    for(int i = 1; i <= n; i++)
        if (check[i]) 
			DFS(i);
    
    cout << res << "\n";

    for(int i = 1; i <= cnt_2; i++)
    {
        for(int u: trace[i])
        {
            cout << u << " ";
        }
        cout << "\n";
    }


    return 0;
}

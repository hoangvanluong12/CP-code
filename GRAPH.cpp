//                         BFS

// #include <bits/stdc++.h>

// using namespace std;

// bool visited[50008];
// vector<int> a[50008];

// void BFS(int u) 
// {
// 	queue<int> q;
// 	visited[u] = false;

// 	q.push(u);
// 	while(!q.empty())
//     {
// 		int s = q.front();
// 		q.pop();
// 		for(int v: a[s]) 
//         {
// 			if(visited[v]) 
//             {
// 				q.push(v);
// 				visited[v] = false;
// 			}
// 		}
// 	}
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("GRAPH.inp", "r", stdin);
//     freopen("GRAPH.out", "w", stdout);

//     int n, m;
//     cin >> n >> m;

// 	int u, v;
// 	for(int i = 1;i <= m; i++) 
//     {
// 		cin >> u >> v;
// 		a[u].push_back(v);
// 		a[v].push_back(u);
// 	}

//     for(int i = 1; i <= n;i++)
//     {
// 		for(int i = 1;i <= n;i++)
//             visited[i] = true;

// 		visited[i] = false;

//         int res = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             if(visited[i])  
//             {
//                 res++;
//                 BFS(i);
//             }
//         }
// 		cout << res << "\n";
// 	}

// 	return 0;
// }

//                         DFS

// #include <bits/stdc++.h>

// using namespace std;

// int visited[500008], c;

// vector<int> a[500008];

// void dfs(int u, int cnt)
// {
//     visited[u] = cnt;

//     for(int v: a[u])
//     {
//         if(v == c || visited[v])
//             continue;
//         dfs(v, cnt);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("GRAPH.inp", "r", stdin);
//     freopen("GRAPH.out", "w", stdout);

//     int n, m, u, v, count;

//     cin >> n >> m;
//     for(int i = 0; i < m; i++)
//     {
//         cin >> u >> v;
//         a[u].push_back(v);
//         a[v].push_back(u);
//     }

//     for(int i = 1; i <= n; i++)
//     {
//         c = i;
//         for(int j = 1; j <= n; j++)
//             visited[j] = 0;

//         visited[c] = -1;
//         count = 0;
        
//         for(int t = 1; t <= n; t++)
//         {
//             if(!visited[t])
//             {
//                 count++;
//                 dfs(t, count);
//             }
//         }
//         cout << count << "\n";
//     }

//     return 0;
// }

//                      Tarjan

// #include <bits/stdc++.h>

// using namespace std;

// const int maxN = 50008;

// long long number[maxN] = {0}, low[maxN],
//           head[maxN] = {0}, joint[maxN] = {0}, adjacent[2 * maxN],
//           n, m, cnt = 0, children;

// struct edge
// {
//     long long u, v;
// };

// void tarjan(int u)
// {
//     int v;
//     number[u] = low[u] = ++cnt;

//     for(int i = head[u] + 1; i <= head[u + 1]; i++)
//     {
//         v = adjacent[i];
//         if(!number[v])
//         {
//             tarjan(v);
//             if(low[v] >= number[u])
//                 joint[u]++;
//             else   
//                 low[u] = min(low[u], low[v]);
//         }
//         else 
//             low[u] = min(low[u], number[v]);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // freopen("GRAPH.inp", "r", stdin);
//     // freopen("GRAPH.out", "w", stdout);

//     int n, m;
//     edge a[maxN];

//     cin >> n >> m;

//     for(int i = 1; i <= m; i++)
//     {
//         cin >> a[i].u >> a[i].v;
//         head[a[i].u]++;
//         head[a[i].v]++;
//     }

//     // for(long long int i = 1; i <= n; i++)
//     //     cout << head[i] << "\n";

//     for(int i = 2; i <= n; i++)
//         head[i] = head[i - 1] + head[i];
//     head[n + 1] = 2 * m;

//     for(int i = 1; i <= m; i++)
//     {
//         adjacent[head[a[i].u]] = a[i].v;
//         adjacent[head[a[i].v]] = a[i].u;
        
//         head[a[i].u]--;
//         head[a[i].v]--;
//     }

//     // for(long long int i = 1; i <= n; i++)
//     //     cout << head[i] << "\n";

//     children = 0;

//     for(int u = 1; u <= n; u++)
//     {
//         if(!number[u])
//         {   
//             children++;
//             tarjan(u);
//             joint[u]--;
//         }
//     }
//     cout << children << "\n";
//     for(int u = 1; u <= n; u++)
//         cout << joint[u] + children << "\n";

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

const int maxN = 50008;

long long number[maxN] = {0}, low[maxN],
          head[maxN] = {0}, joint[maxN] = {0}, adjacent[2 * maxN],
          n, m, cnt = 0;

bool visited[50008];
vector<int> aa[50008];

struct edge
{
    long long u, v;
};

void BFS(int u) 
{
	queue<int> q;
	visited[u] = false;

	q.push(u);
	while(!q.empty())
    {
		int s = q.front();
		q.pop();
		for(int v: aa[s]) 
        {
			if(!visited[v]) 
            {
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

void tarjan(int u)
{
    int v;
    number[u] = low[u] = ++cnt;

    for(int i = head[u] + 1; i <= head[u + 1]; i++)
    {
        v = adjacent[i];
        if(!number[v])
        {
            tarjan(v);
            if(low[v] >= number[u])
                joint[u]++;
            else   
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

    // freopen("GRAPH.inp", "r", stdin);
    // freopen("GRAPH.out", "w", stdout);

    int n, m;
    edge a[maxN];

    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v;
        head[a[i].u]++;
        head[a[i].v]++;
        aa[a[i].u].push_back(a[i].v);
		aa[a[i].v].push_back(a[i].u);
    }

    // for(long long int i = 1; i <= n; i++)
    //     cout << head[i] << "\n";

    for(int i = 2; i <= n; i++)
        head[i] = head[i - 1] + head[i];
    head[n + 1] = 2 * m;

    for(int i = 1; i <= m; i++)
    {
        adjacent[head[a[i].u]] = a[i].v;
        adjacent[head[a[i].v]] = a[i].u;
        
        head[a[i].u]--;
        head[a[i].v]--;
    }

    // for(long long int i = 1; i <= n; i++)
    //     cout << head[i] << "\n";


    for(int i = 1;i <= n;i++)
        visited[i] = false;

    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])  
        {
            res++;
            BFS(i);
        }
    }


    for(int u = 1; u <= n; u++)
    {
        if(!number[u])
        {   
            tarjan(u);
            joint[u]--;
        }
    }

    for(int u = 1; u <= n; u++)
        cout << joint[u] + res << "\n";

    return 0;
}


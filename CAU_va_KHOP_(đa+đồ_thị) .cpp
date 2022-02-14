#include <bits/stdc++.h>

using namespace std;

const int maxN = 100008;

vector<int> a[maxN];
vector<pair<int, int>> res;
int n, m,
	number[maxN], low[maxN], parent[maxN], children[maxN],
	cnt, articulation_point, bridge;
bool IsCut[maxN];

void DFS(int u, int p)
{
    int child = 0;
	cnt++;
	number[u] = cnt;
    low[u] = cnt;

	for(auto v: a[u])
	{
		//v = a[u][i];

		if(v != p)
        {
            if(number[v])
                low[u] = min(low[u], number[v]);

            else
            {
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                child++;
                if(low[v] >= number[v])
                {
                    res.push_back({u, v});
                    bridge++;
                }
                if(u == p)
                {
                    if(child >= 2)
                        IsCut[u] = true;
                }
                else if(low[v] >= number[u])
                    IsCut[u] = true;

            }
        }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("CUT.inp", "r", stdin);
    freopen("CUt.out", "w", stdout);

	cin >> n >> m;

	int i, u, v;
    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(i =1 ; i <= n; i++)
        if (number[i] == 0)
        {
            DFS(i, i);
        }

    vector<int> art_points;
    vector<pair<int, int>> bridges;

    for(auto i: res)
    {
        int cnt = 0;
        int u = i.first, v = i.second;
        for(auto j: a[u])
        {
            if(j == v && ++cnt > 1)
                break;
        }
        if(cnt == 1)
            bridges.push_back({u, v});
    }

    for(i = 1; i <= n; i++)
        if (IsCut[i])
        {
            articulation_point++;
            art_points.push_back(i);
        }

    cout << bridges.size() << " " << art_points.size() << "\n";

    for(auto res: bridges)
        cout << res.first << " " << res.second << "\n";

    for(auto v: art_points)
        cout << v << "\n";

	return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

// const int maxN = 10008;

// vector<int> a[maxN];
// int n, m,
// 	number[maxN], low[maxN], parent[maxN], children[maxN],
// 	cnt, articulation_point, bridge;
// bool IsCut[maxN];

// void DFS(int u)
// {
// 	cnt++;
// 	number[u] = cnt;
//     low[u] = n + 1;

// 	for(auto v: a[u])
// 	{
// 		//v = a[u][i];
// 		if (v == parent[u])
// 			continue;
// 		if (!parent[v])
// 		{
// 			children[u]++;
// 			parent[v] = u;
// 			DFS(v);
// 			low[u] = min(low[u], low[v]);
// 		}
// 		else
// 			low[u] = min(low[u], number[v]);
// 	}
// }

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> n >> m;

// 	int i, u, v;
//     for(i = 1; i <= m; i++)
//     {
//         cin >> u >> v;
//         a[u].push_back(v);
//         a[v].push_back(u);
//     }

//     for(i =1 ; i <= n; i++)
//         if (parent[i] == 0)
//         {
//             parent[i] = -1;
//             DFS(i);
//         }

//     vector<int> art_points;
//     vector<pair<int, int>> bridges;

//     for(v = 1 ; v <= n; v++)
//     {
//         u = parent[v];
//         if (u != -1 && low[v] >= number[v])
//         {
//             bridge++;
//             bridges.push_back(make_pair(u, v));
//         }
//     }

//     for( v = 1; v <= n; v++)
//         if (parent[v] != -1)
//         {
//             u = parent[v];
//             if (low[v] >= number[u])
//                 if(parent[u] != -1 || children[u] >= 2)
//                     IsCut[u] = true;
//         }

//     for(i = 1; i <= n; i++)
//         if (IsCut[i])
//         {
//             articulation_point++;
//             art_points.push_back(i);
//         }


//     cout << art_points.size() << " " << bridges.size();
//     /*
//     cout << bridge << " " << articulation_point << "\n";

//     for(auto res: bridges)
//         cout << res.first << " " << res.second << "\n";

//     for(auto v: art_points)
//         cout << v << "\n";
//     */
// 	return 0;
// }

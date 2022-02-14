

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

#include <bits/stdc++.h>

using namespace std;

int a[10000][10000], f[100000];

bool trace[10000];

int n, s, t, cnt;

void print(int d)
{
    for (int i = 0; i <= d; i++) 
        cout << f[i] << " ";
    
    cout << "\n";
    
    cnt ++;
}

void dfs(int k, int d)
{
   if (k == t)
   {
       print(d-1);
   }
       else for (int i = 1; i <= n; i++)
        if (trace[i] && a[k][i] == 1)
       {
           trace[i] = false;
           f[d] = i;
           dfs(i, d + 1);
           trace[i] = true;
       }
   }


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("AIR.inp", "r", stdin);
    freopen("AIR.out", "w", stdout);

    cin>> n >> s >> t;
    
    for (int i = 1; i <= n; i++)
    {    
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            trace[i] = true;
        }
    }

    cnt = 0;
    f[0] = s;
    trace[s] = false;

    dfs(s, 1);
    cout << cnt;

    return 0;
}

// #include <bits/stdc++.h>
// #define pb push_back
// #define ll long long

// using namespace std;
// const int maxn = 107;
// int n, s, t, a[maxn][maxn];
// bool vis[maxn];

// vector<vector<int>> ans;
// vector<int> path;

// void dfs(int u)
// {
//     path.pb(u);
//     if(u == t)
//     {
//         ans.pb(path);
//         path.pop_back();
//         return;
//     }

//     for(int v = 1; v <= n; v++)
//         if(!vis[v] && a[u][v])
//             {
//                 vis[v] = 1;
//                 dfs(v);
//                 vis[v] = 0;
//             }
//     path.pop_back();
// }

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	freopen("AIR.inp", "r", stdin);
// 	freopen("AIR.out", "w", stdout);

//     cin >> n >> s >> t;

//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= n; j++)
//             cin>>a[i][j];

//     vis[s] = 1;
//     dfs(s);

//     for(auto i: ans)
//     {
//         for(auto j: i)
//             cout<<j<<" ";
//         cout<<"\n";
//     }

//     cout << ans.size();
// 	return 0;
// }

#include "bits/stdc++.h"
#define ill pair<int, long long>
using namespace std;

const int maxN = 1e5 + 8;
const long long int oo = 1e18 + 8;

int n, m;
long long weight[maxN];

vector <ill> a[maxN];
vector<pair<int, int>> trace;
vector<int> trace2;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("MST.inp", "r", stdin);
    freopen("MST.out", "w", stdout);

    cin >> n >> m;

    int u, v;
    long long w;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    priority_queue<ill, vector<ill>, greater<ill>> q;


    for (int i = 1; i <= n; i++) 
        weight[i] = oo;

    weight[1] = 0;
    q.push({0, 1});

    long long int res = 0;

    while (!q.empty()) 
    {
        int curr = q.top().first; 
        int u = q.top().second;
        q.pop();

        if (curr != weight[u]) 
            continue;

        res += weight[u]; 
        weight[u] = -oo;

        for (auto &e: a[u]) 
        {
            int v = e.first; 
            int t = e.second;
            if (weight[v] > t) 
            {
                weight[v] = t;
                q.push({ weight[v], v});
                trace.push_back({u, v});

            }
        }
    }


    cout << res << "\n";

    for(auto e: trace)
        cout << e.first << " " << e.second << " ";

    return 0;
}


// #include "bits/stdc++.h"
// #define ill pair<int, long long>
// using namespace std;

// const int maxN = 1e5 + 8;
// const long long int oo = 1e18 + 8;

// int n, m;
// long long weight[maxN];

// vector <ill> a[maxN];
// map<int, int> trace;

// int main() 
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // freopen("MST.inp", "r", stdin);
//     // freopen("MST.out", "w", stdout);


//     cin >> n >> m;

//     int u, v;
//     long long w;
//     while(m--)
//     {
//         cin >> u >> v >> w;
//         a[u].push_back({v, w});
//         a[v].push_back({u, w});
//         trace
//     }

//     priority_queue<ill, vector<ill>, greater<ill>> q;


//     for (int i = 1; i <= n; i++) 
//         weight[i] = oo;

//     weight[1] = 0;
//     q.push({0, 1});

//     long long int res = 0;

//     pair<int, int>

//     while (!q.empty()) 
//     {
//         int curr = q.top().first; 
//         int u = q.top().second;
//         q.pop();

//         if (curr != weight[u]) 
//             continue;

//         trace.push_back(u);
//         res += weight[u]; 
//         weight[u] = -oo;

//         for (auto &e: a[u]) 
//         {
//             int v = e.first; 
//             int t = e.second;
//             if (weight[v] > t) 
//             {
//                 weight[v] = t;
//                 q.push({ weight[v], v});
//             }
//         }
//     }


//     cout << res << "\n";


//     // for(int e: trace)
//     //     cout << e << " ";

//     return 0;
// }
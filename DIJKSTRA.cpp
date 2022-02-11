#include <bits/stdc++.h>

#define ii pair<long long, long long>
 
using namespace std;
const long long int oo = 1e15;
const int maxN = 1e5 + 8; 
vector<ii> a[maxN];
int n, m, k;

ii min_path[maxN];

void dijkstra(int s) 
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for(int i = 1; i <= n; i++)
        min_path[i].first = oo;

    min_path[s].first = 0;
    
    pq.push(ii(0, s));
    
    while(pq.size()) 
    {
        long long u = pq.top().first;
        long long t = pq.top().second;
        pq.pop();

        if (u != min_path[t].first) 
            continue;

        for(int i = 0; i < a[t].size(); i++) 
        {
            long long db = a[t][i].first;
            long long b = a[t][i].second;
            if (min_path[b].first > u + db) 
            {
                min_path[b].first = u + db;
                pq.push(ii(min_path[b].first, b));
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("DIJKSTRA.INP", "r", stdin);
    freopen("DIJKSTRA.OUT", "w", stdout);

    cin >> n >> m;
    
    while(m--) 
    {
        int u, v;
        long long l;
        cin >> u >> v >> l;
        a[u].push_back(ii(l, v));
        a[v].push_back(ii(l, u));
    }

    dijkstra(1);

    cout << ( (min_path[n].first == oo) ? -1 : min_path[n].first);
 
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// const long long int oo = 1e18;
// typedef pair<int, int> ii;

// vector<ii> a[500008];
// int n, m;

// long long int d[500008];

// void dijkstra(int s) {
//     priority_queue<ii, vector<ii>, greater<ii>> pq;
//     for (int i = 1; i <= n; i++)
//         d[i] = oo;
//     d[s] = 0;
//     pq.push(ii(0, 1));

//     while (pq.size()) {
//         int u = pq.top().second;
//         int du = pq.top().first;
//         pq.pop();
//         if (du != d[u])
//             continue;

//         for (int i = 0; i < a[u].size(); i++) {
//             int v = a[u][i].second;
//             int uv = a[u][i].first;
//             if (d[v] > du + uv) 
//             {
//                 d[v] = du + uv;
//                 pq.push(ii(d[v], v));
//             }
//         }
//     }
// }

// int main() {
//     int p, q, m;
//     long long w;
//     scanf("%d%d", &n, &m);
//     while (m--) {
//         scanf("%d%d%d", &p, &q, &w);
//         a[p].push_back(ii(w, q));
//         a[q].push_back(ii(w, p));
//     }
    
//     dijkstra(1);
    
    
//     cout << (d[n] == oo ? -1 : d[n]);

// }
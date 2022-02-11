#include <bits/stdc++.h>

#define ii pair<long long, long long>
 
using namespace std;
const int oo = 1e9;
vector<ii> a[10008];
int n, m, k;

ii min_path[10008];

void dijkstra(int s) 
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for(int i = 1; i <= n; i++)
        min_path[i].first = oo;

    min_path[s].first = 0;
    min_path[s].second = 1;
    
    pq.push(ii(0, s));
    
    while(!pq.empty()) 
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
            
            if (min_path[b].first == u + db)
                min_path[b].second += min_path[t].second;
            
            else if (min_path[b].first > u + db) 
            {
                min_path[b].first = u + db;
                min_path[b].second = min_path[t].second;
                pq.push(ii(min_path[b].first, b));
            }
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SCHOOL.INP", "r", stdin);
    freopen("SCHOOL.OUT", "w", stdout);

    cin >> n >> m;
    
    while(m--) 
    {
        int k, u, v, l;
        cin >> k >> u >> v >> l;
        a[u].push_back(ii(l, v));
        if (k == 2) 
            a[v].push_back(ii(l, u));
    }

    dijkstra(1);

    cout << min_path[n].first << " " << min_path[n].second;
    return 0;
}
#include <queue>
#include <stack>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#define ii pair<long, long>
#define ll long long

using namespace std;

const long long int oo = 1e18;
ll len[100008];
vector <ii> a[100008];

ll n, m, k, s, t;
void dijkstra(ll u, ll v)
{
    priority_queue <ii, vector<ii>, greater<ii>> pq; 
	// memset(len, oo, sizeof len);

    for(int i = 0; i <= n + 8; i++)
        len[i] = oo;

    len[u] = 0;
    pq.push({0, u});
	
    while (pq.size()) 
    {
		int u = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
	
    	for (auto i: a[u]) 
        {
			int w = i.second;
			int v = i.first;
			if (weight != len[u])
				continue;
			if (len[v] > weight + w) 
            {
				len[v] = weight + w;
				pq.push({len[v], v});
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("TRANSNET.inp", "r", stdin);
    // freopen("TRANSNET.out", "w", stdout);

    cin >> n >> m >> k >> s >> t;
    ll u, v, w;
    
    for (int i = 0; i < m; ++i) 
    {
    	cin >> u >> v >> w;
    	a[u].push_back({v, w});
    }

    long long int res = oo;
    for(int i = 0; i < k; i++)
    {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        
        dijkstra(s, t);
        res = min(res, len[t]);

        // cout << res << "\n";
        a[u].pop_back();
        a[v].pop_back();
    }

    cout << res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define nmax 1001
#define mmax 5001
struct pii 
{
    int u, v;
} a[mmax];

int n, m, head[nmax], link[mmax];
pii trace[nmax][nmax];

void printPath() 
{
    vector<int> p1, p2;
    pii x = { 1, n };
    while (true) 
    {
        p1.push_back(x.u);
        p2.push_back(x.v);
        if (x.u == x.v)
            break;
        x = trace[x.u][x.v];
    }
    
    cout << p1.size() - 1 << '\n';
    for (int u : p1) 
        cout << u << ' ';
    cout << '\n';
    for (int u : p2) 
        cout << u << ' ';
    exit(0);
}

void BFS() 
{
    memset(trace, 0, sizeof trace);
    queue<pii> q;

    for (int u = 1; u <= n; u++) 
    {
        q.push({ u, u });
        trace[u][u] = { -1, -1 };
    }
    while (q.size()) 
    {
        pii x = q.front();
        q.pop();
        if (x.u == 1 && x.v == n)
            printPath();
        
        for (int i = head[x.u]; i; i = link[i])
        {
            for (int j = head[x.v]; j; j = link[j]) 
            {
                int u = a[i].u, v = a[j].u;
                if (!trace[u][v].u) 
                {
                    trace[u][v] = x;
                    q.push({ u, v });
                }
            }
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) 
        cin >> a[i].u >> a[i].v;
    memset(head, 0, sizeof head);

    for (int i = 1; i <= m; i++) 
    {
        link[i] = head[a[i].v];
        head[a[i].v] = i;
    }

    BFS();

    cout << -1;
}
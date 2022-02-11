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
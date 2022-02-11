#include <bits/stdc++.h>

using namespace std;

int low[100008], number[100008], n, m, cnt = 0;
vector <int> a[100008];
stack <int> st;
long long res = 0;

void dfs(int u)
{
    low[u] = number[u] = ++cnt;
    st.push(u);

    for (auto v: a[u])
    {
        if (number[v])
            low[u] = min(low[u], number[v]);
        else 
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == number[u])
    {
        long long node = 0, cnt_2 = 0, v;
        map <long long, long long> s;
        stack <long long> st2;
        do 
        {
            v = st.top();
            st.pop();
            s[v]++;
            node++;
            st2.push(v);
            low[v] = number[v] = 1e9; 
        } while (v != u);

        while (st2.size())
        {
            long long v = st2.top();
            st2.pop();
            for (auto i : a[v])
                if (s[i]) 
                    cnt_2++;
        }

        if (node > 2) 
            res += node * (node - 1) - cnt_2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("NEWROADS.inp", "r", stdin);
    freopen("NEWROADS.out", "w", stdout);
	
    cin >> n >> m;

	int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!number[i]) 
			dfs(i);
    
	cout << res;
	return 0;
}
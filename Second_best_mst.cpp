#include <bits/stdc++.h>

using namespace std;

int parent[100005];

vector<int> present;

int edg;

struct edge
{
	int src, dest, weight;
} edges[100005];

bool cmp(edge x, edge y)
{
	return x.weight < y.weight;
}


void initialise(int n)
{

	for (int i = 1; i <= n; i++)
		parent[i] = i;
}

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

int union1(int i, int sum)
{
	int x, y;
	x = find(edges[i].src);
	y = find(edges[i].dest);
	if (x != y) {


		parent[x] = y;

		present.push_back(i);


		sum += edges[i].weight;
	}
	return sum;
}

int union2(int i, int sum)
{
	int x, y;
	x = find(edges[i].src);
	y = find(edges[i].dest);
	if (x != y) {

		parent[x] = y;

		sum += edges[i].weight;
		edg++;
	}
	return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("MANGDIEN.inp", "r", stdin);
    //freopen("MANGDIEN.out", "w", stdout);

	int n, m;
	cin >> n >> m;


	initialise(n);


    int u, v, w;

	for (int i = 0; i < m; i++)
	{
	    cin >> u >> v >> w;
		edges[i].src = u;
		edges[i].dest = v;
		edges[i].weight = w;
	}

	sort(edges, edges + m, cmp);

	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum = union1(i, sum);
	}

    int mst = sum;

	int sec_best_mst = INT_MAX;

	sum = 0;
	int j;
	for (j = 0; j < present.size(); j++)
	{
		initialise(n);
		edg = 0;
		for (int i = 0; i < m; i++) {

			if (i == present[j])
				continue;
			sum = union2(i, sum);
		}

		if (edg != n - 1) {
			sum = 0;
			continue;
		}


		if (sec_best_mst > sum)
			sec_best_mst = sum;
		sum = 0;
	}
	cout << mst << " " << sec_best_mst;
	return 0;
}

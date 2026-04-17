#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
vector<vector<int>> p;
bool check[110000];
int dist[110000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k >> m;
	p.resize(n + m + 1);
	
	for (int i = n + 1; i < m + n + 1; i++) {
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			p[i].push_back(x);
			p[x].push_back(i);
		}
	}
	queue<int> q;
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == n) break;
		for (int next : p[now]) {
			if (!check[next]) {
				check[next] = true;
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
	if (n != 1 && dist[n] == 0) cout << -1;
	else cout << dist[n] / 2 + 1;
}
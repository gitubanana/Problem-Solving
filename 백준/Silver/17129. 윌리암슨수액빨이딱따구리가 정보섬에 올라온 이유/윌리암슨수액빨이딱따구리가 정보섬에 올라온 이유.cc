#include <iostream>
#pragma warning (disable:4996)
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int map[3001][3001];
int visit[3001][3001];

int dx[4] = {1,-1,0,0};
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	pair<int, int> cur;

	q.push(pair<int, int>(x, y));
	visit[x][y] = 1;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < 4;i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] != 1 && visit[nx][ny] == 0) {
					visit[nx][ny] = visit[cur.first][cur.second] + 1;
					q.push(pair<int, int>(nx, ny));
				}
			}
		}
	}
}


int main()
{
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);

	cin >> n >> m;

	int startx=0, starty=0;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0; j < m; j++) {

			map[i][j] = tmp[j] - '0';

			if (map[i][j] == 2) {
				startx = i;
				starty = j;
			}

		}
	}

	bfs(startx, starty);
	
	int minN = 100000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
				if (visit[i][j] == 0) continue;
				minN = min(minN, visit[i][j]);
			}
		}
	}

	if (minN == 100000) {
		cout << "NIE";
	}
	else {
		cout << "TAK\n";
		cout << minN-1;
	}
}
#include<iostream>
#include<algorithm>
using namespace std;

#define INF 1000000000 // 10억

int ans, cnt;
int n, m, r, a, b, l;
int local[101];
int dist[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i != j) dist[i][j] = INF;
		}

	// 지역별 아이템 갯수 저장
	for (int i = 1; i <= n; i++) cin >> local[i];

	// 길과 길 사이의 거리 저장
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	// 플루이드 와샬
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}

	for (int i = 1; i <= n; i++)
	{
		cnt = local[i]; // 시작지점 아이템 파밍
		for (int j = 0; j <= n; j++)
		{
			// 수색가능 범위 아이템 파밍
			if (i != j && dist[i][j] <= m) cnt += local[j];
		}
		ans = max(ans, cnt);
	}
		
	cout << ans;

}
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX = 100;
int		  ans;
//토마토를 가지고 있는 3차원 배열
int	tomato[MAX][MAX][MAX];
//익은 토마토의 행[0], 열[1]을 가지고 있는 배열
int	ripen[MAX * MAX * MAX][3];
int	ripen_cnt;
//앞, 뒤, 오른쪽, 왼쪽, 위, 아래
int	dx[6] = {0, 0, 1, -1, 0, 0};
int	dy[6] = {1, -1, 0, 0, 0, 0};
int	dz[6] = {0, 0, 0, 0, 1, -1};

void	bfs(int col, int row, int height)
{
	queue<tuple<int, int, int>>	queue;
	tuple<int, int, int>		cur_pos;
	int							i, cur_x, cur_y, cur_z;

	//익은 토마토의 높이, 행, 열을 큐에 넣는다
	for (i = 0; i < ripen_cnt; i++)
		queue.push(make_tuple(ripen[i][0], ripen[i][1], ripen[i][2]));
	while (!queue.empty())
	{
		for (i = 0; i < 6; i++)
		{
			cur_z = get<0>(queue.front()) + dz[i];
			cur_y = get<1>(queue.front()) + dy[i];
			cur_x = get<2>(queue.front()) + dx[i];
			if (!(0 <= cur_z && cur_z < height)
				|| !(0 <= cur_y && cur_y < row)
				|| !(0 <= cur_x && cur_x < col)
				|| tomato[cur_z][cur_y][cur_x] != 0)
				continue ;
			queue.push(make_tuple(cur_z, cur_y, cur_x));
			tomato[cur_z][cur_y][cur_x] +=
				tomato[get<0>(queue.front())][get<1>(queue.front())][get<2>(queue.front())] + 1;
			ans = max(ans, tomato[cur_z][cur_y][cur_x]);
		}
		queue.pop();
	}
}

int main(void)
{
	int	z, y, x;
	int	col, row, height;

	scanf("%d %d %d", &col, &row, &height);
	for (z = 0; z < height; z++)
	{
		for (y = 0; y < row; y++)
		{
			for (x = 0; x < col; x++)
			{
				scanf("%d", &tomato[z][y][x]);
				if (tomato[z][y][x] == 1)
				{
					ripen[ripen_cnt][0] = z;
					ripen[ripen_cnt][1] = y;
					ripen[ripen_cnt++][2] = x;
				}
			}
		}
	}
	bfs(col, row, height);
	for (z = 0; z < height; z++)
		for (y = 0; y < row; y++)
			for (x = 0; x < col; x++)
				if (tomato[z][y][x] == 0)
					return (printf("-1") == 0);
	printf("%d", ans - (ans > 0));
	return (0);
}
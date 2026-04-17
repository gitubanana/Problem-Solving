#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
int		  ans;
//토마토를 가지고 있는 2차원 배열
int	tomato[MAX][MAX];
//익은 토마토의 행[0], 열[1]을 가지고 있는 배열
int	ripen[MAX * MAX][2];
int	ripen_cnt;
//위, 아래, 오른쪽, 왼쪽
int	dx[4] = {0, 0, 1, -1};
int	dy[4] = {1, -1, 0, 0};

void	bfs(int width, int height)
{
	int						i;
	pair<int, int>			cur_pos;
	int						cur_x, cur_y;
	queue<pair<int, int> >	queue;

	//익은 토마토의 행, 열을 큐에 넣는다.
	for (i = 0; i < ripen_cnt; i++)
		queue.push({ripen[i][0], ripen[i][1]});
	while (!queue.empty())
	{
		cur_pos = queue.front();
		for (i = 0; i < 4; i++)
		{
			cur_y = cur_pos.first + dy[i];
			cur_x = cur_pos.second + dx[i];
			if (!(0 <= cur_y && cur_y < height)
				|| !(0 <= cur_x && cur_x < width)
				|| tomato[cur_y][cur_x] != 0)
				continue ;
			queue.push({cur_y, cur_x});
			tomato[cur_y][cur_x] += tomato[cur_pos.first][cur_pos.second] + 1;
			ans = max(ans, tomato[cur_y][cur_x]);
		}
		queue.pop();
	}
}

int main(void)
{
	int	i, j;
	int	width, height;

	scanf("%d %d", &width, &height);
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1)
			{
				ripen[ripen_cnt][0] = i;
				ripen[ripen_cnt++][1] = j;
			}
		}
	}
	bfs(width, height);
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			if (tomato[i][j] == 0)
				return (printf("-1") == 0);
	printf("%d", ans - (ans > 0));
	return (0);
}
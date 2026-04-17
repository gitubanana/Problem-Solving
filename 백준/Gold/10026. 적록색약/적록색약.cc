#include <iostream>
#include <cstring>

using namespace std;

const int	MAX = 100;

char	sketch[MAX][MAX + 1];
int		visited[MAX][MAX];
int		n;

//위, 아래, 오른쪽, 왼쪽
int	dy[4] = {1, -1, 0, 0};
int	dx[4] = {0, 0, 1, -1};

void	make_red_to_green(void)
{
	int	i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (sketch[i][j] == 'R')
				sketch[i][j] = 'G';
		}
	}
}

void	dfs(int y, int x, char cur_color)
{
	if (!(0 <= y && y < n) || !(0 <= x && x < n)
		|| sketch[y][x] != cur_color || visited[y][x] == 1)
		return ;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i], cur_color);
}

int main(void)
{
	int	i, j;
	int	normal, red_green_blind;

	//save inputs
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", sketch[i]);

	//get normal section
	normal = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (visited[i][j] == 0)
				dfs(i, j, sketch[i][j]), normal++;

	/* make red into green */
	make_red_to_green();
	memset(visited, 0, sizeof(visited));

	//get red_green_blind section
	red_green_blind = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (visited[i][j] == 0)
				dfs(i, j, sketch[i][j]), red_green_blind++;

	printf("%d %d", normal, red_green_blind);
	return (0);
}
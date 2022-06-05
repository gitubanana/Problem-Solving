#include <stdio.h>

void	print_ans(int v_cnt);
void	search(int v, int v_cnt, int *p_cnt);

int	matrix[101][101];
int	visited[101];

int	main(void)
{
	int	a;
	int	b;
	int	v_cnt;
	int	e_cnt;

	scanf("%d %d", &v_cnt, &e_cnt);
	while (e_cnt--)
	{
		scanf("%d %d", &a, &b);
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	print_ans(v_cnt);
}

void	print_ans(int v_cnt)
{
	int	cnt;

	cnt = 0;
	visited[1] = 1;
	search(1, v_cnt, &cnt);
	printf("%d", cnt);
}

void	search(int v, int v_cnt, int *p_cnt)
{
	int	i;

	for (i = 1; i <= v_cnt; i++)
	{
		if (matrix[v][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			(*p_cnt)++;
			search(i, v_cnt, p_cnt);
		}
	}
}

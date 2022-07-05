#include <stdio.h>

void	back_tracking(int v, int n, int depth, int m);

int	arr[8];
int	visited[9];

int	main(void)
{
	int	n, m;

	scanf("%d %d", &n, &m);
	back_tracking(1, n, 0, m);
	return (0);
}

void	back_tracking(int v, int n, int depth, int m)
{
	int	i;

	if (depth == m)
	{
		i = 0;
		while (i < m)
			printf("%d ", arr[i++]);
		printf("\n");
		return ;
	}
	i = v - 1;
	while (++i <= n)
	{
		if (visited[i] == 0)
		{
			arr[depth] = i;
			visited[i] = 1;
			back_tracking(i, n, depth, m);
			visited[i] = 0;
		}
	}
}

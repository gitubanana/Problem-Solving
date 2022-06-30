#include <stdio.h>

void	print_ans(int n);

int	main(void)
{
	int	i;
	int	n, m, a, b;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d" &a, &b);
		if (a > b)
			arr[b][a] = 1;
		else
			arr[a][b] = 1;
	}
	print_ans(n);
	return (0);
}

void	print_ans(int n)
{
	int	cnt;
	int	i, j, k;

	cnt = 0;
	for (i = 1; i <= n - 2; i++)
		for (j = i + 1; j <= n - 1; j++)
			for (k = j + 1; k <= n; k++)
				if (!arr[i][j] && !arr[i][k] && !arr[j][k])
					cnt++;
	printf("%d", cnt);
}

#include <stdio.h>

void	dfs(int idx, int size);

int	arr[100001];

int	main(void)
{
	int	i, n;
	int	cnt, cur;

	cnt = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &cur);

	dfs(cur - 1, n);
	for (i = 0; i < n; i++)
		if (arr[i] == 0)
			cnt++;

	printf("%d", cnt);
	return (0);
}

void	dfs(int idx, int size)
{
	if (idx < 0 || idx > size - 1 || arr[idx] == 0)
		return ;

	dfs(idx + arr[idx], size);
	dfs(idx - arr[idx], size);
	arr[idx] = 0;
}

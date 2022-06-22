#include <stdio.h>
#include <stdlib.h>
#define HOME 49

void	scan_map(int size);
int	cmp(const void *a, const void *b);
void	dfs(int i, int j, int size, int *cnt);

int	arr[350];
char	map[25][26];

int	main(void)
{
	int	n;
	int	i, j;
	int	cnt, idx;

	idx = cnt = 0;
	scanf("%d", &n);
	scan_map(n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (map[i][j] == HOME)
			{
				cnt++;
				dfs(i, j, n, &arr[idx++]);
			}
		}
	}
	printf("%d\n", cnt);
	qsort(arr, idx, sizeof(int), cmp);
	for (i = 0; i < idx; i++)
		printf("%d\n", arr[i]);
	return (0);
}

int	cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void	scan_map(int size)
{
	int	i;

	for (i = 0; i < size; i++)
		scanf("%s", map[i]);
}

void	dfs(int i, int j, int size, int *cnt)
{
	//I came here
	(*cnt)++;
	map[i][j] = '0';

	//up
	if (i - 1 >= 0 && map[i - 1][j] == HOME)
		dfs(i - 1, j, size, cnt);

	//down
	if (i + 1 <= size - 1 && map[i + 1][j] == HOME)
		dfs(i + 1, j, size, cnt);

	//left
	if (j - 1 >= 0 && map[i][j - 1] == HOME)
		dfs(i, j - 1, size, cnt);

	//right
	if (j + 1 <= size - 1 && map[i][j + 1] == HOME)
		dfs(i, j + 1, size, cnt);
}

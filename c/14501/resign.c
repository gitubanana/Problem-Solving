#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	d; //days
	int	p; //pay
}work;

void	scan_arr(int size);
void	dfs(int idx, int pay, int size);

work	arr[15];
int	max;

int	main(void)
{
	int	n;

	scanf("%d", &n);
	scan_arr(n);
	dfs(0, 0, n);
	printf("%d", max);
	return (0);
}

void	scan_arr(int size)
{
	int	i;

	for (i = 0; i < size; i++)
		scanf("%d %d", &arr[i].d, &arr[i].p);
}

void	dfs(int idx, int pay, int size)
{
	int	i;
	int	tmp;

	tmp = pay;
	for (i = idx; i < size; i++)
	{
		if (i + arr[i].d <= size && i < size)
		{
			pay = tmp;
			pay += arr[i].p;
			dfs(i + arr[i].d, pay, size);
		}
		if (max < pay)
			max = pay;
	}
}

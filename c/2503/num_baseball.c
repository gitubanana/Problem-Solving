#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char	n[4]; //num
	int	s; //strike
	int	b; //ball
}game;

int	cnt_strike(char *origin, char *num);
int	cnt_ball(char *origin, char *num);
int	is_ok(game *arr, int size, char *num);
void	print_ans(game *arr, int size);

int	main(void)
{
	int	i;
	int	n;
	game	*arr;

	i = -1;
	scanf("%d", &n);
	arr = malloc(sizeof(game) * n);
	if (!arr)
		return (1);
	while (++i < n)
		scanf("%s %d %d", arr[i].n, &arr[i].s, &arr[i].b);
	print_ans(arr, n);
	free(arr);
	return (0);
}

void	print_ans(game *arr, int size)
{
	int	cnt;
	int	i, j, k;
	char	test[3];

	cnt = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			for (k = 1; k <= 9; k++)
			{
				if (i != j && j != k && i != k)
				{
					test[0] = i + '0';
					test[1] = j + '0';
					test[2] = k + '0';
					if (is_ok(arr, size, test))
						cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
}

int	is_ok(game *arr, int size, char *num)
{
	int	i;

	for (i = 0; i < size; i++)
	{
		if (cnt_strike(arr[i].n, num) != arr[i].s)
			return (0);
		if (cnt_ball(arr[i].n, num) != arr[i].b)
			return (0);
	}
	return (1);
}

int	cnt_strike(char *origin, char *num)
{
	int	i, cnt;

	cnt = 0;
	for (i = 0; i < 3; i++)
		if (origin[i] == num[i])
			cnt++;
	return (cnt);
}

int	cnt_ball(char *origin, char *num)
{
	int	i, j, cnt;

	cnt = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (origin[i] == num[j] && i != j)
				cnt++;
	return (cnt);
}

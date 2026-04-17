#include <stdio.h>
#define DEST -1
#define REACHED -2
#define RETURN 0

void	scan_map(long long size);
void	print_ans(long long size);
void	move(long long i, long long j, long long size);

long long    map[100][100];

int	main(void)
{
	int	n;

	scanf("%d", &n);
	scan_map(n);
	print_ans(n);
}

void	scan_map(long long size)
{
	int	i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			scanf("%lld", &map[i][j]);
}

void	print_ans(long long size)
{
	char	*ans;

	move(0, 0, size);
	if (map[size - 1][size - 1] == REACHED)
		ans = "HaruHaru";
	else
		ans = "Hing";
	printf("%s", ans);
}

void	move(long long i, long long j, long long size)
{
    if (map[i][j] == RETURN || map[size - 1][size - 1] == REACHED)
		return ;
    
	if (map[i][j] == DEST)
	{
		map[i][j] = REACHED;
		return ;
	}

	//right
	if (j + map[i][j] <= size - 1)
		move(i, j + map[i][j], size);

	//down
	if (i + map[i][j] <= size - 1)
		move(i + map[i][j], j, size);
    
    map[i][j] = RETURN;
}
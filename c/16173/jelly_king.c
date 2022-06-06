#include <stdio.h>
#define DEST -1
#define REACHED -2
#define RETURN 0

void	scan_map(int size);
void	print_ans(int size);
void	move(int i, int j, int size);

int	map[3][3];

int	main(void)
{
	int	n;

	scanf("%d", &n);
	scan_map(n);
	print_ans(n);
}

void	scan_map(int size)
{
	int	i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			scanf("%d", &map[i][j]);
}

void	print_ans(int size)
{
	char	*ans;

	move(int i, int j, int size);
	if (map[size - 1][size - 1] == REACHED)
		ans = "HaruHaru";
	else
		ans = "Hing";
	printf("%s", ans);
}

void	move(int i, int j, int size)
{
	if (map[i][j] == DEST)
	{
		map[i][j] = REACHED;
		return ;
	}

	if (map[i][j] == RETURN)
		return ;

	//right
	if (j + map[i][j] <= size - 1)
		move(i, j + map[i][j], size);

	//down
	if (i + map[i][j] <= size - 1)
		move(i + map[i][j], j, size);
}

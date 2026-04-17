#include <stdio.h>
#define MAX 50

int	len_till_dot(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '.')
		len++;
	return (len);
}

void	fill_poliomino(char *board, int *cannot_cover)
{
	int	i, len;

	len = len_till_dot(board);
	i = 0;
	while (len >= 4)
	{
		board[i++] = 'A';
		board[i++] = 'A';
		board[i++] = 'A';
		board[i++] = 'A';
		len -= 4;
	}
	if (len == 2)
	{
		board[i++] = 'B';
		board[i++] = 'B';
		len -= 2;
	}
	if (len != 0)
		*cannot_cover = 1;
}

int	main(void)
{
	char	board[MAX + 1];
	int		i, cannot_cover;

	scanf("%s", board);
	cannot_cover = 0;
	for (i = 0; board[i]; i++)
	{
		if (board[i] == 'X')
		{
			fill_poliomino(&board[i], &cannot_cover);
			if (cannot_cover)
				break ;
		}
	}
	printf("%s", cannot_cover ? "-1" : board);
	return (0);
}

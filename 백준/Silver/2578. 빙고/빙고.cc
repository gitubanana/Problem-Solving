#include <iostream>

const int	MAX = 5;
const int	ERASED = -1;
const int	BINGO = 1;

int	bingo[MAX][MAX];

int	check_bingo()
{
	int	y, x;
	int	bingo_cnt = 0;

	// 가로 보기
	for (y = 0; y < MAX; y++)
	{
		for (x = 0; x < MAX; x++)
			if (bingo[y][x] != ERASED)
				break ;
		if (x == MAX)
			bingo_cnt++;
	}

	// 세로 보기
	for (x = 0; x < MAX; x++)
	{
		for (y = 0; y < MAX; y++)
			if (bingo[y][x] != ERASED)
				break ;
		if (y == MAX)
			bingo_cnt++;
	}

	// 대각선 보기
	// [0][4] [1][3] [2][2] [3][1] [4][0]
	// [0][0] [1][1] [2][2] [3][3] [4][4]
	for (x = 0; x < MAX; x++)
		if (bingo[x][MAX - x - 1] != ERASED)
			break ;
	if (x == MAX)
		bingo_cnt++;

	for (x = 0; x < MAX; x++)
		if (bingo[x][x] != ERASED)
			break ;
	if (x == MAX)
		bingo_cnt++;
	return (bingo_cnt);
}

void	print_board(void)
{
	int	y, x;

	printf("=========== start ===========\n");
	for (y = 0; y < MAX; y++)
	{
		for (x = 0; x < MAX; x++)
		{
			if (bingo[y][x] == ERASED)
				printf("* ");
			else
				printf("%d ", bingo[y][x]);
		}
		printf("\n");
	}
	printf("=============================\n\n");
}

void	erase(int &erase_num)
{
	int	y, x;

	for (y = 0; y < MAX; y++)
	{
		for (x = 0; x < MAX; x++)
		{
			if (bingo[y][x] == erase_num)
			{
				bingo[y][x] = ERASED;
				break ;
			}
		}
	}
	// print_board();
}

int	main(void)
{
	int	y, x;
	int	erase_num;
	int	bingo_time, bingo_cnt;

	for (y = 0; y < MAX; y++)
		for (x = 0; x < MAX; x++)
			scanf(" %d", &bingo[y][x]);
	bingo_time = bingo_cnt = 0;
	while (bingo_time < 25)
	{
		scanf(" %d", &erase_num);
		if (bingo_cnt < 3)
		{
			erase(erase_num);
			bingo_cnt = check_bingo();
			if (bingo_cnt >= 3)
				printf("%d\n", bingo_time + 1);
		}
		bingo_time++;
	}
	return (0);
}

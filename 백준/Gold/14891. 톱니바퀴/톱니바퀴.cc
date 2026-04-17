#include <iostream>
#include <cmath>

enum	e_dir
{
	CLOCKWISE = 1,
	COUNTERCLOCKWISE = -1
};

enum	e_idx
{
	LEFT = 6,
	RIGHT = 2
};

const int SIZE = 4;

void	move_to_dir(std::string &arr, int dir)
{
	unsigned long	i;
	char			save;

	if (dir == CLOCKWISE)
	{
		save = arr[arr.size() - 1];
		for (i = arr.size() - 1; i >= 1; --i)
			arr[i] = arr[i - 1];
		arr[0] = save;
	}
	else
	{
		save = arr[0];
		for (i = 0; i < arr.size() - 1; ++i)
			arr[i] = arr[i + 1];
		arr[arr.size() - 1] = save;
	}
}

void	make_move(std::string (&arr)[SIZE], int &move_idx, int &dir)
{
	int	i;
	int	cur_data, cur_dir;

	// 왼쪽 부분 보기
	cur_dir = dir;
	cur_data = arr[move_idx][LEFT];
	for (i = move_idx - 1; i >= 0; --i)
	{
		if (cur_data == arr[i][RIGHT])
			break ;
		cur_data = arr[i][LEFT];
		cur_dir *= -1, move_to_dir(arr[i], cur_dir);
	}

	// 오른쪽 부분 보기
	cur_dir = dir;
	cur_data = arr[move_idx][RIGHT];
	for (i = move_idx + 1; i < SIZE; ++i)
	{
		if (cur_data == arr[i][LEFT])
			break ;
		cur_data = arr[i][RIGHT];
		cur_dir *= -1, move_to_dir(arr[i], cur_dir);
	}

	move_to_dir(arr[move_idx], dir);
}

int	get_ans(std::string (&arr)[SIZE])
{
	int	ret = 0;

	for (int i = 0; i < SIZE; ++i)
		ret += (arr[i][0] == '1') * pow(2, i);
	return (ret);
}

int	main(void)
{
	std::string	arr[SIZE];
	int			idx, dir;
	int			i, test_cnt;

	for (i = 0; i < SIZE; ++i)
		std::cin >> arr[i];
	std::cin >> test_cnt;
	while (test_cnt)
	{
		std::cin >> idx >> dir, --idx;
		make_move(arr, idx, dir);
		--test_cnt;
	}
	std::cout << get_ans(arr) << std::endl;
	return (0);
}

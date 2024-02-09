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

int size;

void	move_to_dir(std::string &gear, int dir)
{
	unsigned long	i;
	char			save;

	if (dir == CLOCKWISE)
	{
		save = gear[gear.size() - 1];
		for (i = gear.size() - 1; i >= 1; --i)
			gear[i] = gear[i - 1];
		gear[0] = save;
	}
	else
	{
		save = gear[0];
		for (i = 0; i < gear.size() - 1; ++i)
			gear[i] = gear[i + 1];
		gear[gear.size() - 1] = save;
	}
}

void	make_move(std::string *arr, int move_idx, int dir)
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
	for (i = move_idx + 1; i < size; ++i)
	{
		if (cur_data == arr[i][LEFT])
			break ;
		cur_data = arr[i][RIGHT];
		cur_dir *= -1, move_to_dir(arr[i], cur_dir);
	}

	move_to_dir(arr[move_idx], dir);
}

int	get_ans(std::string *arr)
{
	int	ret = 0;

	for (int i = 0; i < size; ++i)
		ret += (arr[i][0] == '1');
	return (ret);
}

int	main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

	std::string	*arr;
	int			toMove, dir;
	int			test_cnt;

    std::cin >> size;
    arr = new std::string[size];
	for (int i = 0; i < size; ++i)
		std::cin >> arr[i];

	std::cin >> test_cnt;
	while (test_cnt--)
	{
		std::cin >> toMove >> dir;
		make_move(arr, --toMove, dir);
	}

	std::cout << get_ans(arr) << '\n';
    delete[] arr;
	return (0);
}

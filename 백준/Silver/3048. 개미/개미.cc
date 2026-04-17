#include <iostream>
#include <cstring>

enum	e_dir
{
	LEFT,
	RIGHT
};

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	ft_rev(std::string &str)
{
	int		i, len;

	len = static_cast<int>(str.size()) / 2;
	for (i = 0; i < len; ++i)
		swap(str[i], str[str.size() - i - 1]);
}

void	move_ant(std::string &ants, int &size_1, int &size_2, int &sec)
{
	int	dir[30];
	int	i, total_size, check_flag;

	for (i = 0; i < size_1; ++i)
		dir[i] = LEFT;

	total_size = size_1 + size_2;
	for (i = size_1; i < total_size; ++i)
		dir[i] = RIGHT;

	while (sec)
	{
		check_flag = 1;
		for (i = 0; i < total_size - 1; ++i)
		{
			if (check_flag && dir[i] == LEFT && dir[i + 1] == RIGHT)
			{
				swap(dir[i], dir[i + 1]), swap(ants[i], ants[i + 1]);
				check_flag = 0;
			}
			else
				check_flag = 1;
		}
		--sec;
	}
}

int	main(void)
{
	std::string	ants;
	char		str[26];
	int			size_1, size_2, sec;

	scanf(" %d %d", &size_1, &size_2);
	scanf(" %s", str);
	ants = str, ft_rev(ants);
	scanf(" %s", str);
	ants += str;
	scanf(" %d", &sec);
	move_ant(ants, size_1, size_2, sec);
	printf("%s\n", ants.c_str());
	return (0);
}

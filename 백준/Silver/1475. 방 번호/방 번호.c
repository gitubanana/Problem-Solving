#include <stdio.h>

void	init_it_to_0(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void	set_num_cnt(int *num_cnt, char *room_num)
{
	int	i;

	i = 0;
	while (room_num[i])
	{
		num_cnt[room_num[i] - '0']++;
		i++;
	}
}

int	get_max(int *num_cnt, int size)
{
	int	i;
	int	max;

	max = num_cnt[0];
	i = 1;
	while (i < size)
	{
		if (max < num_cnt[i] && (i != 9 && i != 6))
			max = num_cnt[i];
		i++;
	}
	return (max);
}

int	get_ans(int cnt)
{
	return (cnt / 2 + cnt % 2);
}

int	get_set_cnt(char *room_num)
{
	int	max;
	int	num_cnt[10];
	int	nine_and_six;

	init_it_to_0(num_cnt, sizeof(num_cnt) / sizeof(int));
	set_num_cnt(num_cnt, room_num);
	nine_and_six = get_ans(num_cnt[6] + num_cnt[9]);	
	max = get_max(num_cnt, sizeof(num_cnt) / sizeof(int));
	return (nine_and_six > max ? nine_and_six : max);
}

int	main(void)
{
	char	room_num[8];

	scanf("%s", room_num);
	printf("%d", get_set_cnt(room_num));
	return (0);
}

#include <iostream>

int	main(void)
{
	long long	to_make;
	long long	cur_sum, cur_num;

	scanf(" %u", &to_make);
	cur_sum = 0;
	cur_num = 1;
	while (true)
	{
		cur_sum += cur_num;
		if (cur_sum >= to_make)
			break ;
		++cur_num;
	}
	if (cur_sum == to_make)
		printf("%u\n", cur_num);
	else
		printf("%u\n", cur_num - 1);
	return (0);
}

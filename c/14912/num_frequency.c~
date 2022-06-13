#include <stdio.h>

int	count(int num, int aim);
void	print_ans(int num, int aim);

int	main(void)
{
	int	num;
	int	aim;

	scanf("%d %d", &num, &aim);
	print_ans(num, aim);
}

void	print_ans(int num, int aim)
{
	int	i;
	int	cnt;

	cnt = 0;
	for (i = 1; i <= num; i++)
		cnt += count(i, aim);
	printf("%d", cnt);
}

int	count(int num, int aim)
{
	int	cnt;

	cnt = 0;
	while (num > 0)
	{
		if (num % 10 == aim)
			cnt++;
		n /= 10;
	}
	return (cnt);
}

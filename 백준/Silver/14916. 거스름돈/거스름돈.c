
#include <stdio.h>

int	main(void)
{
	int	cnt = 0;
	int	change;

	scanf("%d", &change);
	if (change >= 5 && change % 5 == 0)
		printf("%d", change / 5);
	else
	{
		while (change % 5 != 0)
		{
			change -= 2;
			cnt++;
		}
		if (change >= 5)
			printf("%d", change / 5 + cnt);
		else
		{
			if (change % 2 == 0)
				printf("%d", change / 2 + cnt);
			else
				printf("-1");
		}
	}
	return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX 100

void	init_padoban(uint64_t *padoban)
{
	int	i;

	padoban[0] = padoban[1] = padoban[2] = 1;
	for (i = 3; i < MAX; i++)
		padoban[i] = padoban[i - 2] + padoban[i - 3];
}

int	main(void)
{
	int			n, test_cnt;
	uint64_t	padoban[MAX];

	scanf("%d", &test_cnt);
	init_padoban(padoban);
	while (test_cnt--)
	{
		scanf("%d", &n);
		printf("%llu\n", padoban[n - 1]);
	}
	return (0);
}
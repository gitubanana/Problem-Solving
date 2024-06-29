#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1500000
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CUR_PAY dp[cur]

typedef struct work
{
	int	days;
	int	pay;
} t_work;

const int FAIL = -1;

int	max, size;
int dp[MAX_SIZE + 1];
t_work arr[MAX_SIZE];

void	takeInput()
{
	int	i;

	scanf("%d", &size);
	for (i = 0; i < size; i++)
		scanf("%d %d", &arr[i].days, &arr[i].pay);
}

int	main(void)
{
	takeInput();

	int maxPay = 0;
	int prevMaxPay = 0;
	for (int start = 0; start < size; ++start)
	{
		prevMaxPay = MAX(
			prevMaxPay,
			dp[start]
		);

		int nextDay = start + arr[start].days;
		if (nextDay > size)
			continue ;

		int newPay = prevMaxPay + arr[start].pay;
		dp[nextDay] = MAX(
			dp[nextDay],
			newPay
		);

		maxPay = MAX(
			maxPay,
			dp[nextDay]
		);
	}

	printf("%d\n", maxPay);
	return (0);
}

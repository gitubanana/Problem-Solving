#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ppl[10001];
int ppl_cnt[10001];
int	count;

// void	print(int HH)
// {
// 	for (int i = 1; i <= HH; i++)
// 	{
// 		printf("%d ", ppl_cnt[i]);
// 	}
// 	printf("\n");
// }

int	going(int current_index, int HH)
{
	if (current_index == HH)
		return (1);
	if (count == HH)
		return (0);
	count++;
	int next_index = ppl[current_index];
	// printf("current index : %d  ", current_index);
	// printf("next    index : %d  ", next_index);
	// print(HH);
	return (going(next_index, HH));
}

int main(void)
{
	int T;
	scanf(" %d", &T);
	while(T--)
	{
		int N;
		scanf(" %d", &N);
		for (int i = 1; i <= N; i++)
			scanf(" %d", &ppl[i]);
		count = 0;
		int result = going(1, N);
		if (result == 0)
			printf("0\n");
		else
			printf("%d\n", count);
		for (int i = 0; i <= N; i++)
		{
			ppl[i] = 0;
		}
	}
}
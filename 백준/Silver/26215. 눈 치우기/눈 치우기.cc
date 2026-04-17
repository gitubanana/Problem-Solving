#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int	MAX = 100;
int			snow[MAX];

int	get_first(int house_cnt)
{
	int	i;

	for (i = house_cnt - 1; i >= 0; i--)
		if (snow[i] > 0)
			break ;
	return (i);
}

int	get_second(int house_cnt)
{
	int	i;
	int	cnt = 0;

	for (i = house_cnt - 1; i >= 0; i--)
	{
		if (snow[i] > 0)
			cnt++;
		if (cnt == 2)
			break ;
	}
	//i가 -1이 될 때...
	return (i);
}

void	print_ans(int house_cnt)
{
	int	minute = 0;
	int	i, first, second;

	//집의 수가 1일 때
	if (house_cnt == 1)
	{
		printf("%d", snow[0] > 1440 ? -1 : snow[0]);
		return ;
	}
	while (1)
	{
		first = get_first(house_cnt);
		second = get_second(house_cnt);
		//두 개씩 뺄 수 없을 때 그냥 남은 만큼 빼기
		if (first != -1 && second == -1)
		{
			minute += snow[first];
			break ;
		}
		//두 개씩 뺄 수 있을 때
		else if (first != -1 && second != -1)
		{
			snow[first] -= snow[second];
			minute += snow[second];
			snow[second] = 0;
		}
		//더 이상 0보다 큰 수를 찾을 수 없을 때
		else if (first == -1 && second == -1)
			break ;
		sort(snow, snow + house_cnt);
	}
	printf("%d", minute > 1440 ? -1 : minute);
}

int main(void)
{
	int	i;
	int	house_cnt;

	scanf("%d", &house_cnt);
	for (i = 0; i < house_cnt; i++)
		scanf("%d", &snow[i]);
	sort(snow, snow + house_cnt);
	// printf("after sort\n");
	// for (i = 0; i < house_cnt; i++)
	// 	printf("%d ", snow[i]);
	// printf("\n");
	print_ans(house_cnt);
	return (0);
}
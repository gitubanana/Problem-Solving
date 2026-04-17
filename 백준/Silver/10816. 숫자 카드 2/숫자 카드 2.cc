#include <cstring>
#include <iostream>

const int	MAX = 10000000;

int	card_cnt[MAX + MAX + 1];

void	take_input(int *&arr, int &arr_size, int is_num)
{
	std::cin >> arr_size;
	arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		std::cin >> arr[i];
		if (is_num)
			card_cnt[arr[i] + MAX]++;
	}
}

void	print_card_cnt(int *&arr, int &size, int *&card, int &card_size)
{
	int	i;
	(void)arr, (void)size;

	for (i = 0; i < card_size; i++)
		std::cout << card_cnt[card[i] + MAX] << " ";
}

int	main(void)
{
	int	*arr, arr_size;
	int	*card, card_size;

	/* 입력받기 */
	take_input(arr, arr_size, 1), take_input(card, card_size, 0);

	/* 카드 개수 출력하기 */
	print_card_cnt(arr, arr_size, card, card_size);

	delete[] arr;
	delete[] card;
	return (0);
}
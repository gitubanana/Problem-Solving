#include <iostream>
#include <algorithm>

int	main(void)
{
	int	i;
	int	*arr, size;

	scanf(" %d", &size);
	arr = new int[size];
	for (i = 0; i < size; i++)
		scanf(" %d", &arr[i]);
	// sort
	std::sort(arr, arr + size);
	for (i = 0; i < size; i++)
		printf("%d\n", arr[i]);
	delete[] arr;
	return (0);
}

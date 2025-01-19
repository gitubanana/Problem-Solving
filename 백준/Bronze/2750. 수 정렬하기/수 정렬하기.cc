#include <iostream>
void	quickSort(int *arr, int start, int end)
{
	int	pivot, l, r;

	if (start >= end)
		return ;
	pivot = start;
	l = pivot + 1;
	r = end;
	while (l <= r)
	{
		while (l <= end && arr[l] <= arr[pivot])
			l++;
		while (r > start && arr[r] >= arr[pivot])
			r--;
		if (l > r)
			std::swap(arr[r], arr[pivot]);
		else
			std::swap(arr[l], arr[r]);
	}
	quickSort(arr, start, r - 1);
	quickSort(arr, r + 1, end);
}


int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '\n';
    }

    delete[] arr;
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;

struct s_data
{
	int	num;
	char name[101];
};

void	ft_merge(s_data *data, s_data *temp, int start, int end)
{
		int mid = (start + end) / 2;
	int i = start;
	int j = start;
	int k = mid + 1;

	while (i <= mid && k <= end)
	{
		if (data[i].num > data[k].num)
		{
			temp[j] = data[k];
			j++;
			k++;
		}
		else
		{
			temp[j] = data[i];
			j++;
			i++;
		}
	}
	if (i > mid)
	{
		while (k <= end)
		{
			temp[j] = data[k];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[j] = data[i];
			j++;
			i++;
		}
	}
	for (int i = start; i <= end; i++)
		data[i] = temp[i];
}

void	ft_sort(s_data *data, s_data *temp, int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		ft_sort(data, temp, start, mid);
		ft_sort(data, temp, mid + 1, end);
		ft_merge(data, temp, start, end);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	n;

	cin >> n;
	s_data *data = static_cast<s_data *>(malloc(sizeof(s_data) * n));
	s_data *temp = static_cast<s_data *>(malloc(sizeof(s_data) * n));
	for (int i = 0; i < n; i++)
		cin >> data[i].num >> data[i].name;

	ft_sort(data, temp, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << data[i].num << ' ' << data[i].name << '\n';
	
	free(data);
	free(temp);
	return (0);
}
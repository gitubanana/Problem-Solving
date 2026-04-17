#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::set<int>	a, b;
	int	a_size, b_size, elem;

	std::cin >> a_size >> b_size;
	while (a_size--)
	{
		std::cin >> elem;
		a.insert(elem);
	}
	while (b_size--)
	{
		std::cin >> elem;
		b.insert(elem);
	}

	int	ans = 0, same_cnt;
	std::set<int>::iterator	iter;

	same_cnt = 0;
	for (iter = a.begin(); iter != a.end(); ++iter)
	{
		if (b.find(*iter) != b.end())
			++same_cnt;
	}
	ans += a.size() - same_cnt;

	same_cnt = 0;
	for (iter = b.begin(); iter != b.end(); ++iter)
	{
		if (a.find(*iter) != a.end())
			++same_cnt;
	}
	ans += b.size() - same_cnt;

	std::cout << ans << '\n';
	return (0);
}

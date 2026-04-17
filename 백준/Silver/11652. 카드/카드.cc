#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

typedef std::map<long long, int> t_card;

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	t_card				_map;
	t_card::iterator	iter;
	long long    		size, max;
	long long			str, ans;

	std::cin >> size;
	while (size--)
	{
		std::cin >> str;
		iter = _map.find(str);
		if (iter == _map.end())
			_map.insert({str, 1});
		else
			++iter->second;
	}
	max = 0;
	for (iter = _map.begin(); iter != _map.end(); ++iter)
	{
		if (max < iter->second)
			ans = iter->first, max = iter->second;
	}
	std::cout << ans << '\n';
	return (0);
}

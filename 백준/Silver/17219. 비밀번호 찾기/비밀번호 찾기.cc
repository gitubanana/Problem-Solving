#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	size, search_cnt;
	std::string	url, passwd;
	std::map<std::string, std::string>	_map;

	std::cin >> size >> search_cnt;
	while (size)
	{
		std::cin >> url >> passwd;
		_map.insert({url, passwd});
		--size;
	}

	while (search_cnt)
	{
		std::cin >> url;
		std::cout << _map[url] << '\n';
		--search_cnt;
	}

	return (0);
}

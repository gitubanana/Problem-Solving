#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <map>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	size;
	std::string	file, extension;
	std::map<std::string, int>	wallpaper;
	std::map<std::string, int>::iterator	iter;

	std::cin >> size;
	while (size--)
	{
		std::getline(std::cin, file, '.');
		std::cin >> extension;

		iter = wallpaper.find(extension);
		if (iter == wallpaper.end())
			wallpaper.insert({extension, 1});
		else
			++iter->second;
	}

	for (iter = wallpaper.begin(); iter != wallpaper.end(); ++iter)
	{
		std::cout << iter->first << " " << iter->second << '\n';
	}

	return (0);
}

#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <deque>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	size;
	std::string	a, b;
	std::set<std::string>	dancer;
	std::set<std::string>::iterator	iter;

	dancer.insert("ChongChong");
	std::cin >> size;
	while (size--)
	{
		std::cin >> a >> b;
		iter = dancer.find(a);
		if (iter != dancer.end())
			dancer.insert(b);
		else if ((iter = dancer.find(b)) != dancer.end())
			dancer.insert(a);
	}
	std::cout << dancer.size() << '\n';
	return (0);
}

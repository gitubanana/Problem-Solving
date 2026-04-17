#include <vector>
#include <cstring>
#include <iostream>

int	main(void)
{
	std::vector<int>	vector;
	int					i, k, size, start;

	std::cin >> size >> start, k = start - 1;
	for (i = 1; i <= size; i++)
		vector.push_back(i);
	std::cout << "<";
	std::vector<int>::iterator it;
	--start;
	while (!vector.empty())
	{
		it = vector.begin() + start;
		std::cout << vector.at(start), vector.erase(it);
		if (vector.size() != 0)
			std::cout << ", ";
		--size;
		if (size)
			start = (start + k) % size;
	}
	std::cout << ">";
	return (0);
}
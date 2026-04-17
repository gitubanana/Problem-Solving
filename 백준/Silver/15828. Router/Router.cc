#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <deque>

const int	SEND = 0, STOP = -1;

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	buffer_size, input;
	std::deque<int>	buffer;

	std::cin >> buffer_size;
	while (true)
	{
		std::cin >> input;
		if (input == STOP)
			break ;
		else if (input == SEND)
			buffer.pop_front();
		else if (buffer.size() != buffer_size)
			buffer.push_back(input);
	}
	for (int i = 0; i < buffer.size(); ++i)
		std::cout << buffer[i] << " ";
	if (buffer.size() == 0)
		std::cout << "empty\n";
	return (0);
}

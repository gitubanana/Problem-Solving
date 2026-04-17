#include <deque>
#include <cstring>
#include <iostream>

int	main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

	std::string		cmd;
	std::deque<int>	deque;
	int				test_cnt, tmp;

	std::cin >> test_cnt;
	while (test_cnt--)
	{
		std::cin >> cmd;
		if (cmd == "push_front")
			std::cin >> tmp, deque.push_front(tmp);
		else if (cmd == "push_back")
			std::cin >> tmp, deque.push_back(tmp);
		else if (cmd == "pop_front")
		{
			if (deque.empty())
				std::cout << -1;
			else
				std::cout << deque.front(), deque.pop_front();
			std::cout << '\n';
		}
		else if (cmd == "pop_back")
		{
			if (deque.empty())
				std::cout << -1;
			else
				std::cout << deque.back(), deque.pop_back();
			std::cout << '\n';
		}
		else if (cmd == "size")
			std::cout << deque.size() << '\n';
		else if (cmd == "empty")
			std::cout << deque.empty() << '\n';
		else if (cmd == "front")
		{
			if (deque.empty())
				std::cout << -1;
			else
				std::cout << deque.front();
			std::cout << '\n';
		}
		else //back
		{
			if (deque.empty())
				std::cout << -1;
			else
				std::cout << deque.back();
			std::cout << '\n';
		}
	}
	return (0);
}
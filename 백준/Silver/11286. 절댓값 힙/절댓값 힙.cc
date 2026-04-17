#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>

const int	POP_NUM = 0;

struct t_data
{
	bool	 	is_minus;
	long long	abs_num;

	t_data(int num)
		: is_minus(num < 0), abs_num(num * (1 - 2 * is_minus))
	{
	}

	operator int(void) const
	{
		if (is_minus)
			return (abs_num * -1);
		return (abs_num);
	}

	// b가 위로 갈 때 true
	bool operator<(const struct t_data &b) const
	{
		if (b.abs_num < abs_num)
			return (true);
		else if (b.abs_num > abs_num)
			return (false);

		return (b.is_minus);
	}
};

class abs_heap
{
	private:
		std::priority_queue<t_data>	pq;
	public:
		const int	EMPTY = 0;

		void	push(int data)
		{
			pq.push(t_data(data));
		}

		int		pop(void)
		{
			if (pq.empty())
				return (EMPTY);
			int	ret = pq.top();
			pq.pop();
			return (ret);
		}
};

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	cnt, num;
	abs_heap	heap;

	std::cin >> cnt;
	while (cnt)
	{
		std::cin >> num;
		if (num == POP_NUM)
			std::cout << heap.pop() << '\n';
		else
			heap.push(num);
		--cnt;
	}
	return (0);
}

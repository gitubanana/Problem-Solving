#include <iostream>
#include <queue>
#define MAX 100001

int	pos[MAX];
int visited[MAX];

void	bfs(int subin, int dongsaeng)
{
    std::queue<int> q;
	int	            i, x[3], front;

	if (subin == dongsaeng)
		return ;
    q.push(subin);
	while (1)
	{
        front = q.front();
		x[0] = front * 2, x[1] = front - 1, x[2] = front + 1;
        q.pop();
		for (i = 0; i < 3; i++)
		{
			if (x[i] < 0 || x[i] > MAX || visited[x[i]])
				continue ;
            visited[x[i]] = 1;
            q.push(x[i]);
   			pos[x[i]] = pos[front] + (x[i] != front * 2);
			if (x[i] == dongsaeng)
				return ;
		}
	}
}

int	main(void)
{
	int	subin, dongsaeng;

    std::cin >> subin >> dongsaeng;
	bfs(subin, dongsaeng);
	std::cout << pos[dongsaeng];
	return (0);
}

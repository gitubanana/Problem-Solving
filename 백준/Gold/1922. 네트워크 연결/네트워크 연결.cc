#include <iostream>
#include <cstring>
#include <algorithm>

typedef struct s_edge
{
	int	from;
	int	to;
	int	weight;

    bool	operator<(const struct s_edge &b)
    {
    	return (this->weight < b.weight);
    }
}	t_edge;

const int	MAX = 1001;

int parent[MAX];

void    init_parent(int v_cnt)
{
    for (int i = 1; i <= v_cnt; ++i)
        parent[i] = i;
}

int find_parent(int v)
{
    if (parent[v] == v)
        return (v);
    return (parent[v] = find_parent(parent[v]));
}

void    union_trees(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

void	kruskal(t_edge *arr, int size, int v_cnt)
{
	int	i, j;
	int	total_weight;
	t_edge  cur_edge;

    init_parent(v_cnt);
	total_weight = 0;
	for (i = 0; i < size; i++)
	{
	    cur_edge = arr[i];
		if (find_parent(cur_edge.from) == find_parent(cur_edge.to))
			continue ;
		union_trees(cur_edge.from, cur_edge.to);
		total_weight += arr[i].weight;
	}
	printf("%d\n", total_weight);
}

int	main(void)
{
	int		i;
	int		v_cnt, e_cnt;
	t_edge	*arr;

	scanf(" %d %d", &v_cnt, &e_cnt);
	arr = new t_edge[e_cnt];
	for (i = 0; i < e_cnt; i++)
		scanf(" %d %d %d",
			&arr[i].from, &arr[i].to, &arr[i].weight);
	std::sort(arr, arr + e_cnt);
	kruskal(arr, e_cnt, v_cnt);
	delete[] arr;
	return (0);
}

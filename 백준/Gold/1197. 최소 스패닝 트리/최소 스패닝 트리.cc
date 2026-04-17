#include <iostream>
#include <cstring>
#include <algorithm>

typedef struct e_edge
{
	int	from;
	int	to;
	int	weight;
	
    bool	operator<(const struct e_edge &b)
    {
    	return (this->weight < b.weight);
    }
}	t_edge;

const int	MAX = 10001;

int	parent[MAX];

void    init_parent(int v_cnt)
{
    for (int i = 1; i <= v_cnt; ++i)
        parent[i] = i;
}

int find(int v)
{
    if (parent[v] == v)
        return (v);
    return parent[v] = find(parent[v]);
}

void    _union(int x, int y)
{
    int x_parent, y_parent;

    x_parent = find(x);
    y_parent = find(y);
    if (x_parent < y_parent)
        parent[y_parent] = x_parent;
    else
        parent[x_parent] = y_parent;
}

void    kruskal(t_edge *arr, int size, int v_cnt)
{
	int	i;
	long long	total_weight;
	t_edge cur_edge;

    init_parent(v_cnt);
	total_weight = 0;
	for (i = 0; i < size; i++)
	{
	    cur_edge = arr[i];
		if (find(cur_edge.from) == find(cur_edge.to))
			continue ;
		total_weight += cur_edge.weight;
		_union(cur_edge.from, cur_edge.to);
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

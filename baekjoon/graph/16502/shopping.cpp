#include <iostream>
#include <vector>
#include <iomanip>

struct t_edge
{
    char   to;
    double prob; // probability
};

typedef std::vector<t_edge> t_edge_vec;
typedef std::vector<double> t_prob_vec;

const int   SIZE = 4;
const char  TO_IDX = 'A';

int        _time;
t_edge_vec edges[SIZE];
t_prob_vec cur_prob(SIZE);
t_prob_vec prev_prob(SIZE, 100 / SIZE);

void    go_shopping(int cur)
{
    t_edge_vec    &cur_edges = edges[cur];

    for (t_edge &edge : cur_edges)
    {
        cur_prob[edge.to] += prev_prob[cur] * edge.prob;
    }
}

void    simulation(void)
{
    while (_time--)
    {
        for (int v = 0; v < SIZE; ++v)
            go_shopping(v);

        if (_time == 0)
            break ;

        prev_prob = cur_prob;
        for (double &to_init : cur_prob)
            to_init = 0;
    }

    for (double &to_print : cur_prob)
        std::cout << std::fixed << std::setprecision(2)
                  << to_print << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_edge edge;
    char   from;
    int    e_cnt;

    std::cin >> _time >> e_cnt;
    while (e_cnt--)
    {
        std::cin >> from >> edge.to >> edge.prob;
        from -= TO_IDX;
        edge.to -= TO_IDX;
        edges[from].push_back(edge);
    }

    simulation();
    return (0);
}

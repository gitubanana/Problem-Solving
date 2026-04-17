// 연결요소 : 나누어진 각각의 그래프 (연결되지 않은 정점도 취급)
#include <stdio.h>

void    print_ans(int v_cnt);
int    is_searchable(int v, int v_cnt);
void    search(int v, int v_cnt);

// 전역변수는 초기화X -> 0으로 초기화됨
int    matrix[1001][1001];
int    visited[1001];

int    main(void)
{
    int    i;
    int    a;
    int    b;
    int    vertex;
    int    edge;
    
    i = 0;
    scanf("%d %d", &vertex, &edge);
    while (edge--)
    {
        scanf("%d %d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    print_ans(vertex);
}

void    print_ans(int v_cnt)
{
    int    i;
    int    cnt;
    
    cnt = 0;
    for (i = 1; i <= v_cnt; i++)
    {
        //탐색 가능하면 -> 연결된 거 '왔다' 표시 -> 연결요소 하나 증가
        if (is_searchable(i, v_cnt))
            cnt++;
    }
    printf("%d", cnt);
}

int    is_searchable(int v, int v_cnt)
{
    int    i;
    
    //와봤다면 -> 탐색 안 됨 -> 0리턴
    if (visited[v] == 1)
        return (0);
    
    //이 정점과 연결된 모든 정점에 '왔다' 표시
    search(v, v_cnt);
    
    //안 와봤다면 -> 탐색가능 -> 1리턴
    //정점과 연결된 게 없어도 연결요소로 취급
    return (1);
}

void    search(int v, int v_cnt)
{
    int    i;
    
    //처음부터 끝까지 탐색
    for (i = 1; i <= v_cnt; i++)
    {
        //1. 연결돼 있고, 2. 가보지 않았다 -> 가서 '왔다' 표시
        if (matrix[v][i] == 1 && visited[i] == 0)
        {
            //'왔다' 표시
            visited[i] = 1;
            
            //'왔다' 표시한 정점과 연결된 거 탐색
            search(i, v_cnt);
        }
    }
}
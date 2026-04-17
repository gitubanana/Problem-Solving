#include<cstdio>
#include<queue>
#include<algorithm>
typedef struct Item {
    Item() {}
    Item(int _x, int _y, int _c, int _from): x(_x), y(_y), c(_c), from(_from) {}
    int x, y, c;
    int from;
    bool operator < (Item op) const {return c < op.c;}
} Item;
using namespace std;
int N, M, CNT, ANS;
bool visited[302][51][51];
int A[51][51];
vector<Item> E, P;
int par[253];
int find(int a) {
    return par[a] = par[a] == a ? a : find(par[a]);
}
int dir[4][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int getp(int x, int y) {
    return y * 50 + x;
}
void bfs_all() {
    Item here;
    queue<Item> q;
    int sz = P.size();
    for(int i = 0; i < sz; i++) {
        here = P[i];
        q.push(here);
        visited[here.from][here.y][here.x] = true;
    }
    while(!q.empty()) {
        here = q.front(), q.pop();
        for(int i = 0; i < 4; i++) {
            int nx=here.x+dir[i][0], ny=here.y+dir[i][1], nc=here.c+1;
            if(nx>=0 && ny>=0 && nx<N && ny<N && A[ny][nx]!=999 && !visited[here.from][ny][nx])
            {
                int &nextSpace = A[ny][nx];
                if (nextSpace != 0) {
                    int a = find(here.from), b = find(nextSpace);
                    if(a != b) {
                        par[a] = b;
                        ANS += here.c + 1, CNT++;
                        if(CNT == M) return;
                    }
                }
                q.push(Item(nx, ny, nc, here.from)), visited[here.from][ny][nx] = true;
            }
        }
    }
}

int main() {
    int vidx = 1;
    char line[55];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%s", line);
        for(int j = 0; j < N; j++) {
            switch(line[j]) {
                case '0': A[i][j] = 0; break;
                case '1': A[i][j] = 999; break;
                case 'K': case 'S': P.push_back(Item(j, i, 0, vidx)); A[i][j] = vidx++; break;
            }
        }
    }
    for(int i = 1; i <= M+1; i++) par[i] = i;
    bfs_all();
    if(CNT < M) ANS = -1;
    printf("%d", ANS);
    return 0;
}
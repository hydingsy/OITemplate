#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> HeapNode;

struct Edge {
    int v, len, next;
};

const int MAXN = 1e4, MAXM = 5e5, INF = 0x3f3f3f3f;
int n, m, s, e_ptr = 1, head[MAXN+10]; Edge E[(MAXM+10)<<1];
int dist[MAXN+10], done[MAXN+10];

void add_edge(int u, int v, int len) {
    E[++e_ptr] = (Edge) { v, len, head[u] }; head[u] = e_ptr;
}

void add_pair(int u, int v, int len) {
    add_edge(u, v, len); add_edge(v, u, len);
}

void Dijkstra() {
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
    memset(done, 0, sizeof(done));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0; pq.push(make_pair(dist[s], s));
    while(!pq.empty()) {
        HeapNode p = pq.top(); pq.pop();
        int u = p.snd;
        if(done[u]) continue;
        done[u] = true;
        for(int j=head[u]; j; j=E[j].next) {
            int v = E[j].v, len = E[j].len;
            if(dist[v] > dist[u] + len) {
                dist[v] = dist[u] + len;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

inline int readint() {
    int f=1, r=0; char c=getchar();
    while(!isdigit(c)) { if(c=='-')f=-1; c=getchar(); }
    while(isdigit(c)) { r=r*10+c-'0'; c=getchar(); }
    return f*r;
}

int main() {
    int u, v, w;
    n = readint(); m = readint(); s = readint();
    for(int i = 1; i <= m; i++) {
        u = readint(); v = readint(); w = readint();
        add_edge(u, v, w);
    }
    Dijkstra();
    for(int i = 1; i <= n; i++) {
        if(dist[i] < INF)
            printf("%d ", dist[i]);
        else
            printf("%d ", INT_MAX);
    }
    return 0;
}

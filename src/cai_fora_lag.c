#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000000
#define MAXN 2001

int graph[MAXN][MAXN], graph_with_super[MAXN][MAXN];
int dist[MAXN][MAXN], dist_with_super[MAXN][MAXN];
int V, E;

int min(int a, int b)
{
    return a < b ? a : b;
}

void add_edge(int graph[MAXN][MAXN], int from, int to, int cost)
{
    graph[from][to] = cost;
}

void floyd_warshall(int graph[MAXN][MAXN], int dist[MAXN][MAXN])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = (i == j) ? 0 : graph[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void detect_negative_cycles(int dist[MAXN][MAXN])
{
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[j][i] != INF && dist[k][j] != INF && dist[j][j] < 0)
                    dist[k][i] = INF;
}

int main()
{
    scanf("%d", &V);

    E = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INF;
            graph_with_super[i][j] = INF;
        }
    }


    while (1)
    {
        int v, w, c, t;
                            
        scanf("%d %d %d %d", &v, &w, &c, &t);

        if (v == 0 && w == 0 && c == 0.0 && t == 0)
            break;

        if (t == 0)
        {
            add_edge(graph, v, w, c);

            add_edge(graph, w, v, c);

            add_edge(graph_with_super, v, w, c);

            add_edge(graph_with_super, w, v, c);
        }
        else if (t == 1)
        {
            add_edge(graph_with_super, v, w, c);
        }
    }

    floyd_warshall(graph, dist);

    floyd_warshall(graph_with_super, dist_with_super);

    detect_negative_cycles(dist);

    detect_negative_cycles(dist_with_super);

    while (1)
    {
        int o, x;

        if (scanf("%d %d", &o, &x) != 2)
            break;

        int without_super = dist[o][x];

        int with_super = dist_with_super[o][x];

        if (without_super == INF || with_super == INF)
            printf("Impossibru\n");

        else
            printf("%d %d\n", without_super, with_super);
    }
    return 0;
}

from heapq import heappush, heappop


def dij(g, s):
    dist = [int(1e9) for u in range(len(g))]
    dist[s] = 0
    pq = []
    heappush(pq, (0, s))

    while (len(pq) > 0):
        d, u = heappop(pq)
        if (d > dist[u]):
            continue
        for v, w in g[u]:
            cand = dist[u] + w
            if cand < dist[v]:
                dist[v] = cand
                heappush(pq, (dist[v], v))

    return dist


def main():
    n, m = map(int, input().split())
    g = [[] for i in range(n)]

    for _ in range(m):
        u, v, w = map(int, input().split())
        g[u].append((v, w))

    start = 0
    ans = dij(g, start)


main()

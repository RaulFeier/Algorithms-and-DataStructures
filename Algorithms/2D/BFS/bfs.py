from collections import deque

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def bfs(a, b, l, n, m):
    vis = [[False for i in range(m)] for j in range(n)]
    q = deque()
    q.append((a, b))
    vis[a][b] = True

    while (len(q) > 0):
        a, b = q.popleft()
        q.pop()

        for i in range(4):
            x = a + dx[i]
            y = b + dy[i]

            if (x >= 0 and x < n and y >= 0 and y < m and not vis[x][y]):
                q.append((x, y))
                vis[x][y] = True

def main():
    n, m = int(input().split())
    
    l = []
    for i in range(n):
        a = []
        for j in range(m):
            a.append(int(input()))
        l.append(a)
    
    start_point_a = 1
    start_point_b = 1

    bfs(start_point_a, start_point_b, l, n, m)    


if __name__ == '__main__':
    main()
from typing import List

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, u, v):
        pu = self.find(u)
        pv = self.find(v)

        if pu == pv:
            return False

        if self.size[pu] < self.size[pv]:
            pu, pv = pv, pu

        self.parent[pv] = pu
        self.size[pu] += self.size[pv]
        return True

    def connected(self, u, v):
        return self.find(u) == self.find(v)


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N = len(grid)
        dsu = DSU(N * N)

        positions = sorted(
            (grid[r][c], r, c)
            for r in range(N)
            for c in range(N)
        )

        directions = [(0,1), (1,0), (0,-1), (-1,0)]

        for t, r, c in positions:
            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if 0 <= nr < N and 0 <= nc < N and grid[nr][nc] <= t:
                    dsu.union(r * N + c, nr * N + nc)

            if dsu.connected(0, N * N - 1):
                return t
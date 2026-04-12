class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:


        n = len(points)
        visit = [False] * n
        dist = [float("inf")] * n
        edges = 0
        node = 0
        res =0 
        while edges < n - 1:
            visit[node] = True
            nextNode = -1

            for i in range(n):
                if visit[i]:
                    continue
                currentDist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1])

                dist[i] = min(dist[i], currentDist)
                if nextNode == -1 or dist[i] < dist[nextNode]:
                    nextNode = i

            res += dist[nextNode]
            node = nextNode
            edges+=1
        return res

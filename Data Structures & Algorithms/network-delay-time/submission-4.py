

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        graph = defaultdict(list)
        dist = {i: float('inf') for i in range(1, n + 1)}
        dist[k] = 0
        minHeap = [(0, k)]

        for u, v, w in times:
            graph[u].append((v, w))


        while minHeap:
            time, node = heapq.heappop(minHeap)
            for nei, weight in graph[node]:

                new_time = time + weight
   
                if new_time < dist[nei]:
                    dist[nei] = new_time
                    heapq.heappush(minHeap, (new_time, nei))

        max_time = max(dist.values())

        if max_time == float('inf'):
            return -1

        return max_time

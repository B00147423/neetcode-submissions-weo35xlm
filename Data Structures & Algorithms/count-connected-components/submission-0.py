class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        visit = [False] * n
        adj  = {}
        for i in range(n):
            adj [i] = []

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(node):
            for nei in adj[node]:
                if not visit[nei]:
                    visit[nei] = True
                    dfs(nei)
        

        countComponent = 0

        for node in range(n):
            if not visit[node]:
                visit[node] = True
                dfs(node)
                countComponent +=1
        return countComponent

        

        
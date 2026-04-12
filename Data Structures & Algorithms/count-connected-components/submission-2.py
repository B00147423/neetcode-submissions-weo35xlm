class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]

        visit = [False] * n
        ## build adj list
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

            
        #dfs
        def dfs(node):
            for neighbors in adj[node]:
                if not visit[neighbors]:
                    visit[neighbors] = True
                    dfs(neighbors)
        

        res = 0
        for node in range(n):
            if not visit[node]:
                visit[node] = True
                dfs(node)
                res+=1
        return res
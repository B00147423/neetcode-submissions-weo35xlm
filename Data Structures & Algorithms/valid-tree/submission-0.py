class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        '''

          0
        / | \
        1  2  3
        |
        4 

          0
          |
          1
        / | \
       2 -3  4 = CYCLE BECAUSE 1- ALSO 2-3 WE ALRREADY VISITED WITH 2 - 3 
 
        '''

        if len(edges) > (n - 1):
            return False

        adj = {}
        for i in range(n):
            adj[i] = []

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            print(adj)


        visit = set()


        def dfs(node, par):
            if node in visit:
                return False

            visit.add(node)
            
            for nei in adj[node]:
                if nei == par:
                    continue
                if not dfs(nei, node):
                    return False
            return True
        return dfs(0, -1) and len(visit) == n


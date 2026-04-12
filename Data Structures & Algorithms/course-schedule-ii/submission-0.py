class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        preMap = {}
        for i in range(numCourses):
            preMap[i] = []


        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        visited = set()
        visiting = set()
        result = []
        def dfs(crs):
            if crs in visiting:
                return False  # Cycle detected
            if crs in visited:
                return True

            visiting.add(crs)
            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            visiting.remove(crs)
            visited.add(crs)
            result.append(crs)
            return True
        
        for crs in range(numCourses):
            if not dfs(crs):
                return []
        
        return result


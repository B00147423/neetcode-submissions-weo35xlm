class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {}  # Empty dictionary

        for i in range(numCourses):
            preMap[i] = []  # Initialize each course with empty list
            print(preMap)

        for crs, pre in prerequisites:
            preMap[crs].append(pre)
       

            # Store all courses along the current DFS path
        visiting = set()

        def dfs(crs):
            if crs in visiting:
                return False
            if preMap[crs] == []:
                return True

            visiting.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            visiting.remove(crs)
            preMap[crs] = []
            return True


        for c in range(numCourses):
            if not dfs(c):
                return False
        return True



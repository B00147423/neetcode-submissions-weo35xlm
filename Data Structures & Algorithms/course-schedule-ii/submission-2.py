class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        result = []
        graph = []
        visited = set()
        path = set()

        for i in range(numCourses):
            graph.append([])

        for course, prereq in prerequisites:
            graph[prereq].append(course)

        def dfs(currNode):

            if currNode in path:
                return False
            if currNode in visited:
                return True
                
            path.add(currNode)

            for neighbor in graph[currNode]:
                if not dfs(neighbor):
                    return False

            path.remove(currNode)
            visited.add(currNode)
            result.append(currNode)
            return True

        for i in range(numCourses):
            if not dfs(i):
                return []
        result.reverse()
        return result
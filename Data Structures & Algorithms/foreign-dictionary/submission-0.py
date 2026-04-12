class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj = {}
        #ADJ LIST
        for w in words:
            for c in w:
                adj[c] = set()

        for i in range(len(words) - 1):
            word1 = words[i]
            word2 = words[i + 1]
            minLen = min(len(word1), len(word2))
            if len(word1) > len(word2) and word1[:minLen] == word2[:minLen]:
                return ""
            for j in range(minLen):
                if word1[j] != word2[j]:
                    adj[word1[j]].add(word2[j])
                    break
            
        visited = {}

        res = []

        def dfs(char):
            if char in visited:
                return visited[char]

            visited[char] = True

            for neighbor in adj[char]:
                if dfs(neighbor):
                    return True

            visited[char] = False
            res.append(char)
        
        for char in adj:
            if dfs(char):
                return ""
        res.reverse()
        return "".join(res)
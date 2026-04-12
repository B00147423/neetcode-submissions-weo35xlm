class Solution {
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     /*
     prerequisites[i] = [a, b] = u must take course b to take course a.

     The pair [0, 1], indicates that must take course 1 before taking course 0.
     */   

        for(int i = 0; i < numCourses; i++){
            preMap[i] = {}; 
        }

        for(const auto& prereq : prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }


    bool dfs(int crs) {
        // if this course is already in the recursion stack, cycle found
        if (visiting.count(crs)) return false;

        // if no prerequisites, it's fine
        if (preMap[crs].empty()) return true;

        // mark this course as "currently exploring"
        visiting.insert(crs);

        // explore prerequisites
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) return false;
        }

        // finished exploring this course
        visiting.erase(crs);

        // memoize result: mark course as having no prerequisites anymore
        preMap[crs].clear();

        return true;
    }
};

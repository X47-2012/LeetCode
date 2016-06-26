class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            inDegree[p.first] += 1;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int x = 0;
        while (true) {
            if (q.empty()) {
                break;
            }
            int a = q.front();
            q.pop();
            x += 1;
            for (auto i : graph[a]) {
                inDegree[i] -= 1;
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (x < numCourses) {
            return false;
        } else {
            return true;
        }
    }
};
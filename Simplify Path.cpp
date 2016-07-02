class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        for (auto i = path.begin(); i != path.end(); ) {
            i++;
            auto j = find(i, path.end(), '/');
            string dir = string(i, j);
            if (dir != "" && dir != ".") {
                if (dir == "..") {
                    if (dirs.size() > 0) {
                        dirs.pop_back();
                    }
                } else {
                    dirs.push_back(dir);
                }
            }
            i = j;
        }
        
        stringstream out;
        if (dirs.empty()) {
            out << "/";
        } else {
            for (auto dir : dirs) {
                out << "/" << dir;
            }
        }
        return out.str();
    }
};
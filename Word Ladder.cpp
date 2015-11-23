#include <unordered_set>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

unordered_set<char> char_set;

struct Node {
    string str;
    int level;
    Node(string p_str, int p_level): str(p_str), level(p_level) {}
};

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    if (beginWord == endWord)
        return 1;

    wordList.insert(endWord);

    for (auto it = wordList.begin(); it != wordList.end(); ++it) {
		string tmp = *it;
		for (int i = 0; i < tmp.size(); i++) {
			char_set.insert(tmp[i]);
		}
	}

    wordList.erase(beginWord);
    wordList.erase(endWord);

    queue<Node *> q;

    Node *node = new Node(beginWord, 1);
    q.push(node);

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        string curr = node->str;

        char * c_str = (char *) curr.data();
        for (auto it = char_set.begin(); it != char_set.end(); ++it) {
            for (int i = 0; i < curr.size(); i++) {
                char tmp_ch = curr[i];
                if (tmp_ch == *it)
                    continue;

                c_str[i] = *it;

                string new_str(c_str);

                if (new_str == endWord) {
                    return node->level + 1;
                }

                if (wordList.find(new_str) != wordList.end()) {
                    Node *tmp_node = new Node(new_str, node->level + 1);
                    q.push(tmp_node);
                    wordList.erase(new_str);
                }
                c_str[i] = tmp_ch;
            }
        }
    }
    return 0;
}

int main() {
    string strs[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordList(strs, strs + 5);
    cout << ladderLength("hit", "cog", wordList);
}

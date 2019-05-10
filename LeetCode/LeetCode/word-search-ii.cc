#include<unordered_map>

using namespace std;

class Solution { 
private:
    struct TrieNode {
        bool isString = false;
        unordered_map<char, TrieNode*> leaves;

        bool Insert(const string& s) {
            auto *p = this;
            for (const auto& c : s ) {
                if(p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }

            if(p->isString) {
                return false;
            } else {
                p->isString = true;
                return true;
            }
        }

        ~TrieNode() {
            for (auto &kv : leaves) {
                if(kv.second) {
                    delete kv.second;
                }
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string>& words) {
        unordered_set<string> ret;

    }
};

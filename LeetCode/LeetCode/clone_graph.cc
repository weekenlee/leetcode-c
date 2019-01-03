#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraph(int x) : label(x) {}
};

class Solution {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode *> map;
    void dfs(UndirectedGraphNode *node) {
        if(map.find(node) != map.end()) return;
        map[node] = new UndirectedGraphNode(node->label);
        for(UndirectedGraphNode *neighbor : node->neighbors) {
            dfs(neighbor);
            map[node]->neighbors.push_back(map[neighbor]);
        }
    }

    public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        dfs(node);
        return map[node];
    }
};

#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>

void printUndirectedGraph(UndirectedGraphNode *node) {
    std::ostringstream out;
    std::unordered_map<int,std::unordered_set<int>> map{0,std::unordered_set<int>(){}};
}

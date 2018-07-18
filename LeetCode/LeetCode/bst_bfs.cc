#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode *root) {
            vector<vector<int>> result;
            queue<TreeNode*> que;

            if(root != nullptr) {
                que.emplace(root);
            }

            while(!que.empty()) {
                vector<int> level;
                int size = que.size();
                for(int i = 0 ; i < size; i++) {
                    auto *front = que.front();
                    que.pop();
                    level.emplace_back(front->val);
                    if(front->left != nullptr) {
                        que.emplace(front->left);
                    }
                    if(front->right != nullptr) {
                        que.emplace(front->right);
                    }
                }
                result.emplace_back(move(level));
            }
            return result;
        }
};

int main(void) 
{
    struct TreeNode root;
    root.val = 3;

    struct TreeNode node1[2];
    node1[0].val = 9;
    node1[1].val = 20;

    struct TreeNode node2[4];
    node2[2].val = 15;
    node2[3].val = 7;

    root.left = &node1[0];
    root.right = &node1[1];

    node1[0].left = NULL;
    node1[0].right = NULL;
    node1[1].left = &node2[2];
    node1[1].right = &node2[3];

    node2[0].left = NULL;
    node2[0].right = NULL;
    node2[1].left = NULL;
    node2[1].right = NULL;
    node2[2].left = NULL;
    node2[2].right = NULL;
    node2[3].left = NULL;
    node2[3].right = NULL;

    Solution s;
    vector<vector<int>> lists = s.levelOrder(&root);

    for(auto vt : lists) {
        for (auto item : vt) {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;
    }
 
    return 0;
}

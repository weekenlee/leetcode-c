#include <cstddef>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void flattern(TreeNode *root) {
            for(; root; root = root->right) {
                if(root->left) {
                    TreeNode *end = root->left;
                    while(end->right) {
                        end = end->right;
                    }
                    end->right = root->right;
                    root->right = root->left;
                    root->left = NULL;
                }
            }
        }
};

int main() {
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);

    root.left = &node1;
    root.right = &node4;
    node1.left = &node2;
    node2.right = &node3;
    node4.right = &node5;

    Solution s;
    s.flattern(&root);

    for(TreeNode *p = &root;  p;  p=p->right) {
        cout << p->val << " ";
    }
    cout << endl;
}

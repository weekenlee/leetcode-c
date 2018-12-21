#include <cstddef>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxPathSum(TreeNode *root, int &maxSum) {
        if(!root) return 0;
        int leftMax = std::max(0, maxPathSum(root->left, maxSum));
        int rightMax = std::max(0, maxPathSum(root->right, maxSum));
        maxSum = std::max(maxSum, leftMax + rightMax + root->val);
        return root->val + std::max(leftMax, rightMax);
    }

    public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};


#include <iostream>

int main()
{
    Solution s;
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);
                        
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;
                                            
    std::cout << s.maxPathSum(&root) << std::endl;
}

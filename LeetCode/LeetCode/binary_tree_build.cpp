#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct Solution {
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, size_t> in_entry_idx_map;
            for(size_t i = 0; i < inorder.size(); ++i) {
                in_entry_idx_map.emplace(inorder[i], i);
            }
            return ReconstructPreInOrdersHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size(),in_entry_idx_map);
        }

        TreeNode *ReconstructPreInOrdersHelper(const vector<int>& preorder, size_t pre_s, size_t pre_e, 
                const vector<int>& inorder, size_t in_s, size_t in_e, 
                const unordered_map<int, size_t>& in_entry_idx_map) {
            if(pre_s == pre_e || in_s == in_e) {
                return nullptr;
            }

            auto idx = in_entry_idx_map.at(preorder[pre_s]);
            auto left_tree_size = idx - in_s;

            auto node = new TreeNode(preorder[pre_s]);
            node->left = ReconstructPreInOrdersHelper(preorder, pre_s+1, pre_s+1+left_tree_size,
                    inorder, in_s, idx, in_entry_idx_map);
            node->right = ReconstructPreInOrdersHelper(preorder, pre_s+1+left_tree_size,pre_e,
                    inorder, idx+1,in_e, in_entry_idx_map);
            return node;
        }
};

void PrintHelper(TreeNode *root)
{
    if(root != NULL) {
        printf("%d ", root->val);
        PrintHelper(root->left);
        PrintHelper(root->right);
    }
}

int main() {
    vector<int> pre{1,2,3};
    vector<int> in{2,1,3};
    Solution s;
    TreeNode *root = s.buildTree(pre, in);
    PrintHelper(root);
    return 0;
}

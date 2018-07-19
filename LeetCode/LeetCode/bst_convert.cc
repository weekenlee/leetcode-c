#include<iostream>
#include<vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int> &nums) {
            return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
        }
    private:
        TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
            if(start <= end) {
                TreeNode *node = new TreeNode(nums[start]+(end - start)/2);
                node->left = sortedArrayToBSTHelper(nums,start, start + (end - start)/2 -1 );
                node->right = sortedArrayToBSTHelper(nums,start+(end-start)/2+1 , end);
                return node;
            }
            return nullptr;
        }
};

void PrintHelper(TreeNode *root)
{
    if(root != NULL) {
        PrintHelper(root->left);
        printf("%d \n", root->val);
        PrintHelper(root->right);
    }
}

int main(void) 
{
    Solution s;
    vector<int> v = {1,2,3,4,5,6};
    PrintHelper(s.sortedArrayToBST(v));
    return 0;
}

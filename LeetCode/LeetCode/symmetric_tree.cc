#include<cstddef>
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root == NULL) return true;
            TreeNode *lt = root->left, *rt = root->right;
            for(std::stack<TreeNode*> stack; !stack.empty()||(lt&&rt);) {
                if(lt && rt) {
                    if(lt->val != rt->val) return false;
                    stack.push(lt->right);
                    stack.push(rt->left);
                    lt = lt->left;
                    rt = rt->right;
                } else if (lt || rt ) {
                    return false;
                } else {
                    lt = stack.top();
                    stack.pop();
                    rt = stack.top();
                    stack.pop();
                }
            }

            if(lt||rt) return false;
            else return true;
        }
};


int main(void) {
    #if 1
    struct TreeNode root, n10, n11, n20, n21, n22, n23;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n20.val = 3;
    n21.val = 4;
    n22.val = 4;
    n23.val = 3;
    root.left = &n10;
    root.right = &n11;
    n10.left = &n20;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = &n23;
    n20.left = NULL;
    n20.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
    n23.left = NULL;
    n23.right = NULL;
#else
    TreeNode root, n10, n11, n21, n22;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n21.val = 3;
    n22.val = 4;
    root.left = &n10;
    root.right = &n11;
    n10.left = NULL;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
#endif
    printf("%s\n", Solution().isSymmetric(&root) ? "true" : "false");
    return 0;
}


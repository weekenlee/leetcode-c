#include<cstddef>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    public:
        BSTIterator(TreeNode *root) : cur_(root) {
            
        }

        bool hasNext() {
            return !s_.empty() || cur_ != nullptr;
        }

        int next() {
            while (cur_ != nullptr) {
                s_.emplace(cur_);
                cur_ = cur_->left;
            }
            cur_ = s_.top();
            s_.pop();

            const auto *node = cur_;
            cur_ = cur_->right;

            return node->val;
        }

    private:
        stack<TreeNode *> s_;
        TreeNode *cur_;
};

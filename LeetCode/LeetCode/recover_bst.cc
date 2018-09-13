#include<iostream>
#include<utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void recoverTree(TreeNode *root) {
            MorrisTraversal(root);
        }
    private:
        void MorrisTraversal(TreeNode *root) {
            if (!root) {
                return;
            }
            pair<TreeNode*, TreeNode*> broken;
            broken.first = NULL;
            broken.second= NULL;
            cout<<&broken.first<<endl;
            cout<<&broken.second<<endl;
            TreeNode *prev = nullptr;
            TreeNode *cur = root;
            while(cur) {
                if(!cur->left) {
                    detect(prev, cur, &broken);
                    prev=cur;
                    cur = cur->right;
                }else {
                    TreeNode *node = cur->left;
                    while(node->right && node->right != cur) {
                        node = node->right;
                    }
                    if(!node->right) {
                        node->right = cur;
                        cur = cur->left;
                    }else {
                        detect(prev, cur, &broken);
                        prev = cur;
                        node->right = nullptr;
                        cur = cur->right;
                    }
                }
            }
            cout<<&broken.first<<endl;
            cout<<&broken.second<<endl;
            if (broken.first&&broken.second) {
                swap(broken.first->val, broken.second->val);
            }
        }

        void detect(TreeNode *prev, TreeNode *cur, pair<TreeNode*, TreeNode*> *broken) {
            if(prev && prev->val > cur->val) {
                if(!broken->first) {
                    cout<<"赋值first"<<endl;
                    broken->first = prev;
                }
                cout<<"赋值second"<<endl;
                broken->second = cur;
            }
        }
};

int main(void) 
{   
    TreeNode root(2);
    TreeNode left(3);
    TreeNode right(1);

    cout <<&root<<endl;
    cout <<&root.left<<endl;
    cout <<&root.right<<endl;
    cout <<&right<<endl;
    cout <<&right.left<<endl;
    cout <<&right.right<<endl;
    cout <<&left<<endl;
    cout <<&left.left<<endl;
    cout <<&left.right<<endl;
    cout <<endl;

    root.left = &left;
    root.right = &right;

    Solution s;
    s.recoverTree(&root);
    printf("%d %d %d\n", root.val, left.val, right.val);
}

#include<stack>
#include<cstddef>
#include<iostream>
#include<vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL),right(NULL), next(NULL) {}
};

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL) return;
            while(root->left) {
                root->left->next = root->right;//左子树
                for(TreeLinkNode *cur = root; cur->next; cur = cur->next) {
                    cur->right->next = cur->next->left;//外连接
                    cur->next->left->next = cur->next->right;//右子树
                }
                root = root->left;
            }
        }
};

TreeLinkNode *createBinaryTree(vector<int>::iterator beg, vector<int>::iterator end) {
    vector<TreeLinkNode *> vec;
    for(auto it = beg; it != end; ++it) {
        vec.push_back(new TreeLinkNode(*it)); 
    }

    for(int i = 0, pos = 0; pos != vec.size()-1; ++i) {
        vec[i]->left = vec[++pos];
        vec[i]->right = vec[++pos];
    }
    return *vec.begin();
}

void print(TreeLinkNode *root) {
    while(root) {
        cout << root->val;
        TreeLinkNode *cur = root->next;
        while(cur) {
            cout << "->" << cur->val;
            cur = cur->next;
        }
        cout << endl;
        root = root->left;
    }
}

int main() 
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeLinkNode *root = createBinaryTree(vec.begin(),vec.end());
    Solution s;
    s.connect(root);
    print(root);
    return 0;
}

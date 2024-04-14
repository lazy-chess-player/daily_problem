#include <iostream>

struct node
{
    int val;
    node *left;
    node *right;
    node() : val(0), left(nullptr), right(nullptr) {}
    node(int x) : val(x), left(nullptr), right(nullptr) {}
    node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    node *sufficientSubset(node *root, int limit)
    {
        limit -= root->val;
        if (root->left == root->right)
            return limit > 0 ? nullptr : root;
        if (root->left)
            root->left = sufficientSubset(root->left, limit);
        if (root->right)
            root->right = sufficientSubset(root->right, limit);
        return root->left || root->right ? root : nullptr;
    }
};
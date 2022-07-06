/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root || !root->left)
            return root;

        Node *toReturn = root, *previous=root, *current = root;

        while (current->left)
        {
            previous = current;
            root = current = current->left;

            while ( previous->left==root || previous->right ==root )
            {
                if (root == previous->left)
                    root->next = previous->right;
                if (root == previous->right&&previous->next)
                {
                    root->next = previous->next->left;
                    previous = previous->next;
                }
                   
                root = root->next;
            }
        }

        return toReturn;
    }
};
/**
 * @file inorder_successor_in_binary_search_tree.cpp
 * @author Zhijie Xia (zhijiexiacs@gmail.com)
 * @brief In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. Inorder Successor is NULL for the last node in Inorder traversal.  
 * In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of the input node. So, it is sometimes important to find next node in sorted order. 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */



class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // if there is right subtree
        if(node->right)
        {
            node = node->right;
            while(node->left)
                node = node->left;
            return node;
        }

        // the parent is keeping decreasing, until find the parent that is 
        // a right child of an ancestor
        while(node->parent && node!=node->parent->left)
        {   
            node = node->parent;
        }

        return node->parent;
    }
};


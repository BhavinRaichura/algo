 Count BST nodes that lie in a given range
 https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
/*
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

    The values smaller than root go to the left side
    The values greater and equal to the root go to the right side

Example 1:
Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the range

Example 2:

Input:
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the given range.

Your Task: This is a function problem. You don't have to take input. You are required to complete the function getCountOfNode() that takes root, l ,h as parameters and returns the count.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST).

*/

class Solution{

    int getCount(Node *root, int l, int h)
    {
       
        int cnt = 0;
        if(root == NULL) return 0;
        
        if(root->data>=l && root->data<=h){
            cnt++;
        }
        
        // if root's data is greater then the renge[l,h],
        // then we traverse only for left child of that node because every node in left side is smaller then root
        if(root->data>=h){
            return cnt + getCount(root->left,l,h);
        }
        
        // if root's data is smaller then the renge[l,h],
        // then we traverse only for right child of that node because every node in left side is greater then root
        if(root->data<=l){
            return cnt + getCount(root->right,l,h);
        }
        
        // if root's data is lie between the range then we traverse for both child
        return cnt + getCount(root->left,l,h) + getCount(root->right,l,h);
      
    }
};

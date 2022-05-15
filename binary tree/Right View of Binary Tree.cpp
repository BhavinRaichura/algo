/*

Right View of Binary Tree
https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2

Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60

Your Task:
Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
  */
  
class Solution
{
    private:
    vector<int> ans;
    public:
    //Function to return list containing elements of right view of binary tree.
    void rights(Node*root,int level){
        if (root==NULL)return;
        if (ans.size()==level){
            ans.push_back(root->data);
        }
        rights(root->right,level+1);
        rights(root->left,level+1);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       rights(root,0);
       return ans;
    }
};

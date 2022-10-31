#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int findFloor(Node* node ,int target)
{
    int floor;
     while( node!=NULL)
     {
         if(node->data==target)
         return target;
         if(node->data < target){
         floor=node->data;    
         node=node->right;
         }
         else
         node=node->left;
     }
    
      return floor;
}

int main(){
    struct Node* root=new Node(10);
    root->left=new Node(6);
    root->right=new Node(14);
    root->left->left=new Node(4);
    root->left->right=new Node(9);
    root->right->left=new Node(12);
    root->right->right=new Node(15);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(7);
    root->right->left->left=new Node(11);

    cout<<(findFloor(root, 13));
  
    return 0;

}

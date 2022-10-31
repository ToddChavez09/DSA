
package BST;

class searchForKeyInBST {

    public class Node {
        int val;
        Node left;
        Node right;
    
        Node(){}
        
        Node(int val){
            this.val = val;
        }
    
        Node (int val, Node left, Node right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    
    public boolean searchBST (int key, Node root) {
        if(root == null) {
            return false;
        }
    
        if (root.val == key) {
            return true;
        }
    
        //search left tree
        boolean leftSearch = searchBST(key, root.left);
    
        //search right tree
        boolean rightSearch = searchBST(key, root.right);
    
        return leftSearch || rightSearch;
    }
    

}    

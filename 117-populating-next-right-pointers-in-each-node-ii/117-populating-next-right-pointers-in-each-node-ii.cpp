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

class Solution {
public:
    
    void solve(Node* node){
        if (node == NULL) return;
        
        queue<Node *> q;
        stack<Node *> st;
        
        q.push(node);
        st.push(node);
        
        Node* rightNode = NULL;
        
        while(q.empty() == false){
            int levelSize = q.size();

            Node* rightNode = NULL;
            
            while(st.empty() == false){
                Node* currentNode = st.top();
                
                currentNode->next = rightNode;
                
                rightNode = currentNode;
                
                st.pop();
            }
            
            
            while(levelSize > 0){
                Node* currentNode = q.front();
                q.pop();
                st.push(currentNode);
                
                if(currentNode->left != NULL) q.push(currentNode->left);
                if(currentNode->right != NULL) q.push(currentNode->right);
                
                levelSize--;
            }
            
        }
        
        while(st.empty() == false){
            Node* currentNode = st.top();

            currentNode->next = rightNode;

            rightNode = currentNode;

            st.pop();
        }
    }
    
    Node* connect(Node* root) {
        
        solve(root);
        
        return root;
        
    }
};
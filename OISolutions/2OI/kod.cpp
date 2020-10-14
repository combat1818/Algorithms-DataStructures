// C program to insert a node in AVL tree 
#include<stdio.h> 
#include<stdlib.h>
#include<iostream> 
using namespace std;   
// An AVL tree node 
struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height;
	int t_size,lt_size, rt_size; 
};
int B[30001];
int A[30001]; 
  
// A utility function to get maximum of two integers 
int max(int a, int b); 
  
// A utility function to get the height of the tree 
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
// A utility function to get maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf
	node->t_size=0; 
    node->lt_size=0;
    node->rt_size=0;
    return(node); 
} 
  
// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
    
	y->lt_size= (y->left==NULL) ? 0:y->left->t_size+1;
    y->rt_size= (y->right==NULL) ? 0:y->right->t_size+1;
    y->t_size=y->lt_size + y->rt_size;
  //  
    x->lt_size= (x->left==NULL) ? 0:x->left->t_size+1;
	x->rt_size= (x->right==NULL) ? 0:x->right->t_size+1;
    x->t_size=x->lt_size + x->rt_size;
    
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1;
	
	x->lt_size= (x->left==NULL) ? 0:x->left->t_size+1;
	x->rt_size= (x->right==NULL) ? 0:x->right->t_size+1;
    x->t_size=x->lt_size + x->rt_size; 
    
    y->lt_size= (y->left==NULL) ? 0:y->left->t_size+1;
    y->rt_size= (y->right==NULL) ? 0:y->right->t_size+1;
    y->t_size=y->lt_size + y->rt_size;
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* insert(struct Node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key){
    	node->left  = insert(node->left, key);
		if(node->left!=NULL)	node->lt_size=node->left->t_size+1;
		if(node->right!=NULL)	node->rt_size=node->right->t_size+1;
  		node->t_size=node->lt_size + node->rt_size;
	} 
    else if (key > node->key){
    	node->right = insert(node->right, key);
		if(node->left!=NULL)	node->lt_size=node->left->t_size+1;
		if(node->right!=NULL)	node->rt_size=node->right->t_size+1;
  		node->t_size=node->lt_size + node->rt_size; 
	} 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
}


/* Given a non-empty binary search tree, return the 
   node with minimum key value found in that tree. 
   Note that the entire tree does not need to be 
   searched. */
struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
// Recursive function to delete a node with given key 
// from subtree with given root. It returns root of 
// the modified subtree. 
struct Node* deleteNode(struct Node* root, int key) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
  
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key < root->key ){
        root->left = deleteNode(root->left, key);
        root->lt_size= (root->left==NULL) ? 0:root->left->t_size+1;
		root->rt_size= (root->right==NULL) ? 0:root->right->t_size+1;
  		root->t_size=root->lt_size + root->rt_size;
	} 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key > root->key ){
    	root->right = deleteNode(root->right, key); 
    	root->lt_size= (root->left==NULL) ? 0:root->left->t_size+1;
		root->rt_size= (root->right==NULL) ? 0:root->right->t_size+1;
  		root->t_size=root->lt_size + root->rt_size;
	} 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct Node *temp = root->left ? root->left : 
                                             root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
	//		  root->lt_size=0;
	////		  root->rt_size=0;
	//		  root->t_size=0;	             
                            // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct Node* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->key = temp->key; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->key);
            
			root->lt_size= (root->left==NULL) ? 0:root->left->t_size+1;
			root->rt_size= (root->right==NULL) ? 0:root->right->t_size+1;
  			root->t_size=root->lt_size + root->rt_size; 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
}

bool b(int k, int a, int b){
	if(a<=k && k<=b) return true;
	else return false;
}

int find_kth(int key, Node* current){
	int out;
	if(current==NULL) return -1;
	 
	if(key==current->lt_size+1)
		return current->key;
	else if(key<=current->lt_size)
		out=find_kth(key,current->left);
	else
		out=find_kth(key-(current->lt_size+1), current->right);
	return out;		 	
}  
  
// A utility function to print preorder traversal 
// of the tree. 
// The function also prints height of every node 
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
		cout<<"root->key= "<<root->key<<" tree_size= "<<root->t_size<<" lt_size= "<<root->lt_size<<" rt_size= "<<root->rt_size<<endl;
 //       printf("%d ", root->key);
 		cout<<"z lewa  "; 
        preOrder(root->left); 
        cout<<"z prawa  ";
        preOrder(root->right); 
    } 
} 
  
/* Drier program to test above function*/
int main() 
{ 
    struct Node *root = NULL;
    int n,i,x,size;
    cin>>n;
    size=n;
	for(i=1;i<=n;i++){
		root=insert(root,i);
		cin>>B[i];
	}
	i=n;
	int z;
    string s;
 //   cin>>s;
    while(i>0){
    //	cin>>s; //x=B[I]
    //	 if(s=="z"){
    		if(size-B[i]<=0){
    			cout<<"NIE";
    			return 0;
			}	
			A[i]=find_kth(size-B[i],root);
			z=find_kth(size-B[i],root);
			size--;
			i--;
	//	}
	//	else if(s=="u"){
	//		cin>>x;
			root=deleteNode(root,z);
		}
	
//	for(i=1;i<=n;i++){
//		cin>>x;
//		cout<<find_kth(x,root);
//	}*/
	

//	cout<<endl;
	for(i=1;i<=n;i++)
		cout<<A[i]<<endl;

//	preOrder(root);  */
  

}
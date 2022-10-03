// Implementing a Binary Search Tree
#include<iostream>
#include<queue>
using namespace std;

// Node class to create a node
class Node{
	
	public:
		int data;
		Node* left;
		Node* right;
	
		// Constructor Function
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

// Here, in our 'insertIntoBST()' We'll be processing the data user gave in 'takeInput()' to make insertion at the correct Place in our BST, And Once the Correct Insertion has been Made this function returns the root Node of our BST.
Node* insertIntoBST(Node* root, int data){
	// BASE CASE
	// Root is a NULL node [in this case it means that our tree doesn't even exists at all!]
	// For this case, we'll be making a New Node for our BST, & root gets updated with this newly created Node & we'll return the same Back
	if(root == NULL){
		root = new Node(data);
		return root;
	}
	
	// Now, we Do our checks for insertion.
	// Is our data bigger than the root Node's data?
	// if yes, then make an insertion to the right. [Satisfying the property of a BST]
	// if no, then make an insertion the the left. [Again, done to satisfy a BST's Property]
	if( data > root->data ){
		// Insert there in the Right Part.
		// Here, we pass 'root->right' into the 'insertIntoBST()' Function because that's the root of the tree Now we have to insert our data Node into!
		root->right = insertIntoBST( root->right , data );	
	}
	else{
		// Insert there in the Left Part.
		// Here, we pass 'root->left' into the 'insertIntoBST()' Function because that's the root of the tree Now we have to insert our data Node into
		root->left = insertIntoBST( root->left , data );
	}
	
	// Now, After Making the Correct Insertion,
	// We'll have to return the Complete Tree's Root Node
	return root;
	
}
// 'takeInput()' takes the Input from the user regarding the data they wish to Enter into our BST
// Root Parameter has been passed by reference here because of the fact that the function takeInput Has been made 'void' type & therefore we make the changes only in this 'root' parameter that get reflected in our calling function.
void takeInput(Node* &root){
	int data;
	cin>>data;
	
	// '-1' input for Node creation is considered to be the terminating case
	while(data!=-1){
		root = insertIntoBST( root , data );
		
		// Take input data for the next Node
		cout<<"\nEnter the Next Node's data: ";
		cin>>data;
	}
}

// Function returning the node with the Minimum value in our BST
Node* findMin(Node* root){
	
	if(root == NULL){
		return NULL;
	}
	
	Node* temp = root;
	
    // For a BST, Due to its property the Minimum Node would be found there on the leftmost side of the tree
    // Because of this, we'll be traversing to the leftmost Node of our BST
	while(temp->left!=NULL){
		temp = temp->left;
	}
	
	// Here temp would be pointing to our Minimum Data Node
	return temp;
}

// Function returning the node with the Maximum value in our BST
Node* findMax(Node* root){
	
	if(root == NULL){
		return NULL;
	}
	
	Node* temp = root;
	
    // For a BST, Due to its property the Maximum Node would be found there on the leftmost side of the tree
    // Because of this, we'll be traversing to the Rightmost Node of our BST
	while(temp->right!=NULL){
		temp = temp->right;
	}
	
	// Here temp would be pointing to our Maximum Data Node
	return temp;
}

// Deleting the Node from our BST
Node* deleteFromBST(Node* root, int val){
	
	// BASE CASE
	if(root == NULL){
		return NULL;
	}
	
	// OUR PRIORITY IS TO FIND THE NODE FIRST that has to be deleted!
	// Our current Node is the one with the 'target value'
	if( root->data == val ){
		// We got the Root Node with the target value!
		// Now, we look out for those 4 cases
		
		// Case 1 -> Node is a leaf node
		if( root->left == NULL && root->right == NULL ){
			// free current Node's Memory & return NULL
			delete root;
			return NULL;
		}
		
		// Case 2 -> Node has just one child
		// Left Child
		if( root->left == NULL ){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		
		// Right Child
		if( root->right == NULL ){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		
		// Case 3 -> Node has two children
		if( root->left!=NULL && root->right!=NULL ){
			// For such a case you can either find the Maximum value from the left subtree or the Minimum value from the right subtree
			// You can do it as per your wish.
			
			int mini = findMin(root->right);
			// int maxi = findMax(root->left);
			
			// -> Now copy this mini/maxi value into your root Node
			root->data = mini;
			
			// Now we need to delete this mini/maxi value from our BST because it's already been copied into our root Node
			// AND we've made its replacement at the correct place!
			root->right = deleteFromBST( root->right , mini );
			
			// Let's say if you took maxi value, then the function call would look something like this [We'll pass the root node as the left-Subtree's root Node since that's the portion we've found this maxi from]
			// root->left = deleteFromBST( root->left , maxi );			
		}
	}else if( root->data > val ){
		// Current Node's data is greater than the target value
        // So, we'll be looking for the target value in the left subtree
		root->left = deleteFromBST( root->left , val );
	}else if( root->data < val ){
        // Current Node's data is smaller than the target value
        // So, we'll be looking for the target value in the right subtree
		root->right = deleteFromBST( root->right , val );
	}
	
	return root;	
}

// BST TRAVERSALS
void levelOrderTraversal(Node* root){
	// Also called 'Breadth First Search'
	// We use a Queue for its implementation
	queue<Node*> q;
	
    // Firstly, we push the root Node into the queue
    // Because from here we'll be starting our traversal
	q.push(root);
	
	// In order for us to give the output in a tree format - we're required to use a separator
	// The seperator that we've decided to use is 'NULL'.
	// Whenever, we encounter NULL, we're going to 'endl' and move to the next line for our Next level's output printing.
	q.push(NULL);
	
	// We work until the queue isn't empty.
	while(!q.empty()){
		// Find the node in hand first which has to be currently dealt with.
		Node* temp = q.front();
		
        // Now, we've dealt with the current node in hand, so we pop it out
		q.pop();
		
        // We check first if the current node is NULL or not
        // Because if it's a NULL, then we know that we've reached the end of the current level & is a separator

		if(temp == NULL){
			// Execute endl & push NULL into the queue
			cout<<endl;
			
			// Now, encountering this separator means that we've reached the end of the previously traversed level
			// Which also means that we've pushed all the child nodes from the previous level into our queue.
			// Therefore, we check whether the queue currently has any Nodes (for us to insert an another NULL Separator -> that caters to the next level.)
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			// Print the data of the current Node in hand
			cout<<temp->data<<" ";
			
            // if the current Node has a left child, then we push it into the queue
			// This below Statement works only if temp->left is NOT-NULL.
			if(temp->left){
				q.push(temp -> left);
			}
			
            // if the current Node has a right child, then we push it into the queue
			// This below Statement works only if temp->right is NOT-NULL.
			// In this manner We're traversing the Binary search tree Level Wise Inorder
			if(temp->right){
				q.push(temp -> right);
			}	
		} 
	}
}

// In-Order Traversal
void inOrder(Node* root){
	//Base case
	if(root == NULL){
		return;
	}
	
	// Left-Node-Right Format
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

// Pre-Order Traversal
void preOrder(Node* root){
	//Base case
	if(root == NULL){
		return;
	}
	
	// Node-Left-Right Format
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

// Post-Order Traversal
void postOrder(Node* root){	
	//Base case
	if(root == NULL){
		return;
	}
	
	// Left-Right-Node Format
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int main(){
	
	Node* root = NULL;
	
	cout<<"Enter the data to create BST: ";	
	takeInput(root);
	
	cout<<"\nLevel Order Traversal of our Binary Search Tree gives: \n";
	levelOrderTraversal(root);
	
	cout<<"\nIn-Order Traversal of our Binary Search Tree gives: \n";
	inOrder(root);
	
	cout<<"\nPre-Order Traversal of our Binary Search Tree gives: \n";
	preOrder(root);
	
	cout<<"\nPost-Order Traversal of our Binary Search Tree gives: \n";
	postOrder(root);
	
	cout<<"\nNode with the Minimum Value in our Binary Search Tree gives: \n";
	cout<<findMin(root)->data;
	
	cout<<"\nNode with the Maximum Value in our Binary Search Tree gives: \n";
	cout<<findMax(root)->data;	
}

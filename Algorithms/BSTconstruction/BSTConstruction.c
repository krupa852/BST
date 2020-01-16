#include<stdio.h>
#include<stdlib.h>

typedef struct node {
   	int value;
   	struct node *leftChild;
 	struct node *rightChild;
}node;


node *Newnode(int value) {
   	node *newNode = (node*)malloc(sizeof(node));
   	newNode->value = value;
   	newNode->leftChild = NULL;
   	newNode->rightChild = NULL;
   	return newNode;
}

// Find the index of value in arr
int search(int arr[], int start_index, int end_index, int value) {
   	int i;
   	for(i = start_index; i <= end_index; i++) {
         	if(arr[i] == value)
            	return i;
   	}
}


void inorderTraversal(node *p) {
   	if(p == NULL)
      		return;
   	else {
      		inorderTraversal(p->leftChild);
      		printf("%d\t",p->value);
      		inorderTraversal(p->rightChild);
   	}
}


node* constructBSTree(int inorder[],int preorder[],int inorder_start,int inorder_end){
   	static int preorder_index = 0;
   	if(inorder_start > inorder_end) 
         	return NULL;

   	// create a new node using the value in the current index of the preorder array
   	node *tree_node = Newnode(preorder[preorder_index++]);

   	// leaf node
   	if(inorder_start == inorder_end)
         return tree_node;

   	// Find the index of this node in the inorder array
   	int inorder_index = search(inorder,inorder_start,inorder_end,tree_node->value);

   	   
   	tree_node->leftChild = constructBSTree(inorder,preorder,inorder_start,inorder_index-1);
   	tree_node->rightChild = constructBSTree(inorder,preorder,inorder_index+1,inorder_end);

   	return tree_node;
}


int main() {
  	  	
	int n,inorder[20],preorder[20];
	//Enter length of inorder/preorder array
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&inorder[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&preorder[i]);
   	node *root = constructBSTree(inorder, preorder, 0, n-1);
   	printf("\n Inorder traversal of the constructed tree is \n");
   	inorderTraversal(root);
   	return 0;
}

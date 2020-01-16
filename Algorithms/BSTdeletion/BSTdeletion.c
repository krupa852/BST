#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int value;
    struct node *leftChild;
    struct node *rightChild;

};


struct node* NewNode(int data)
{
        struct node* newNode =(struct node*) malloc(sizeof(struct node));
        newNode->value =data;
        newNode->leftChild=NULL;
        newNode->rightChild=NULL;
        return newNode;
}

struct node* Insert(struct node* root,int data)
{
        if(root==NULL)
        {
                root = NewNode(data);
        }
        else if(data < root->value)
        {
                root->leftChild = Insert(root->leftChild,data);
        }
        else if(data > root->value)
        {
                root->rightChild = Insert(root->rightChild,data);
		
        }

        return root;
}

struct node* DeleteMin(struct node* currnode)
{
        if(currnode->leftChild==NULL)
        {
                return currnode;
        }
        return DeleteMin(currnode->leftChild);
}

struct node * deletenode(struct node* currnode, int data)
{
        if(currnode==NULL)
                return NULL;
        else if(data<currnode->value)
                currnode->leftChild = deletenode(currnode->leftChild, data);
        else if(data > currnode->value)
                currnode->rightChild = deletenode(currnode->rightChild, data);
        else
        {

                if(currnode->leftChild == NULL && currnode->rightChild == NULL)
                {
                        currnode = NULL;
                }
                else if(currnode->leftChild == NULL)
                {
                        currnode = currnode->rightChild;
                }
                else if(currnode->rightChild == NULL)
                {
                        currnode = currnode->leftChild;
                }
                else
                {
                       // currnode->value=DeleteMin(currnode->rightChild);
			struct node* temp = DeleteMin(currnode->rightChild);
			currnode->value = temp->value;
			currnode->rightChild = deletenode(currnode->rightChild,temp->value);
                }
        }
        return currnode;

}

int preorderprint(struct node* root)
{
    if(root==NULL){
        //printf("empty");
        return 0;}

    printf("%d ", root->value);

    preorderprint(root->leftChild);
    preorderprint(root->rightChild);

}
int main()
{
	struct node* root;
	root = NULL;
	int n,i,a[20],data;
//	printf("Enter number of nodes\n");
	scanf("%d",&n);
	if(n==0)
	{	printf("No elements to input\n");
		return 0;
	}
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		root = Insert(root,a[i]);
//	preorderprint(root);
//	printf("Enter value to be deleted\n");
	scanf("%d",&data);
	root = deletenode(root, data);
	preorderprint(root);
	return 0;

}


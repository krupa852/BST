#include<stdio.h>
#include<stdlib.h>

#define BLACK 'B'
#define RED   'R'

typedef struct node{
	char color;
	int value;
	struct node *leftChild;
	struct node *rightChild;
	struct node *parent;
}node;



struct node SenTNIL_Node;
node* TNIL=&SenTNIL_Node;


node* NewNode(int data)
{
        node* newNode =(node*) malloc(sizeof(node));
        newNode->value =data;
	newNode->color = RED;
        newNode->leftChild=NULL;
        newNode->rightChild=NULL;
	newNode->parent=NULL;
        return newNode;
}


int rotateLeft( node** T, node* x)
{
  	node *y  = x->rightChild;    
    	x->rightChild = y->leftChild;    
    	if(y->leftChild != TNIL)
        	y->leftChild->parent = x;
    	y->parent = x->parent;  
    	if(x->parent == TNIL)
       	*T = y;
    	else if(x == x->parent->leftChild)
       		x->parent->leftChild = y;
    	else
       		x->parent->rightChild = y;
    	y->leftChild = x;            
    	x->parent = y;
}

int rotateRight(node** T, node* y)
{
    	node *x  = y->leftChild;     
    	y->leftChild  = x->rightChild;   
    	if(x->rightChild != TNIL)
        	x->rightChild->parent = y;
    	x->parent = y->parent;  
    	if(y->parent == TNIL)
       		*T = x;
    	else if(y == y->parent->rightChild)
       		y->parent->rightChild = x;
    	else
       		y->parent->leftChild = x;
    	x->rightChild = y;         
    	y->parent = x;
}

int RB_InsertFixup(node** T, node* z)
{
	node* y;
	while(z->parent->color == RED)
	{
		if(z->parent->value == z->parent->parent->leftChild->value)
		{
			y = z->parent->parent->rightChild;
            		if(y->color == RED)
            		{	
                		z->parent->color = BLACK;
                		y->color = BLACK;
                		z->parent->parent->color = RED;
                		z = z->parent->parent;
            		}	
            		else{ 
				if(z->value == z->parent->rightChild->value)
            			{
                			z = z->parent;
                			rotateLeft(T,z);
            			}
            			z->parent->color = BLACK;
            			z->parent->parent->color = RED;
            			rotateRight(T,z->parent->parent);
			}
        	}	
        	else
        	{	
            		y = z->parent->parent->leftChild;
            		if(y->color == RED)
            		{	
                		z->parent->color = BLACK;
                		y->color = BLACK;
                		z->parent->parent->color = RED;
                		z = z->parent->parent;
            		}
            		else{
				 if(z == z->parent->leftChild)
            			 {
                			z = z->parent;
                			rotateRight(T,z);
            			 } 
            			z->parent->color = BLACK;
            			z->parent->parent->color = RED;
            			rotateLeft(T, z->parent->parent);
 	 		} 
		}
	}	
    	T[0]->color = BLACK;
	if(T[0]->parent==NULL)
	{
		T[0]->parent=TNIL;
	}
}


int RB_Insert(node** T,int data)
{
	node* x = *T;
	node* y = TNIL;
	node* z = NewNode(data);
	
	while(x!=TNIL)
	{
		y=x;
		if(z->value < x->value)
			x = x->leftChild;
       		else
			x = x->rightChild;
	}
	z->parent=y;
	if (y == TNIL)
       		*T = z;
	else if(z->value < y->value)
       		 y->leftChild = z;
    	else
        	 y->rightChild = z;

    
    	z->leftChild  = TNIL;
    	z->rightChild = TNIL;
    	z->color = RED;

        
    	RB_InsertFixup(T,z);
}


void RBT_print_dot_aux(node* node, FILE* stream)
{


     	if(node->leftChild != NULL)
    	{
		fprintf(stream, "    %d -> %d;\n", node->value, node->leftChild->value);
		if(node->color == 'R')
			fprintf(stream, " %d[fillcolor=red];\n",node->value);
        	RBT_print_dot_aux(node->leftChild, stream);
    	}
    

    	if(node->rightChild != NULL)
    	{
        	fprintf(stream, "    %d -> %d;\n", node->value, node->rightChild->value); 
	 	RBT_print_dot_aux(node->rightChild, stream);
    	}
	
  
}

void RBT_print_dot(node* tree, FILE* stream)
{
	stream=fopen("kd.dot", "w");
	fprintf(stream, "digraph RBT {\n");
	fprintf(stream, "  node [style=filled, color=black, shape=circle, fontname=Arial, fontcolor=white];\n");
    	if (!tree)
        	fprintf(stream, "\n");
    	else if (!tree->rightChild && !tree->leftChild)
        	fprintf(stream, "    %d;\n", tree->value);
    	else
 	{	if(tree->parent==TNIL)
    		{
     			fprintf(stream, "    %d -> 0;\n", tree->value);
    		}
      		RBT_print_dot_aux(tree, stream);
	}
    		fprintf(stream, "}\n");
    		fclose(stream);
    		system("dot -Tps -O kd.dot");
    		system("open kd.dot.ps &");

}

int main()
{
    	node* Root = TNIL;
	FILE *stream;
	int i,a[20],n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
    		RB_Insert(&Root,a[i]);
    	}

	RBT_print_dot(Root,stream);
    	
}

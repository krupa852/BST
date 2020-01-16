#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
};
 
struct node *head;

int Insertvaluetonode(int n)
{
	struct node *temp, *Newnode;
	int value,i;
	
	if(n<=0){
		printf("Number of nodes should be greater than zero\n");
		return 0;
	}
	head = (struct node *)malloc(sizeof(struct node));
	//printf("Enter the first node value: ");
        scanf("%d", &value);
	head->value = value; 
        head->next = NULL; 
	temp = head;
        
	for(i=2;i<=n;i++)
        {
		Newnode = (struct node*)malloc(sizeof(struct node)); 
              	//printf("Enter the value of node %d: ", i);
		scanf("%d", &value);
		Newnode->value = value; 
             	Newnode->next = NULL;
		temp->next = Newnode; 
             	temp = temp->next;
            
        }


        printf("Inserting values to linked list successful\n");
    
}

int displaylinkedlist() {

   	struct node *curr = head;

   	printf("\n(head) =>");
   	while(curr != NULL) {        
      		printf(" %d =>",curr->value);
      		curr = curr->next;
   	}	

   	printf(" null\n");
}

	
int reverselinkedlist()
{
        struct node *prevnode, *currnode;
        if(head!=NULL)
        {
                prevnode=head;
                currnode=head->next;
                head = head->next;
		prevnode->next = NULL;
		
		while(head!=NULL)
		{	
			head = head->next;
			currnode->next = prevnode;
			prevnode=currnode;
			currnode=head;
		}
		head = prevnode;
		printf("Reversed linkedlist successful\n");
	}
}

int main()
{       
        int n;
        //printf("Enter number of nodes\n");
        scanf("%d",&n);
        Insertvaluetonode(n);
        displaylinkedlist();
        reverselinkedlist();
        displaylinkedlist();
        return 0;
}

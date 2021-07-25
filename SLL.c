#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
int num;
	struct node *p;
	
	void addatbeg();
	void addatend();
	void addatmid();
	void delete();
	void display();
	
	int main()
	{
		int ch;
	
		while(1)
		{
				display();
		printf("\n1.addatbeg \n2.addatend\n3.addatmid\n4.delete\n5.display\n6. Exit");
		
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			addatbeg();
			break;
	    	
			case 2:
			addatend();
			break;
		
		    case 3:
			addatmid();
			break;
		
			case 4:
			delete();
			break;
		
			case 5:
			display();
			break;
		
			case 6:
			return 0;
			
			default:
			printf("\n invalid choice:");
		}
	}
		return 0;
	}
	
	void addatbeg()
	{
		struct node *r;
		r=(struct node*)malloc(sizeof(struct node));
		
		printf("\n Enter data");
		scanf("%d",&num);
		
		if(p==NULL)
		{
			r->data=num;
			r->next=NULL;
			p=r;
		}
		else
		{
			r->data=num;
			r->next=p;
			p=r;
		}
	}
	void addatend()
	{	
		struct node *r;
		struct node *q;
		q=p;
		r=(struct node*)malloc(sizeof(struct node));
		
		printf("\n Enter data");
		scanf("%d",&num);
		
		if(p==NULL)
		{
			r->data=num;
			r->next=NULL;;
			p=r;
		}
		else
		{
			while(q->next!=NULL)
			{
				q=q->next;
			}
			r->data=num;
			r->next=NULL;
			q->next=r;
		}
	}
		
	void display()
	{
			struct node *q;
			q=p;
			
			//printf("[");
			
			while(q!=NULL)
			{
				printf("\t %d,",q->data);
				q=q->next;
			}
			printf("]");
	}
				
		    	
	void addatmid()
	{
			int no;
				
		struct node *r;
		struct node *q;
		q=p;
		r=(struct node*)malloc(sizeof(struct node));
		
		printf("\n Enter data");
		scanf("%d",&num);
		
		printf("After which data do u want to add:");
		scanf("%d",&no);
		
		if(p==NULL)
		{
			printf("List is empty");
			exit(0);
		}
		
		else
		{
			while(q->data!=no)
			{
				q=q->next;                    //..............after traveling q shoud have address of no.
				if(q==NULL)
				{
					printf("Given no not found........");
					exit(0);
				}
			}
			r->data=num;
			r->next=q->next;
			q->next=r;
		}
	}
		
	void delete()
	{    
		int no;
			struct node *old;
			struct node *q;
			q=p;
			
			
			
			printf("\n Enter data do u want to delete:");
			scanf("%d",&no);
			
			if(p==NULL)
			{
				printf("List is empty");
				exit(0);
			}
			
			else
			{
				while(q->data!=no)
				{
					if(q==NULL)
					{
						printf(" Given no not find......");
						exit(0);
						
					}
					old=q;
					q=q->next;
				}
				
					if(p==q)
					{
						p=q->next;
						free(q);
					}
				else
				{
					old->next=q->next;
					free(q);
				}
			}
	}

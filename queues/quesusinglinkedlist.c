#include<stdio.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
}*front=0,*rear=0;

enq(int x)
{
    struct node *p=0;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->next=0;
    if (front==0)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }

}

deq()
{
    struct node *temp=front;
    front=front->next;
    free(temp);
}

display()
{
    struct node *p=front;
    while(p!=0)
    {
        printf("%d",p->data);
        if (p->next!=0)
            printf("->");
        p=p->next;
    }
    printf("\n");
}

void main()
{
    int ch,x;
    do{
printf("\t****Queue operations menu****\n");
printf("\t1. Enq\n");
printf("\t2. Deq\n");
printf("\t3. Display\n");
printf("\t4. Exit\n");
printf("\tEnter your response: ");
scanf("%d",&ch);

switch(ch){
case 1:
    printf("\tEnter the element to be enqueued: ");
    scanf("%d",&x);
    enq(x);
    break;
case 2:
    deq();
    break;
case 3:
    printf("\tQueue elements are: \n");
    display();
    break;
case 4:
    printf("\t****End****\n");
    break;
}
}while(ch!=4);
}


#include<stdio.h>
  #include<stdlib.h>

  struct node {
        int c, p;
        struct node *next;
  };

  struct node *Ptr1, *Ptr2, *Ptr3;
 
  struct node * create_Node(int c, int p) {
        struct node *ptr = (struct node *) malloc(sizeof (struct node));
        ptr->c = c;
        ptr->p = p;
        ptr->next = NULL;
        return ptr;
  }

  
  void polynomial_insert(struct node ** p, int coefficient, int exponent) {
        struct node *lPtr, *pPtr, *qPtr = *p;
        lPtr = create_Node(coefficient, exponent);

        
        if (*p == NULL || (*p)->p < exponent) {
                *p = lPtr;
                (*p)->next = qPtr;
                return;
        }

       
        while (qPtr) {
                pPtr = qPtr;
                qPtr = qPtr->next;
                if (!qPtr) {
                        pPtr->next = lPtr;
                        break;
                } else if ((exponent < pPtr->p) &&(exponent > qPtr->p)) {
                        lPtr->next = qPtr;
                        pPtr->next = lPtr;
                        break;
                }
        }
        return;
  }

  
  void polynomial_add(struct node **n1, int coefficient, int exponent) {
        struct node *x = NULL, *temp = *n1;
        if (*n1 == NULL || (*n1)->p < exponent) {
               
                *n1 = x = create_Node(coefficient, exponent);
                (*n1)->next = temp;
        } else {
                while (temp) {
                        if (temp->p == exponent) {
                                /* updating the co-efficient value  alone */
                                temp->c = temp->c + coefficient;
                                return;
                        }
                        if (temp->p > exponent && (!temp->next ||
                                temp->next->p < exponent)) {
                                /* inserting in the middle or end */
                                x = create_Node(coefficient, exponent);
                                x->next = temp->next;
                                temp->next = x;
                                return;
                        }
                        temp = temp->next;
                }
                x->next = NULL;
                temp->next = x;
        }
  }

  void polynomial_multiply(struct node **n1, struct node *n2, struct node *n3) {
        struct node * temp;
        int coefficient, exponent;

        temp = n3;

       
        if (!n2 && !n3)
                return;

        
        if (!n2) {
                *n1 = n3;
        } else if (!n3) {

               
                *n1 = n2;
        } else {
                while (n2) {
                        while (n3) {
                                
                                coefficient = n2->c * n3->c;
                                exponent = n2->p + n3->p;
                                n3 = n3->next;
                                
                                polynomial_add(n1, coefficient, exponent);
                        }
                        n3 = temp;
                        n2 = n2->next;
                }
        }
        return;
  }
  
  void polynomial_display(struct node *ptr) {
        int i = 0;
        while (ptr) {
                printf("%dX^%d %c ", ptr->c,
                        ptr->p, ptr->next?'+':'\0');
                ptr = ptr->next;
                i++;
        }
        printf("\n");
        return;
  }
  
  void main(){
  	
  	
  	int coef,exp,c=1;
  	
  	printf("\nEnter polynomial 1 :");
    while(c){
    	
    	printf("\nEnter coefficient :");
    	scanf("%d",&coef);
    	printf("\nEnter power :");
    	scanf("%d",&exp);
    	polynomial_insert(&Ptr1,coef,exp);
    	printf("\nContinue ?");
    	scanf("%d",&c);
    	
	}
  	
  	
  	polynomial_display(Ptr1);
  	c=1;
  	printf("\nEnter polynomial 2 :");
    while(c){
    	
    	printf("\nEnter coefficient :");
    	scanf("%d",&coef);
    	printf("\nEnter power :");
    	scanf("%d",&exp);
    	polynomial_insert(&Ptr2,coef,exp);
    	printf("\nContinue ?");
    	scanf("%d",&c);
    	
	}
  	
  	
  		polynomial_display(Ptr2);
  	
  	polynomial_multiply(&Ptr3,Ptr1,Ptr2);
  	
  	printf("\n The resultant polynomial is :\n");
  	
  	polynomial_display(Ptr3);
  	
  	
  	
  	
  	
  	
  	
  	
  }

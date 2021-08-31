#include <stdio.h>
#include <stdlib.h>
//create structure of Linked List  
struct Node {
	
    int key;
    struct Node* next;
    
};
//create structure of Queue 
struct Queue {
	
    struct Node *front, *rear;
    
};
//creating new node
struct Node* newNode(int N)
{
	
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = N;
    temp->next = NULL;
    
    return temp;
    
}
//create empty queue  
 struct Queue* createQueue()
{
	
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    
    return q;
    
}
//function to inqueue (insert) 
void enQueue(struct Queue* q, int N)
{
	
    struct Node* temp = newNode(N);
 
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        
        return;
        
    }
 
    q->rear->next = temp;
    q->rear = temp;
    
}
//function to dequeue (delete) 
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
 
    struct Node* temp = q->front;
 
    q->front = q->front->next;
 
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
    
}
//our main function 
int main()
{
    struct Queue* q = createQueue();
    enQueue(q, 0);
    enQueue(q, 5);
    enQueue(q, 7);
    enQueue(q, 8);
    enQueue(q, 9);
    deQueue(q);
    
    printf("Front element in queue : %d \n", q->front->key);
    printf("Rear elemnt in queue : %d", q->rear->key);
    
    return 0;
}


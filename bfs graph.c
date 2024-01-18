#include<stdio.h>
#include<stdlib.h>
#define MAX 20 
typedef struct { 
 int x[MAX]; 
 int front; 
 int rear; 
} queue; 

void insertq(queue * q,int x) 
 { 
 if(q->rear==MAX) 
 { 
 printf("\nOverflow\n"); 
 } 
 else 
 { 
 q->x[++q->rear]=x; 
 if(q->front==-1) 
 { 
 q->front=0; 
 } 
 }
 } 
 int deleteq(queue * q) 
 { 
 int x; 
 if(q->front==-1) 
 { 
 printf("\nUnderflow!!!\n"); 
 } 
 else if(q->front==q->rear) 
 { 
 x=q->x[q->front]; 
 q->front=q->rear=-1; 
 return x; 
 } 
 else 
 { 
 return q->x[q->front++]; 
 } 
 }
 int isempty(queue*q){
     if(q->front==-1 && q->rear==-1){
         return 1;
     }
     return 0;
 }
int main() 
{ 
 queue q; 
 q.front=-1; 
 q.rear=-1; 
 int visited[3] ={0,0,0};
 int i=2;
 insertq(&q,i);
 int adj[3][3]={
     {0,1,0},
     {1,0,1},
     {0,1,0}
 };
 printf("%d",i);
 visited[i]=1;
 while(!isempty(&q)){
     int node = deleteq(&q);
     for(int j=0;j<3;j++){
         if(adj[node][j]==1 && visited[j]==0){
             insertq(&q,j);
             printf("%d",j);
             visited[j]=1;
         }
     }
 }
 }
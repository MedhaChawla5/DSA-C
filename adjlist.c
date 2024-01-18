#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct list{
    struct node* head;
};
struct graph{
    int numv;
    struct list* adj;
};
struct graph* create_graph(int V){
    struct graph* Graph = (struct graph*)malloc(sizeof(struct graph));
    Graph->numv = V;
    Graph->adj = (struct list*)malloc(V*sizeof(struct list));
    for(int i=0;i<V;i++){
        Graph->adj[i].head = NULL;
    }
    return Graph;
}

struct node* newnode(int d){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    return new;
}

void add_edge(struct graph * Graph , int src , int dest){
    struct node* new = newnode(dest);
    new->next = Graph->adj[src].head;
    Graph->adj[src].head = new;
    
    new = newnode(src);
    new->next = Graph->adj[dest].head;
    Graph->adj[dest].head = new;
}


void print_graph(struct graph * Graph){
    for(int i=0;i<Graph->numv;i++){
        struct node* temp = Graph->adj[i].head;
        printf("Adjacency list of vertex %d ",i);
        while(temp){
            printf(" - > %d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int x = 5;
    struct graph * Graph = create_graph(x);
    add_edge(Graph,0,1);
    add_edge(Graph,0,2);
    add_edge(Graph,1,4);
    add_edge(Graph,1,3);
    add_edge(Graph,2,3);
    add_edge(Graph,4,3);
    print_graph(Graph);
    return 0;
}
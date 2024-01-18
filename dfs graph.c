#include<stdio.h>
#include<stdlib.h>
int adj[4][4]={
    {0,0,1,0},
    {0,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};
int visited[4]={0,0,0,0};
void dfs(int i){
    visited[i]=1;
    printf("%d",i);
    for(int j=0;j<4;j++){
        if(visited[j]==0 && adj[i][j]==1){
            dfs(j);
        }
    }
}
int main(){
    printf("dfs traversal of the given graph is ");
    dfs(3);
    return 0;
}
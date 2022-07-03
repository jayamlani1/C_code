/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

void dfs(int** isConnected, int* visited, int i, int isConnectedSize)
{
    int j = 0;
    for(int j=0;j<isConnectedSize;j++)
    {
        if(visited[j] == 0 && isConnected[i][j])
        {
            visited[j] = 1;
            dfs(isConnected, visited, j, isConnectedSize);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int visited[isConnectedSize];
    int count = 0;
    for(int i =0;i<isConnectedSize;i++)
    {
        visited[i] = 0;
    }
    
    for(int i=0;i<isConnectedSize;i++)
    {
        if(visited[i] == 0)
        {
            //visited[i] = 1;
            dfs(isConnected, visited, i, isConnectedSize);
            count++;
        }
    }
    return count;
}

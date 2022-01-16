#include<bits/stdc++.h>
using namespace std;
bool is_safe(int x, int y, vector<vector<int>>maze, vector<vector<int>>visited){
    if(x>=0 && x<maze.size() && y>=0 && y<maze[0].size() && maze[x][y]==1 && visited[x][y]==0)
        return true;
    return false;
}

void solve(vector<vector<int>>&maze, int x, int y, vector<vector<int>>visited, vector<string>&ans, string path){
    if(x==maze.size()-1 && y==maze[0].size()-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    int newx = x+1;
    int newy = y;
    if(is_safe(newx, newy, maze, visited)){
        path.push_back('D');
        solve(maze, newx, newy, visited, ans, path);
        path.pop_back();
    }

    // up
    newx = x-1;
    newy = y;
    if(is_safe(newx, newy, maze, visited)){
        path.push_back('U');
        solve(maze, newx, newy, visited, ans, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y-1;
    if(is_safe(newx, newy, maze, visited)){
        path.push_back('L');
        solve(maze, newx, newy, visited, ans, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y+1;
    if(is_safe(newx, newy, maze, visited)){
        path.push_back('R');
        solve(maze, newx, newy, visited, ans, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main(){
    vector<vector<int>>maze = {{1, 1, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<vector<int>>visited = maze;
    for(int i=0; i<visited.size(); i++){
        for(int j=0; j<visited[0].size(); j++){
            visited[i][j] = 0;
        }
    }
    int x = 0;
    int y = 0;
    vector<string>ans;
    string path;
    solve(maze, x, y, visited, ans, path);
    for(auto it: ans)
        cout<<it<<endl;
    return 0;
}
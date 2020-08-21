// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively
bool isSafe(int i, int j, int R, int C)
{
    if(i>=0 && j>=0 && i<R && j<C)
        return true;
    return false;
}
int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    // Your code goes here
    /*int no = 2;
    bool changed = false;
    while(true){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(matrix[i][j] == no)
            {
                if(isSafe(i+1,j,R,C) && (matrix[i+1][j] == 1))
                {
                    changed = true;
                    matrix[i+1][j] = matrix[i][j] + 1;
                }
                if(isSafe(i-1,j,R,C) && (matrix[i-1][j] == 1))
                {
                    changed = true;
                    matrix[i-1][j] = matrix[i][j] + 1;
                }
                if(isSafe(i,j+1,R,C) && (matrix[i][j+1] == 1))
                {
                    changed = true;
                    matrix[i][j+1] = matrix[i][j] + 1;
                }
                if(isSafe(i,j-1,R,C) && (matrix[i][j-1] == 1))
                {
                    changed = true;
                    matrix[i][j-1] = matrix[i][j] + 1;
                }
            }
        }       
    }
    if(changed == false)
        break;
    changed = false;
    no++;
            
    }
    for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) { 
            	if (matrix[i][j] == 1) 
				    return -1; 
		} 
	}
	
    return no - 2;*/
    queue<pair<int, int>> rotten;
    int fresh = 0, t = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(matrix[i][j] == 2)
                rotten.push({i,j});
            if(matrix[i][j] == 1)
                fresh++;
        }    
    }
    while(!rotten.empty()){
        int num = rotten.size();    
        for(int i = 0; i < num; i++){
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
                if((isSafe(x+1,y,R,C)) && (matrix[x+1][y] == 1)){
                    rotten.push({x+1,y});matrix[x+1][y] = 2;fresh--;}
                if((isSafe(x-1,y,R,C)) && (matrix[x-1][y] == 1)){
                    rotten.push({x-1,y});fresh--;matrix[x-1][y] = 2;}
                if((isSafe(x,y+1,R,C)) && (matrix[x][y+1] == 1)){
                    rotten.push({x,y+1});fresh--;matrix[x][y+1] = 2;}
                if((isSafe(x,y-1,R,C)) && (matrix[x][y-1] == 1)){
                    rotten.push({x,y-1});fresh--;matrix[x][y-1] = 2;}
        }
        if(!rotten.empty()){
            t++;
        }
    }
    return (fresh == 0) ? t : -1;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends
#include <iostream>
using namespace std;

#define SIZE 105

void spiralTraverse(int row, int column, int mat[SIZE][SIZE])
{
    
    int top= 0, left = 0, bottom = row-1, right = column-1;
    
    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right;i++)
            cout<<mat[top][i]<<" ";
        top++;
        
        for(int i=top; i<=bottom; i++)
            cout<<mat[i][right]<<" ";
        right--;
        
        if(top<=bottom)
        {
            for(int i=right; i>=left; i--)
                cout<<mat[bottom][i]<<" ";
            bottom--;
        }
        
        if(left<=right)
        {
            for(int i=bottom; i>=top;i--)
                cout<<mat[i][left]<<" ";
            left++;
        }
    }
}


int main() {
	
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
	    int ar[SIZE][SIZE] = {{0}};
	    int i = 0;
	    int j = 0;
	    int row = 0;
	    int col = 0;
	    
	    for(i=0; i<m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            scanf("%d",&ar[i][j]);
	        }
	    }
	    
	    spiralTraverse(m, n, ar);
	    cout<<endl;
	   
}

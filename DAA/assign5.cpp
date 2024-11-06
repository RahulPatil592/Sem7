#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, vector<vector<char>> &mat)
{

    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q')
            return false;
    }
    for (int i = 0; i < c; i++)
    {
        if (mat[r][i] == 'Q')
            return false;
    }

    for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q')
            return false;
    }
    int n=mat.size();
    for (int i = r+1, j = c-1; i < n && j >= 0; i++, j--)
    {
        if (mat[i][j] == 'Q')
            return false;
    }

    return true;
}

void print(vector<vector<char>>&mat, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool nQueen(int c,int n,vector<vector<char>> &mat){
    if(c==n){
        print(mat,n);
        return true;
    }

    for(int r=0; r<n; r++){
        if(mat[r][c]=='Q' && isSafe(r,c,mat)){
            if(nQueen(c+1,n,mat)) return true;
        }
        if(mat[r][c]=='.' && isSafe(r,c,mat)){
            mat[r][c]='Q';
            if(nQueen(c+1,n,mat)) return true;
            mat[r][c]='.';
        }
    }
    return false;
}
int main()
{
     int n;
     cin>>n;
    vector<vector<char>> mat(n,vector<char>(n,'.'));
    mat[0][2]='Q';
    cout<<nQueen(0,n,mat);
    return 0;
}
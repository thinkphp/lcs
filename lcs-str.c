/*
 *  Longest Common Subsequence
 *
 *  Given  two sequences, find the length of longest subsequence present in both of them.
 *  A subsequence is a sequence that appears in the same relative order, but not necessarily
 *  contiguous. For example, "abc","abg","aeg" are subsequences of "abcdefg". So, a string
 *  of length N has 2^N different possible subsequences.
 *
 */

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if(a>b) return a; else return b;
}

int main() { 

     char X[] = "AGGTAB";
     char Y[] = "GXTXAYB";

     int i,j;
     
     int n = strlen(X), 
         m = strlen(Y);

     int mat[n+1][m+1];
      
     for(i=0;i<=n;i++) {

         for(j=0;j<=m;j++) {

             if(i==0 || j == 0) mat[i][j] = 0;
  
             else if(X[i-1] == Y[j-1]) {

                     mat[i][j] = mat[i-1][j-1] + 1;  

             } else {

                     mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
             }
         }
     }                   

     for(i=0;i<=n;i++) {

         for(j=0;j<=m;j++) {

             printf("%d ", mat[i][j]);
         }
             printf("\n");
    }      

    printf("%d\n",mat[n][m]);

    int index = mat[n][m]; 
    
    char lcs[ index + 1 ]; lcs[ index ] = '\0';

    i = n;
    j = m;

    while(i > 0 && j > 0) {

          if(X[i-1] == Y[j-1]) 

             lcs[--index] = X[i-1], i--, j--;

          else if(mat[i-1][j] > mat[i-1][j-1]) i--;

                  else          j--;       
    }          

    printf("%s",lcs);

     return(0);
};
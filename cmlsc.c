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
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAXN 1024
#define MAXM 1024

int X[ MAXN ], 
    Y[ MAXM ];

int N,
    M;

int mat[ MAXN ][ MAXM ];

FILE *fin, 
     *fout;

//function prototypes
int max(int,int);
void read();
void solve();

int main() { 
      
     read();
     solve();

     return(0);
};

void read() {

     int i;

     fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &N, &M);

     for(i=1;i<=N;i++) 

         fscanf(fin, "%d", &X[i]);

     for(i=1;i<=M;i++) 

         fscanf(fin, "%d", &Y[i]);

     fclose( fin );
};

int max(int a, int b) {

    if( a > b ) return a;

        else

            return b;
}

void solve() {

     int i,j;

     fout = fopen(FOUT, "w");

     for(i = 1; i<= N; i++) {

         for(j = 1; j <= M; j++) {

             if(X[ i ] == Y[ j ]) {

                mat[ i ][ j ] = mat[ i - 1][ j - 1 ] + 1;
 
             } else {

                mat[ i ][ j ] = max(mat[ i - 1][ j ], mat[ i ][ j - 1]);

             }

         }  
     }

  fprintf(fout, "%d\n",mat[ N ][ M ]);

  int sol[ mat[N][M] + 1 ];  

  int index = mat[N][M];

  i = N;
  j = M;

  while(i>0 && j>0) {

        if(X[i] == Y[j])
 
           sol[--index] = X[ i ], i--, j--;
           
        else if(mat[i-1][j] > mat[i][j-1]) i--;

                  else j--;           
  }   

  for(i = 0; i < mat[ N ][ M ]; i++) fprintf(fout, "%d ", sol[i]); 
};
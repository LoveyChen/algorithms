#include <iostream>

#include "sort_helper.h"

const int MAX_VAL = 12345;

void merge( int A[], const int p, const int q, const int r ){
  int n1 = q - p;
  int n2 = r - q;
  
  int L[ n1 + 1 ];
  int R[ n2 + 1 ];

  for( int i = 0; i < n1; ++i ){
    L[i] = A[ p + i];
  }
  L[n1] = MAX_VAL;
  for( int i=0; i < n2; ++i ){
    R[i] = A[ q + i ];
  }
  R[n2] = MAX_VAL;

  int i = 0;
  int j = 0;

  for( int k = p; k < r; ++k ){
    if( L[i] < R[j] ){
      A[k] = L[i];
      ++ i;
    }else{
      A[k] = R[j];
      ++ j;
    }
  }
}

void merge_sort( int A[], int p, int r ){
  if( p >= r-1 ){
    return;
  }

  int q = ( p + r ) / 2;
  merge_sort( A, p, q );
  merge_sort( A, q, r );
  merge( A, p, q, r );
}

int main( int argc, char *argv[] ){
  int n = 10;
  
  if( argc > 1 ){
    n = atoi( argv[1] );
  }

  int *A = genRandomData( n, 0, 1234 );
  
  printf( "Before sort: \n" );
  printArray( A, n );
  merge_sort( A, 0, n );
  printf( "\n\nAfter sort:\n" );
  printArray( A, n );

  delete[] A;
  
  return 0;
}

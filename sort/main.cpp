#include "heapSort.h"
#include <cstdio>

int printArray( int *A, int n, int linelen ){
	for( int i=0; i<n; ++i ){
		printf( "%d", A[i] );
		if( (i+1) % linelen == 0 ){
			printf( "\n" );
		}else{
			printf( " " );
		}
	}
	if( n % linelen != 0 ){
		printf( "\n" );
	}
}

int main( int argc, char *argvs[] ){
	const int len = 16;
	int A[] = { 16, 11, 15, 9, 10, 13, 14, 8, 2, 1, 5, 12, 6, 3, 7, 4 };

	printArray( A, len, 10 );

	buildHeap( A, len );

	printArray( A, len, 10 );

	heapSort( A, len );

	printArray( A, len, 10 );
}

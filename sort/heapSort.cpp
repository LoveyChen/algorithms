#include "heapSort.h"

void heapSort( int *A, int n ){
	buildHeap( A, n );

	for( int i=n-1; i> 0; --i ){
		int tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;

		heapify( A, 0, i );
	}
}

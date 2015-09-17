#include "heapSort.h"

void buildHeap( int *A, int n ){
	for( int idx=n/2-1; idx>=0; --idx ){
		heapify( A, idx, n );
	}
}

void heapify( int *A, int idx, int n ){
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	int largest = idx;
	if( left < n && A[left] > A[idx] ){
		largest = left;
	}

	if( right < n && A[right] > A[largest] ){
		largest = right;
	}

	if( largest != idx ){
		int tmp = A[idx];
		A[idx] = A[largest];
		A[largest] = tmp;

		heapify( A, largest, n );
	}
}

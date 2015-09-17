#ifndef __SORT_HELPER_H__
#define __SORT_HELPER_H__

#include <iostream>
#include <random>
#include <functional>

static std::default_random_engine generator;

int * genRandomData( int N, int min=0, int max=100 ){
	std::uniform_int_distribution<int> distribution( min, max );
	auto dice = std::bind( distribution, generator );

	int *result = new int[N];
	for( int i=0; i<N; ++i ){
		result[i] = dice();	
	}

	return result;
}

void printArray( int *A, int N, int linelen=10 ){
	for( int i=0; i<N; ++i ){
		printf( "%5d", A[i] );

		if( (i+1) % linelen == 0 ){
			printf( "\n" ); 
		}else{
			printf( " " );
		}
	}

	if( N % linelen != 0 ){
		printf( "\n" );
	}
}

#endif

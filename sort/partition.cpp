/*****************************************************************
 * 在线性时间, 根据给定的中枢值 privot, 重新组合子序列 ar[left, right]
 * 使得, ar[left, store] <= privot, ar[store+1,right] > privot
 * 返回中枢值 privot 对应序列中的索引 store
 ****************************************************************/
int partition( int[] ar, int left, int right, int privotIndex ){
	int tmp = ar[right];
	ar[right] = ar[privotIndex];
	ar[privotIndex] = tmp;

	int privot = ar[privotIndex];

	// store save the expect index for privot
	// and after the loop, it is the right place for privot
	int store = left;
	for( int i=left; i<right; ++i){
		if( ar[i] < privot && i != store ){
			tmp = ar[store];
			ar[store] = ar[i];
			ar[i] = tmp;
			++ store;
		}
	}
	
	tmp = ar[store];
	ar[store] = ar[right];
	ar[right] = tmp;

	return store;
}

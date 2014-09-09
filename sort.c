#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "read_data.h"


// function definition
void divide(int array[], int start, int end);
void order(int array[], int start, int middle, int end);

/* 
 * Takes a file name as input from command line
 * which contains array of integers. These are
 * sorted either in ascending order or descending
 * order. The array is printed out both pre- and 
 * post-sort.
 *
 * DO NOT EDIT THIS MAIN FUNCTION 
 */
int
main(int argc, char **argv)
{
	int i;
        int num;
	int to_sort_array[MAX_NUM];
	int sorted_array[MAX_NUM];

	if (argc != 2) {
		perror("Input arguments are not correct.\n");
		return 1;
	}

	/* Fill the input array */
	num = fillInput(to_sort_array, argv[1]);
	if (num <= 0) {
		perror("Data initilization error.\n");
		return 1;
	}

	/* Print input and sort */
	printf("Unsorted array:\t");
	for (i = 0; i < num; i++) {
		printf("%d ",to_sort_array[i]);
	}
	printf("\n");

	merge_sort(to_sort_array, sorted_array, num);
#ifdef DSC
	printf("Sorted (descending) array: ");
#elif ASC
	printf("Sorted (ascending) array: ");
#endif
	for (i = 0; i < num; i++) {
		printf("%d ",sorted_array[i]);
	}
	printf("\n");
	return 0;
}

/*
 * INSERT DESCRIPTION HERE
 */
void 
merge_sort(int input_array[], int output_array[], int num)
{
	int * p = 0;
	int * j = ((int *) p) + 1;
	char * k = ((char *) p) + 1;

	int i;
	for (i = 0; i < num; i++){
		output_array[i] = input_array[i];
	#ifdef DSC
			output_array[i] *= -1;
	#endif
	}
	
	divide(output_array,0,num-1);
 	#ifdef DSC
 		for (i=0; i<num; i++){
			output_array[i] *= -1;
 		}
 	#endif	
}

void order(int array[], int start, int middle, int end){

	int old_array[end - 1];
	int index;
	for (index = start; index < (end + 1); index++){
		old_array[index] = array[index];
	}
	
	int i = start;
	int j = middle + 1;
	
	while ((i+j) < (middle + end + 2)){
		if (((old_array[i] < old_array[j]) || (j > end)) && (i<=middle)){
			array[i+j-middle-1] = old_array[i];
			i++;
		}
		else{
			array[i+j-middle-1] = old_array[j];
			j++;
		}
	}
}


void divide(int array[], int start, int end){
	if (start != end){
		divide(array, start, (start + end)/2);
		divide(array,(start + end)/2 + 1, end);
		order(array,start,(start+end)/2,end);
	}
}






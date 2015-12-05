/*
 * input.c
 *
 *  Created on: 29 Nov 2015
 *      Author: lubiedak
 */



short* allocate_mem(short*** arr, int n, int m)
{
  *arr = (short**)malloc(n * sizeof(short*));
  short *arr_data = malloc( n * m * sizeof(short));
  for(int i=0; i<n; i++)
     (*arr)[i] = arr_data + i * m ;
  return arr_data; //free point
}

void deallocate_mem(short*** arr, short* arr_data){
    free(arr_data);
    free(*arr);
}

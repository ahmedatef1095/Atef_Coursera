/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief  Delacrations of functions that can analyze an array of unsigned char 
 * data items and report analytics on the maximum, minimum, mean, and median of the data set.
 *
 *
 * @author Ahmed Atef
 * @date 9/2/2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Statistics and Printing Functions Go Here */
  printf("Array before sorting: \n");
  /*call function print_array */
  print_array(test, SIZE);

  /*call function print_statistics*/
  print_statistics(	find_minimum(test, SIZE),
		  	  	  	find_maximum(test, SIZE),
					find_mean(test, SIZE),
					find_median(test, SIZE));

  /*call function sort_array*/
  sort_array(test, SIZE);

  printf("Array after sorting: \n");
  /*call function print_array*/
  print_array(test, SIZE);
}

void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
  printf("The minimum = %d \n", minimum);
  printf("The maximum = %d \n", maximum);
  printf("The mean = %f \n", mean);
  printf("The median = %d \n", median);
}


void print_array (unsigned char *A, unsigned int n){
		for (int i = 0; i < n; i++)
		{
			if (i == 0) printf("Array= [%d" , A[i]);
			else if (i == n-1) printf(",%d]" , A[i])  ;
			else  printf( ",%d", A[i]);
		}
		printf ("\n");
}

unsigned char find_median (unsigned char *array, unsigned int counter){
  unsigned char median = 0;
  median = *(array + (counter / 2) -1);
  return median;
}

float find_mean (unsigned char *array, unsigned int counter){
  unsigned int accumulator = 0; /*variable to store the accumulator value throughout the mean finding process*/
  float mean = 0;
  for (int i=0; i<counter; i++){
    accumulator = accumulator + array[i] /* *(array + i) */;
  }
  printf("Accumulator = %d \n", accumulator);
  mean = accumulator / ((float) counter); /*must type cast one of the two integers to float for accurate calculation.*/
  return mean;
}

unsigned char find_maximum (unsigned char *array, unsigned int counter){
  unsigned char maximum = *array; /* initalize the maximum variable with the value of the first array element*/
  for (int i=1; i<counter; i++){  /* start the loop from the second elemnt*/
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }

  }
  return maximum;
}

unsigned char find_minimum (unsigned char *array, unsigned int counter){
  unsigned char minimum = *array; // initalize the minimum variable with the value of the first array element
  for (int i=1; i<counter; i++){ // start the loop from the second elemnt
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }

  }
  return minimum;
}

void sort_array (unsigned char *array, unsigned int counter){
  char flag = 0; /*this flag is to indicate if a swap process has occurred at least once in the loop*/
  unsigned char temp;
  do {
    flag =0; /*set flag to default at every new 'do' operation*/
    for (int index=0; index<counter; index++){
      if (array[index] > array[index +1] || array[index] == array[index +1]) {
        continue;
      }
      else if (array[index] < array[index +1]) {
        /*swap elements*/
        temp = array[index];
        array[index] = array[index+1];
        array[index+1] = temp;

        flag = 1; /* a swap process has occurred at least once in this loop*/
      }
    }
  }
  while (flag ==1); /* the array is not sorted as long as a swap operation is occurred at least once*/
}


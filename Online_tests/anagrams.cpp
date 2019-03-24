
/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
using namespace std;
using std::string;
using std::cin;
using std::cout;
  
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>

void merge(char* arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    char L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(char* arr, int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 


int len_mas(string mas)
{
	int i = 0;
	char a = 'o';
	while (mas[i])
	{
		//a = mas[i];
		i += 1;
	}
	return i ;
}

int main()
{
	int i = 0, n_s, n_j;
	//cin >> j0 >> s0;
	char *a;
	a = (char*) calloc (100000, sizeof(char));
	fgets(a, 100000, stdin);
	std::cout << "lol" << endl;

	int a_size = sizeof(a)/sizeof(a[0]);
	mergeSort(a, 0, a_size - 1);
	puts(a);
	//n_s = len_mas(s);
	//n_j = len_mas(j);
	//cout << n_j << endl;
	//cout << n_s << endl;
	
/*	int s_size = sizeof(s)/sizeof(s[0]);
	int j_size = sizeof(j)/sizeof(j[0]);
	cout << "s" << s_size;  
	mergeSort(s, 0, s_size - 1);
	mergeSort(j, 0, j_size - 1);
	
	cout << s << endl;
	cout << j << endl;
*/

	return 0;
}
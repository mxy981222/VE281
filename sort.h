#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include<cmath>
#include <cassert>
using namespace std;
void swap(int* a, int x, int y);
void bubble_sort(int* a, int n);
void selection_sort(int* a, int n);
void insertion_sort(int* a, int n);
void merge_sort(int* a, int left, int right, int* temp);
void merge(int* a, int left, int mid, int right, int* temp);
int mypartition(int* a, int first, int last); 
void quick_sort(int* a, int first, int last);
int RSelect(int* a, int first, int last, int i);
int DSelect(int a[], int first, int last, int i);
int find_max(int* a, int n);
void counting_sort1(int* a, int n);
void counting_sort2(int* a, int n);
int find_min(int* a, int n);
void bucket_sort(int* a, int n);
int maxbit(int max);
void radix_sort(int* a, int n);
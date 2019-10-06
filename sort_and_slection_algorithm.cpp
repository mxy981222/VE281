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
void swap(int* a, int x, int y) {
	//REQUIRE: a is an array, x and y are the index which is smaller than the size of a
	//MODIFY: a
	//EFFECT: Exchange the value of a[x] and a[y]
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
void bubble_sort(int *a, int n) {
	//REQUIRE: a is an array, n is the size of a
	//MODIFY: a
	//EFFECT: Sort a in ascending order
	for (int i = n - 1; i > 0; i--) {
		for (int j = n-1; j > 0; j--) {
			if (a[j] < a[j - 1]) {//If the later one is smaller exchange it with the previous one
				swap(a, j, j - 1);
			}
		}
	}
}
void insertion_sort(int* a, int n) {
	//REQUIRE: a is an array, n is the size of a
	//MODIFY: a
	//EFFECT: Sort a in ascending order
	for (int i = 1; i < n; i++) {// elements before i is already sorted
		int temp = a[i];// save a[i] since it will be replaced by a[i-1]
		int j = i - 1;
		while (j >= 0 && temp < a[j]) {
			a[j + 1] = a[j];//push elements between j and i forward
			--j;
		}
		a[j + 1] = temp;
	}
}
void selection_sort(int* a, int n) {
	//REQUIRE: a is an array, n is the size of a
	//MODIFY: a
	//EFFECT: Sort a in ascending order
	for (int i = 0; i < n; i++) {//find the minimum 
		int minindex = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[minindex]) {
				minindex = j;
			}
		}
		if (minindex != i) {
			swap(a, minindex, i);//place the minimum if it is not a[i]
		}
	}
}


void merge(int* a, int left, int mid, int right, int* temp) {
	int i = left, j = mid+1, m = mid, n = right, k = 0;
	while (i <= m && j <= n) {//when both the array is not empty
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= m) {//when one of the array is empty
		temp[k++] = a[i++];
	}
	while (j <= n) {
		temp[k++] = a[j++];
	}
	for (int it = 0; it < k; it++) {//copy the elements into the array
		a[left + it] = temp[it];
	}
}
void merge_sort(int* a, int left, int right, int* temp) {
	//REQUIRE: a is an array, temp is an empty array, with the same size as a, left and right are the index of the first and last element of the array
	//MODIFY: a
	//EFFECT: Sort a in ascending order
	if (left>=right) {
		return;
	}
	else {
		int mid = (left + right) / 2;
		merge_sort(a, left, mid, temp);
		merge_sort(a, mid + 1, right, temp);
		merge(a, left, mid, right, temp);
	}
}


int mypartition(int* a, int first, int last) {
	//REQUIRE: a is an array, first and last is the index of the first and last elements in this array
	//MODIFY: a
	//EFFECT: partition a from first to last and return the position of the pivot
	int bgn = first, fnl = last;
	while (bgn < fnl) {
		for (; bgn < last + 1; bgn++) {//find the left-most element greater than the pivot
			if (a[bgn] > a[first]) {
				break;
			}
		}
		for (; fnl > first; fnl--) {//find the right-most element smaller than the pivot
			if (a[fnl] < a[first]) {
				break;
			}
		}
		if (bgn < fnl) {
			swap(a, bgn, fnl);
		}
		else swap(a, first, fnl);
	}
	return fnl;
}
void quick_sort(int *a,int first, int last) {
	//REQUIRE: a is an array, first and last are the index of the first and last element of the array
	//MODIFY: a
	//EFFECT: Sort a in ascending order
	if (first >= last) {
		return;
	}
	else {
		int pivot = rand() % (last - first) + first;//randomly choose a pivot
		swap(a, first, pivot);// put the at the first place
		int pivotat = mypartition(a, first, last);// return the proper position of the chosen pivot
		quick_sort(a, first, pivotat - 1);
		quick_sort(a, pivotat + 1, last);
	}
}


int RSelect(int* a, int first, int last, int i) {
	//REQUIRE: a is an array, first and last are the start and final index of a, i is the index of the number in the ascending array (0<=i<=n)
	//EFFECT: return the value of the ith smallest number in a
	if (first >= last) {
		return a[first];
	}
	else {
		int pivot = rand() % (last - first) + first;//randomly choose a pivot
		swap(a, first, pivot);
		int pivotat = mypartition(a, first, last);
		if (pivotat == i) {
			return a[pivotat];
		}
		if (pivotat < i) {
			RSelect(a, pivotat + 1, last, i);
		}
		else {
			RSelect(a, first, pivotat - 1, i);
		}
	}
}

int DSelect(int a[], int first, int last, int i) {
	//REQUIRE: a is an array, first and last are the start and final index of a, i is the index of the number in the ascending array (0<=i<=n)
	//EFFECT: return the value of the ith smallest number in a
	if (first >= last) {
		return a[first];
	}
	else {
		int size_o = last - first + 1;
		int size_d = size_o / 5;
		if (size_o % 5 != 0) {
			size_d++;
		}//the amount of sub-arrays
		int* c = new int[size_d];//the n/5 "middle elements"
		int k = 0;//index of elements in c
		for (int i = 0; i < size_d; i++) {
			int temp[5] = { 0 };
			int mid = 0;//the value of the middle of this sub-array
			if (first + 5 * i + 4 > last) {
				merge_sort(a, first + 5 * i, last, temp);
				mid = a[(first + 5 * i + last) / 2];
				c[k] = mid;
			}
			else {
				merge_sort(a, first + 5 * i, first + 5 * i + 4, temp);
				mid = a[(first + 5 * i + first + 5 * i + 4) / 2];
				c[k++] = mid;
			}
		}
		int pivot = DSelect(c, 0, size_d-1, (size_d-1) / 2);
		delete[] c;//delete the allocated space for c, since c is no longer useful-
		for (int i = first; i <= last; i++) {
			if (a[i] == pivot) {
				swap(a, first, i);
			}
		}
		int pivotat = mypartition(a, first, last);
		if (pivotat == i) {
			return a[pivotat];
		}
		if (pivotat < i) {
			return DSelect(a, pivotat + 1, last, i);
		}
		else {
			return DSelect(a, first, pivotat - 1, i);
		}
	}
}

int find_max(int* a, int n) {
	//REQUIRE: a is an array, n is the size of a
	//EFFECT: Return the maximum in a
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
void counting_sort1(int* a, int n) {//not STABLE
	//REQUIRE: a is an array, n is the size of a
	//MODIFY: a
	//EFFECT: sort a in ascending order
	int max = find_max(a, n);
	int* count = new int[max + 1]{0};//counter for every number in this array, 0 for not existing
	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}
	int k = 0;
	for (int j = 0; j <= max; j++) {
		while (count[j] > 0) {
			a[k++] = j;
			count[j]--;
		}
	}
	delete[] count;
}
void counting_sort2(int* a, int n) {//STABLE
	//REQUIRE: a is an array, elements in a should be greater or equal to 0, n is the size of a
	//MODIFY: a
	//EFFECT: sort a in ascending order
	int* temp = new int[n] {0};
	int max = find_max(a, n);
	int* count = new int[max + 1]{ 0 };//counter for every number in this array, 0 for not existing
	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}
	for (int k = n - 1; k >= 0; k--) {
		temp[count[a[k]]-1] = a[k];
		count[a[k]]--;
	}
	delete[] count;
	for (int i = 0; i < n; i++) {
		a[i] = temp[i];
	}
	delete[] temp;
}

int find_min(int* a, int n) {
	//REQUIRE: a is an array, n is the size of a
	//EFFECT: Return the minimum in a
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

void bucket_sort(int* a, int n) {
	//REQUIRE: a is an array, n is the size of a
	//MODIFY: a
	//EFFECT: sort a in ascending order
	int max = find_max(a, n);
	int min = find_min(a, n);
	int size = max - min;
	int num = size / 5;//the number of buckets and step=5, step can be modified as the length of the array changing
	if (size % 5 != 0) {
		num++;
	}
	int* count = new int[num] {0};//counter for the elements in every bucket, with initially 0
	int* temp = new int[n] {0};//a temparary array to save the value
	int k = 0;
	for (int i = 0; i < num; i++) {//in order to make the time complexity less than n^2, num should be initially fixed! here we do not care about it. 
		for (int j = 0; j < n; j++) {
			if (a[j] >= min + i * 5 && a[j] <= min + i * 5 + 4) {
				temp[k++] = a[j];
				count[i]++;
			}
		}
	}
	int counter = 0;
	while (counter < n) {
		for (int i = 0; i < num; i++) {
			if (count[i] != 0) {
				quick_sort(temp, counter, counter + count[i]-1);
				counter += count[i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] = temp[i];
	}
	delete[] count;
	delete[] temp;
}

int maxbit(int max) {
	//REQUIRE: max an integer
	//EFFECT:return the number of bits of max
	int bit = 1;
	while (max > 0) {
		if (max / 10 > 0) {
			max = max / 10;
			bit++;
		}
		else break;
	}
	return bit;
}
void radix_sort(int* a, int n) {
	//REQUIRE: a is an array,elements in a should all be greater or equal to 0, n is the size of a
	//MODIFY: a
	//EFFECT: sort a in ascending order
	int mbit = maxbit(find_max(a, n));
	int count[10] = { 0 };//a counter for every number on one bit
	int* temp = new int[n] {0};
	for (int bit = 1; bit <= mbit; bit++) {
		int radix = pow(10, bit);
		for (int i = 0; i < 10; i++) {
			count[i] = 0;
		}//initialize the counter
		for (int i = 0; i < n; i++) {
			count[(a[i] % radix) / (radix / 10)]++;
		}//count the number of every bucket
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}//calculate the position
		for (int i = n - 1; i >= 0; i--) {
			temp[count[(a[i] % radix) / (radix / 10)] - 1] = a[i];
			count[(a[i] % radix) / (radix / 10)]--;
		}
		for (int i = 0; i < n; i++) {
			a[i] = temp[i];
		}
	}
	delete[] temp;
}


int main() {
	int a[7] = { 33,303,41,4123,98113,1000,8 };
	//cout << DSelect(a, 0, 6, 2) << endl;;
	//bubble_sort(a, 7);-
	//insertion_sort(a, 7);
	//counting_sort2(a, 7);
	//int temp[7] = { 0 };
	//quick_sort(a, 0,6);
	radix_sort(a, 7);
	cout << "selection_sort:\t";
	for (int i = 0; i < 7; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

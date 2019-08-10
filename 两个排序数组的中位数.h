#pragma once
#include<iostream>
#include<vector>
using namespace std;

double findKposTwoSortArrayMedian(int a[], int m, int b[], int n, int K)
{
	if (m > n)
		return findKposTwoSortArrayMedian(b, n, a, m, K);
	if (m == 0)
		return  b[K - 1];
	if (K == 1)
		return a[K - 1]<b[K - 1] ? a[K - 1] : b[K - 1];


	int medianA = K / 2 < m ? K / 2 : m;
	int medianB = K - medianA;

	if (a[medianA - 1] < b[medianB - 1])
		return findKposTwoSortArrayMedian(a + medianA, m - medianA, b, n, medianB);
	else if (a[medianA - 1] > b[medianB - 1])
		return findKposTwoSortArrayMedian(a, m, b + medianB, n - medianB, medianA);
	else
		return a[medianA - 1];


}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();

	int *a = nums1.data();
	int *b = nums2.data();
	int total = m + n;
	if (total & 1)
		return findKposTwoSortArrayMedian(a, m, b, n, total / 2 + 1);
	else
		return (findKposTwoSortArrayMedian(a, m, b, n, total / 2) + findKposTwoSortArrayMedian(a, m, b, n, total / 2 + 1)) / 2;
}
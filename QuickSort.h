#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <random>
#include <chrono>
#include <cmath>
#include <vector>
#pragma comment (linker, "/STACK:50000000")

template<typename T>
void QuickSort(T* arr, long l, long r)
{
	if (l != r)
	{
		long ind = (l + r) / 2;
		long item = arr[ind];
		long ind1 = l;
		long ind2 = r;
		long tmp;
		while (ind1 <= ind2)
		{
			while ((ind1 <= ind2) && (arr[ind1] < item))
			{
				ind1++;
			}
			while ((ind1 <= ind2) && (arr[ind2] > item))
			{
				ind2--;
			}
			if (ind1 <= ind2)
			{
				tmp = arr[ind1];
				arr[ind1] = arr[ind2];
				arr[ind2] = tmp;
				ind1++;
				ind2--;
			}
		}
		if (ind2 > l)
			QuickSort(arr, l, ind2);
		if (ind1 < r)
			QuickSort(arr, ind1, r);
	}
}
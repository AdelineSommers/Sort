#include <conio.h>
#include <stdio.h>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include "QuickSort.h"
#include "TreeSort.h"

class SortTime {
protected:
	const int low = 1;
	const int up = pow(10, 9);
	const int max_val = pow(10, 4);
	const int step = pow(10, 2);

public:
	std::vector<double> TimeTree1(double* a);
	std::vector<double> TimeQuick1(double* b);
	std::vector<double> TimeTree2(double* a);
	std::vector<double> TimeQuick2(double* b);
	std::vector<double> TimeTree3(double* a);
	std::vector<double> TimeQuick3(double* b);
	std::vector<double> TimeTree4(double* a);
	std::vector<double> TimeQuick4(double* a);
	std::vector<double> TimeTree5(double* a);
	std::vector<double> TimeQuick5(double* a);
	std::vector<double> TimeTree6(double* a);
	std::vector<double> TimeQuick6(double* a);
};

std::vector<double> SortTime::TimeTree1(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resA;
	std::vector<int> arr1;

	arr1.reserve(max_val + 1);

	for (int n = 1; n <= max_val + 1; n += step) {
		// fill array
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(low, up);
		for (int i = 0; i < n; i++) {
			const auto val = distr(gen);
			arr1.push_back(val);
		}
		// record time
		auto t1a = high_resolution_clock::now();
		SORT_AVL(arr1.data(), n);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resA.push_back(s_double1.count());

		arr1.clear();
	}
	return resA;
}

std::vector<double> SortTime::TimeQuick1(double* b) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resB;
	std::vector<int> arr2;

	arr2.reserve(max_val + 1);

	for (int n = 1; n <= max_val + 1; n += step) {
		// fill array
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(low, up);
		for (int i = 0; i < n; i++) {
			const auto val = distr(gen);
			arr2.push_back(val);
		}
		// record time
		auto t3a = high_resolution_clock::now();
		QuickSort(arr2.data(), 0, n - 1);
		auto t4a = high_resolution_clock::now();
		duration<double> s_double2 = t4a - t3a;
		resB.push_back(s_double2.count());

		arr2.clear();
	}
	return resB;
}

std::vector<double> SortTime::TimeTree2(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resA;
	std::vector<int> arr1;

	arr1.reserve(max_val + 1);

	for (int n = 1; n <= max_val + 1; n += step) {
		// fill array
		for (int i = 0; i < n; i++) {
			const auto val = 1 + i;
			arr1.push_back(val);
		}
		// record time
		auto t1a = high_resolution_clock::now();
		SORT_AVL(arr1.data(), n);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resA.push_back(s_double1.count());

		arr1.clear();
	}
	return resA;
}

std::vector<double> SortTime::TimeQuick2(double* b) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resB;
	std::vector<int> arr2;

	arr2.reserve(max_val + 1);

	for (int n = 1; n <= max_val + 1; n += step) {
		// fill array
		for (int i = 0; i < n; i++) {
			const auto val = 1 + i;
			arr2.push_back(val);
		}
		// record time
		auto t3a = high_resolution_clock::now();
		QuickSort(arr2.data(), 0, n - 1);
		auto t4a = high_resolution_clock::now();
		duration<double> s_double2 = t4a - t3a;
		resB.push_back(s_double2.count());

		arr2.clear();
	}
	return resB;
}

std::vector<double> SortTime::TimeTree3(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resA;
	std::vector<int> arr1;

	arr1.reserve(max_val + 1);

	for (int n = 1; n <= max_val + 1; n += step) {
		// fill array
		for (int i = 0; i < n; i++) {
			const auto val = n - i;
			arr1.push_back(val);
		}
		// record time
		auto t1a = high_resolution_clock::now();
		SORT_AVL(arr1.data(), n);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resA.push_back(s_double1.count());

		arr1.clear();
	}
	return resA;
}

std::vector<double> SortTime::TimeQuick3(double* b) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resB;
	std::vector<int> arr2;

	arr2.reserve(max_val + 1);

	for (int n = 1; n <= max_val + 1; n += step) {
		std::cout << "--------------------\n";
		// fill array
		for (int i = 0; i < n; i++) {
			const auto val = n - i;
			arr2.push_back(val);
		}
		// record time
		auto t3a = high_resolution_clock::now();
		QuickSort(arr2.data(), 0, n - 1);
		auto t4a = high_resolution_clock::now();
		duration<double> s_double2 = t4a - t3a;
		resB.push_back(s_double2.count());

		arr2.clear();
	}
	return resB;
}

std::vector<double> SortTime::TimeTree4(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resA;
	std::vector<int> arr1;

	arr1.reserve(max_val + 1);

	for (int new_up = 1; new_up < 100 + 1; new_up++) {
		// fill array
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(low, new_up);
		for (int i = 0; i < max_val; i++) {
			const auto val = distr(gen);
			arr1.push_back(val);
		}
		// record time
		auto t1a = high_resolution_clock::now();
		SORT_AVL(arr1.data(), max_val);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resA.push_back(s_double1.count());

		arr1.clear();
	}
	return resA;
}

std::vector<double> SortTime::TimeQuick4(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resB;
	std::vector<int> arr2;

	arr2.reserve(max_val + 1);

	for (int new_up = 1; new_up < 100 + 1; new_up++) {
		// fill array
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(low, new_up);
		for (int i = 0; i < max_val; i++) {
			const auto val = distr(gen);
			arr2.push_back(val);
		}
		// record time
		auto t1a = high_resolution_clock::now();
		QuickSort(arr2.data(), 0, max_val - 1);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resB.push_back(s_double1.count());

		arr2.clear();
	}
	return resB;
}

std::vector<double> SortTime::TimeTree5(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resA;
	std::vector<int> arr1;
	
	arr1.reserve(max_val + 1);

	for (int new_up = 1; new_up < 100 + 1; new_up++) {
		int block = max_val / new_up;
		int rem = (int)max_val % new_up;
		// fill array
		for (int i = 1; i <= new_up; i++) {
			int j = 0;
			while (j < block) {
				arr1.push_back(i);
				j++;
			}
			if (rem > 0) {
				arr1.push_back(i);
				rem--;
			}
			while (rem > 0 && i == new_up) {
				arr1.push_back(i);
				rem--;
			}
		}
		// record time
		auto t1a = high_resolution_clock::now();
		SORT_AVL(arr1.data(), max_val);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resA.push_back(s_double1.count());

		arr1.clear();
	}
	return resA;
}

std::vector<double> SortTime::TimeQuick5(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resB;
	std::vector<int> arr2;

	arr2.reserve(max_val + 1);

	for (int new_up = 1; new_up < 100 + 1; new_up++) {
		int block = max_val / new_up;
		int rem = (int)max_val % new_up;
		// fill array
		for (int i = 1; i <= new_up; i++) {
			int j = 0;
			while (j < block) {
				arr2.push_back(i);
				j++;
			}
			if (rem > 0) {
				arr2.push_back(i);
				rem--;
			}
			while (rem > 0 && i == new_up) {
				arr2.push_back(i);
				rem--;
			}
		}
		// record time
		auto t1a = high_resolution_clock::now();
		QuickSort(arr2.data(), 0, max_val - 1);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resB.push_back(s_double1.count());

		arr2.clear();
	}
	return resB;
}

std::vector<double> SortTime::TimeTree6(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resA;
	std::vector<int> arr1;

	arr1.reserve(max_val + 1);

	for (int new_up = 1; new_up < 100 + 1; new_up++) {
		int block = max_val / new_up;
		int rem = (int)max_val % new_up;
		// fill array
		for (int i = 1; i <= new_up; i++) {
			int j = 0;
			while (j < block) {
				arr1.push_back(new_up - i + 1);
				j++;
			}
			if (rem > 0) {
				arr1.push_back(new_up - i + 1);
				rem--;
			}
			while (rem > 0 && i == new_up) {
				arr1.push_back(new_up - i + 1);
				rem--;
			}
		}
		// record time
		auto t1a = high_resolution_clock::now();
		SORT_AVL(arr1.data(), max_val);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resA.push_back(s_double1.count());

		arr1.clear();
	}
	return resA;
}

std::vector<double> SortTime::TimeQuick6(double* a) {
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::seconds;

	std::vector<double> resB;
	std::vector<int> arr2;

	arr2.reserve(max_val + 1);

	for (int new_up = 1; new_up < 100 + 1; new_up++) {
		int block = max_val / new_up;
		int rem = (int)max_val % new_up;
		// fill array
		for (int i = 1; i <= new_up; i++) {
			int j = 0;
			while (j < block) {
				arr2.push_back(new_up - i + 1);
				j++;
			}
			if (rem > 0) {
				arr2.push_back(new_up - i + 1);
				rem--;
			}
			while (rem > 0 && i == new_up) {
				arr2.push_back(new_up - i + 1);
				rem--;
			}
		}
		// record time
		auto t1a = high_resolution_clock::now();
		QuickSort(arr2.data(), 0, max_val - 1);
		auto t2a = high_resolution_clock::now();
		duration<double> s_double1 = t2a - t1a;
		resB.push_back(s_double1.count());

		arr2.clear();
	}
	return resB;
}
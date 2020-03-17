// TestCase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class FindDuplicate
{
public:
	FindDuplicate() {}
	FindDuplicate(int arr[], int size);
	int findDupl1(int arr[], int size);
	int findDupl2(int arr[], int size);
	int findDupl3(int arr[], int size);
	int findDupl4(int arr[], int size);
	~FindDuplicate();

private:

};

// Constructor can't return any value
FindDuplicate::FindDuplicate(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j])
				std::cout << arr[i];
		}
	}
	std::cout << -1;
}

// Complete Search
// TC : O(n^2) SC : O(1)
int FindDuplicate::findDupl1(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j])
				return arr[i];
		}
	}
	return INT16_MIN;
}
// sort and search Array
// TC : O(n^2) SC : O(1)
int FindDuplicate::findDupl2(int arr[], int size) {
	sort(arr, arr + size);

	cout << "Sorted Array: " << ends;
	copy(arr, arr + size, ostream_iterator<int>(cout, " "));
	cout << endl;

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1])
			return arr[i];
	}
	return INT16_MIN;
}


// Aux Array
// TC : O(n^2) SC : O(n)
int FindDuplicate::findDupl3(int arr[], int size) {
	int* auxArr = new int[size];
	for (int i = 0; i < size; i++)
		auxArr[i] = 0;

	for (int i = 0; i < size; i++) {
		if (auxArr[arr[i]] != 0)
			return arr[i];
		auxArr[arr[i]] = 1;
	}

	return INT16_MIN;
}

// Negation Trick
// TC : O(n^2) SC : O(1)
int FindDuplicate::findDupl4(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		int temp = abs(arr[i]);
		if (arr[temp] < 0)
			return temp;
		arr[temp] *= -1;
	}

	return INT16_MIN;
}
FindDuplicate::~FindDuplicate()
{
	std::cout << "Distroy " << std::endl;
}
int main()
{
	int arr[] = { 1, 2, 6, 4, 5, 7, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Size of array: " << size << std::endl;
	FindDuplicate obj1;
	//FindDuplicate obj(arr, size);
	std::cout << "Size of array From Function 1 call: " << obj1.findDupl1(arr, size) << std::endl;
	std::cout << "Size of array From Function 2 call: " << obj1.findDupl2(arr, size) << std::endl;
	std::cout << "Size of array From Function 3 call: " << obj1.findDupl3(arr, size) << std::endl;
	std::cout << "Size of array From Function 4 call: " << obj1.findDupl4(arr, size) << std::endl;

	return 0;
}

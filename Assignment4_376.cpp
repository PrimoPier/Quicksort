#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

void swap(int *a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partition(int *a, int low, int high) {
	int pivot = a[low];
	int left = low;
	int right = high;

	while (left < high) {
		/* Move left while item < pivot */
		while (a[left] <= pivot) left++;
		/* Move right while item > pivot */
		while (a[right] > pivot) right--;
		if (left < right)
			swap(a, left, right);
	}
	return left;
}
void quicksort(int *input, int start, int end) {
	if (start < end) {
		int p = partition(input, start, end);
		quicksort(input, start, p-1);
		quicksort(input, p+1, end);
	}
}

int main() {
	fstream file;
	file.open("input.txt");
	if (!file) {
		cerr << "Error opening file." << '\n';
		return 1; // Exit the program with an error code
	}

	int size = 0;
	file >> size;

	int* input = new int[size];

	for (int i=0; i<size; i++) {
		file >> input[i];
	}

	cout << "Display Input Data: ";
	for (int i=0; i<size; i++) {
		cout << input[i] << " ";
	}

	quicksort(input, 0, size-1);

	cout << "\n\nDisplay Ascending Order: ";
	for (int i=0; i<size; i++) {
		cout << input[i] << " ";
	}

	delete[] input;
	file.close();
	return 0;
}

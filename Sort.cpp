#include <concepts>
using namespace std;

class Sort {
private:
	static int partition(int* array, int low, int high) {
		int pivot = array[high];
		int i = low - 1;

		for (int j = low; j < high; ++j) {
			if (array[j] < pivot) {
				++i;
				swap(array[i], array[j]);
			}
		}

		swap(array[i + 1], array[high]);
		return i + 1;
	}

	static void quickSort(int* array, int low, int high) {
		if (low < high) {
			int pivot_index = partition(array, low, high);
			quickSort(array, low, pivot_index - 1);
			quickSort(array, pivot_index + 1, high);
		}
	}

public:
	static void QuickSort(int array[], int size) {
		quickSort(array, 0, size - 1);
	}
};
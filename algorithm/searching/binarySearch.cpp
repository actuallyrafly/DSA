// Binary search sederhana untuk array yang sudah terurut.

#include <iostream>
using namespace std;

int binarySearch(int data[], int ukuran, int target) {
	int kiri = 0;
	int kanan = ukuran - 1;

	while (kiri <= kanan) {
		int tengah = (kiri + kanan) / 2;

		if (data[tengah] == target) {
			return tengah;
		}

		if (data[tengah] < target) {
			kiri = tengah + 1;
		} else {
			kanan = tengah - 1;
		}
	}

	return -1;
}

int main() {
	int data[] = {2, 4, 6, 8, 10, 12, 14};
	int ukuran = sizeof(data) / sizeof(data[0]);
	int target = 10;

	int hasil = binarySearch(data, ukuran, target);

	if (hasil != -1) {
		cout << "Data ditemukan pada indeks ke-" << hasil << endl;
	} else {
		cout << "Data tidak ditemukan" << endl;
	}

	return 0;
}

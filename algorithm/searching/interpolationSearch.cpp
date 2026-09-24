// Interpolation search sederhana untuk array yang sudah terurut.

#include <iostream>
using namespace std;

int interpolationSearch(int data[], int ukuran, int target) {
	int kiri = 0;
	int kanan = ukuran - 1;

	while (kiri <= kanan && target >= data[kiri] && target <= data[kanan]) {
		if (data[kiri] == data[kanan]) {
			return data[kiri] == target ? kiri : -1;
		}

		int posisi = kiri + ((target - data[kiri]) * (kanan - kiri)) /
							(data[kanan] - data[kiri]);

		if (data[posisi] == target) {
			return posisi;
		}

		if (data[posisi] < target) {
			kiri = posisi + 1;
		} else {
			kanan = posisi - 1;
		}
	}

	return -1;
}

int main() {
	int data[] = {10, 20, 30, 40, 50, 60, 70};
	int ukuran = sizeof(data) / sizeof(data[0]);
	int target = 50;

	int hasil = interpolationSearch(data, ukuran, target);

	if (hasil != -1) {
		cout << "Data ditemukan pada indeks ke-" << hasil << endl;
	} else {
		cout << "Data tidak ditemukan" << endl;
	}

	return 0;
}

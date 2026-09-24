// Implementasi struktur data array dinamis sederhana.
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array {
private:
	T* data_;
	size_t size_;
	size_t capacity_;

	void resize(size_t newCapacity) {
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < size_; ++i) {
			newData[i] = data_[i];
		}
		delete[] data_;
		data_ = newData;
		capacity_ = newCapacity;
	}

public:
	explicit Array(size_t initialCapacity = 4)
		: data_(new T[initialCapacity]), size_(0), capacity_(initialCapacity) {}

	~Array() {
		delete[] data_;
	}

	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	void pushBack(const T& value) {
		if (size_ == capacity_) {
			resize(capacity_ == 0 ? 1 : capacity_ * 2);
		}
		data_[size_++] = value;
	}

	void popBack() {
		if (empty()) {
			throw out_of_range("Array kosong");
		}
		--size_;
	}

	T& at(size_t index) {
		if (index >= size_) {
			throw out_of_range("Indeks di luar batas");
		}
		return data_[index];
	}

	const T& at(size_t index) const {
		if (index >= size_) {
			throw out_of_range("Indeks di luar batas");
		}
		return data_[index];
	}

	size_t size() const { return size_; }
	bool empty() const { return size_ == 0; }

	void print() const {
		for (size_t i = 0; i < size_; ++i) {
			cout << data_[i] << (i + 1 == size_ ? '\n' : ' ');
		}
	}
};

int main() {
// Implementasi struktur data array dinamis sederhana.
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
private:
	T* data_;
    size_t size_;
	size_t capacity_;

	void resize(size_t newCapacity) {
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < size_; ++i) {
			newData[i] = data_[i];
		}
		delete[] data_;
		data_ = newData;
		capacity_ = newCapacity;
	}

public:
	explicit Array(size_t initialCapacity = 4)
		: data_(new T[initialCapacity]), size_(0), capacity_(initialCapacity) {}

	~Array() {
		delete[] data_;
	}

	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	void pushBack(const T& value) {
		if (size_ == capacity_) {
			resize(capacity_ == 0 ? 1 : capacity_ * 2);
		}
		data_[size_++] = value;
	}

	void popBack() {
		if (empty()) {
			throw out_of_range("Array kosong");
		}
		--size_;
	}

	T& at(size_t index) {
		if (index >= size_) {
			throw out_of_range("Indeks di luar batas");
		}
		return data_[index];
	}

	const T& at(size_t index) const {
		if (index >= size_) {
			throw out_of_range("Indeks di luar batas");
		}
		return data_[index];
	}

	size_t size() const { return size_; }
	bool empty() const { return size_ == 0; }

	void print() const {
		for (size_t i = 0; i < size_; ++i) {
			cout << data_[i] << (i + 1 == size_ ? '\n' : ' ');
		}
	}
};

int main() {
	std::vector<int> angka;
		angka.pushBack(10);
		angka.pushBack(20);
		angka.pushBack(30);

	angka.pushBack(10);
	angka.pushBack(20);
	angka.pushBack(30);

	for (int nilai : angka) {
			std::cout << nilai << ' ';
		}
		std::cout << '\n';
		cout << "Elemen indeks 1: " << angka.at(1) << '\n';
		cout << "Jumlah elemen: " << angka.size() << '\n';

		return 0;
	}
	cout << "Elemen indeks 1: " << angka.at(1) << '\n';
	cout << "Jumlah elemen: " << angka.size() << '\n';

	return 0;
}

// Implementasi struktur data array dinamis sederhana.
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
	T* data_;
	std::size_t size_;
	std::size_t capacity_;

	void resize(std::size_t newCapacity) {
		T* newData = new T[newCapacity];
		for (std::size_t i = 0; i < size_; ++i) {
			newData[i] = data_[i];
		}
		delete[] data_;
		data_ = newData;
		capacity_ = newCapacity;
	}

public:
	explicit Array(std::size_t initialCapacity = 4)
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
			throw std::out_of_range("Array kosong");
		}
		--size_;
	}

	T& at(std::size_t index) {
		if (index >= size_) {
			throw std::out_of_range("Indeks di luar batas");
		}
		return data_[index];
	}

	const T& at(std::size_t index) const {
		if (index >= size_) {
			throw std::out_of_range("Indeks di luar batas");
		}
		return data_[index];
	}

	std::size_t size() const { return size_; }
	bool empty() const { return size_ == 0; }

	void print() const {
		for (std::size_t i = 0; i < size_; ++i) {
			std::cout << data_[i] << (i + 1 == size_ ? '\n' : ' ');
		}
	}
};

int main() {
	Array<int> angka;
	angka.pushBack(10);
	angka.pushBack(20);
	angka.pushBack(30);

	angka.print();
	std::cout << "Elemen indeks 1: " << angka.at(1) << '\n';
	std::cout << "Jumlah elemen: " << angka.size() << '\n';

	return 0;
}

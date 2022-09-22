#pragma once

#include <array>
#include <stdexcept>


namespace skl {
	template <typename T>
	struct vector {
	public:

		vector() : Size(0), Capacity(1) {
			mainArray = new T[Capacity];
		}

		vector(std::initializer_list<T> initList): Size(0), Capacity(1) {
			mainArray = new T[Capacity];
			for (auto element : initList) {
				this->push_back(element);
			}
		}

		~vector() {
			delete[] mainArray;
		}

		int size() {
			return Size;
		}

		bool isEmpty() {
			return Size == 0;
		}

		void swap(int ind1, int ind2) {
			int temp = mainArray[ind2];
			mainArray[ind2] = mainArray[ind1];
			mainArray[ind1] = temp;
		}

		void push_back(T value) {
			if (Size < Capacity) {
				mainArray[Size] = value;
				Size++;
			}
			else {
				Capacity += 1;
				T* tempArray = new T[Capacity];
				for (int i = 0; i < Size; i++) {
					tempArray[i] = mainArray[i];
				}
				mainArray = tempArray;
				mainArray[Size] = value;
				Size++;
			}
		}

		void erase(int index) {
			if (index >= Size) {
				throw std::out_of_range("Index out of range");
			}
			T* tempArray = new T[Capacity - 1];
			for (int i = 0; i < Size; i++) {
				if (i < index) {
					tempArray[i] = mainArray[i];
				}
				else if (i > index) {
					tempArray[i-1] = mainArray[i];
				}
			}
			delete[] mainArray;
			mainArray = tempArray;
		}

		const T& operator[](const int index) {
			if (index >= Size) {
				throw std::out_of_range("Index out of range");
			}
			return mainArray[index];
		}

		vector* operator=(vector& rightvec) {
			if (Size != rightvec.size()) {
				Capacity = Size = rightvec.size();
				delete[] mainArray;
				mainArray = new T[Capacity];
			}
			for (int i = 0; i < Size; i++) {
				mainArray[i] = rightvec[i];
			}
			return this;
		}

	private:
		T* mainArray;
		int Size;
		int Capacity;
	};
}


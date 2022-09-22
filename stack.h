#pragma once

#include "double_linked_list.h"

namespace skl {
	template <typename T>
	class stack {
	public:
		int size() {
			return mainList.size();
		}

		bool isEmpty() {
			return mainList.isEmpty();
		}

		T peek() {
			return mainList.peek_back();
		}

		void push(T value) {
			mainList.push_back(value);
		}

		void pop() {
			mainList.pop_back();
		}
		

	private:
		skl::DoubleLinkedList<int> mainList;
	};
}
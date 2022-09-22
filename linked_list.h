#pragma once

#include <stdexcept>
#include "list_node.h"

namespace skl {

	template <typename T>
	class LinkedList {
	public:
		ListNode<T>* Head;

		LinkedList() {
			Head = nullptr;
			Size = 0;
		}

		void push_back(T value) {
			if (Head == nullptr) {
				Head = new ListNode<T>(value, nullptr, nullptr);
				Size = 1;
			}
			else {
				ListNode<T>* current = Head;
				while (current->Next != nullptr) {
					current = current->Next;
				}
				current->Next = new ListNode<T>(value, nullptr, nullptr);
				Size++;
			}
		}

		void push_front(T value) {
			if (Head == nullptr) {
				Head = new ListNode<T>(value, nullptr, nullptr);
				Size = 1;
			}
			else {
				ListNode<T>* temp = new ListNode<T>(value);
				temp->Next = Head;
				Head = temp;
				Size++;
			}
		}

		void pop_back() {
			if (Head->Next == nullptr) {
				delete Head;
				Head = nullptr;
				Size = 0;
			}
			else if (Head == nullptr) {
				throw std::out_of_range("Tried to pop out empty list");
			}
			else {
				ListNode<T>* lastTemp = Head;
				ListNode<T>* secondLastTemp = Head;
				lastTemp = lastTemp->Next;
				while (lastTemp->Next != nullptr) {
					lastTemp = lastTemp->Next;
					secondLastTemp = secondLastTemp->Next;
				}
				delete lastTemp;
				secondLastTemp->Next = nullptr;
				Size--;
			}
		}

		void pop_front() {
			if (Head == nullptr) {
				throw std::out_of_range("Tried to pop out empty list");
			}
			else if (Head->Next == nullptr) {
				delete Head;
				Head = nullptr;
				Size = 0;
			}
			else{
				ListNode<T>* temp = Head->Next;
				delete Head;
				Head = temp;
				Size--;
			}
		}

		bool has_value(T value) {
			ListNode<T>* current = Head;
			while (current != nullptr) {
				if (current->data == value) {
					return true;
				}
				current = current->Next;
			}
			return false;
		}

		bool isEmpty() {
			return Size == 0;
		}

		int size() {
			return Size;
		}
	private:
		int Size;
	};

}
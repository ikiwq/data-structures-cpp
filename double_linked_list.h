#pragma once

#include "list_node.h"

namespace skl{
	template <typename T>
	class DoubleLinkedList {
	public:
		DoubleLinkedList(){
			Head = nullptr;
			Tail = nullptr;
			Size = 0;
		}

		void push_back(T value) {
			if (Head == nullptr) {
				Head = new ListNode<T>(value, nullptr, nullptr);
				Tail = Head;
			}
			else if (Head->Next == nullptr) {
				Head->Next = new ListNode<T>(value, Head, nullptr);
				Tail = Head->Next;
			}
			else {
				Tail->Next = new ListNode<T>(value, Tail, nullptr);
				Tail = Tail->Next;
			}
		}

		void pop_back() {
			if (Head == Tail) {
				delete Head;
				delete Tail;
				Head = nullptr;
				Tail = nullptr;
			}
			else if (Head->Next == Tail) {
				delete Tail;
				Tail = nullptr;
				Head->Next = nullptr;
				Tail = Head;
			}
			else {
				ListNode<T>* current = Tail->Previous;
				delete Tail;
				Tail = nullptr;
				Tail = current;
			}
		}

		T peek_back() {
			return Tail->data;
		}
		
		int size() {
			return Size;
		}

		bool isEmpty() {
			return Size == 0;
		}

	public:
		ListNode<T>* Head;
		ListNode<T>* Tail;
		int Size;
	};
}
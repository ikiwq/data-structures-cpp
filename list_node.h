#pragma once

template <typename T>
struct ListNode {
	T data;
	ListNode* Previous;
	ListNode* Next;
	ListNode(T value, ListNode* previous = nullptr, ListNode* next = nullptr)
		:data(value), Previous(previous), Next(next) {}

};
#pragma once

class Node
{
public:// Данные.
	char m_data;

    // Адрес следующего элемента списка.
	Node* m_next;

    // Адрес предыдущего элемента списка.
    Node* m_previous;

    Node(const char data);
};
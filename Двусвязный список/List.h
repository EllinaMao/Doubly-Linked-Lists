#pragma once

#include "Node.h"

template <typename T>
class List
{
    // Голова.
    Node<T>* m_head;
    // Хвост.
    Node<T>* m_tail;

    // Количество элементов.
    unsigned int m_size;

public:
    // Конструкторы и деструктор.
    List();
    List(const List& list);
    ~List();

    // Оператор присваивания.
    List& operator=(const List& right);

    // Методы добавления.
    void AddHead(const T& data);
    void AddTail(const T& data);

    // Копирование списка.
    void Assign(const List& list);

    // Вставка элемента.
    void Insert(const T& data, unsigned int index);

    // Получение элемента по индексу.
    Node<T>* NodeAt(unsigned int index) const;

    // Печать списка.
    void PrintHead() const;
    void PrintTail() const;

    // Удаление элементов.
    void RemoveAll();
    void RemoveAt(unsigned int index);
    void RemoveHead();
    void RemoveTail();

    // Получение размера списка.
    unsigned int GetSize() const;
};

// Реализация методов.

template <typename T>
List<T>::List() : m_head(nullptr), m_tail(nullptr), m_size(0U) {}

template <typename T>
List<T>::List(const List& list) : m_head(nullptr), m_tail(nullptr), m_size(0U)
{
    Assign(list);
}

template <typename T>
List<T>::~List()
{
    RemoveAll();
}

template <typename T>
List<T>& List<T>::operator=(const List& right)
{
    if (this != &right)
    {
        Assign(right);
    }
    return *this;
}

template <typename T>
void List<T>::AddHead(const T& data)
{
    Node<T>* node = new Node<T>(data);

    if (m_size > 0)
    {
        m_head->m_previous = node;
        node->m_next = m_head;
        m_head = node;
    }
    else
    {
        m_head = node;
        m_tail = node;
    }

    ++m_size;
}

template <typename T>
void List<T>::AddTail(const T& data)
{
    Node<T>* node = new Node<T>(data);

    if (m_size > 0U)
    {
        m_tail->m_next = node;
        node->m_previous = m_tail;
        m_tail = node;
    }
    else
    {
        m_head = node;
        m_tail = node;
    }

    ++m_size;
}

template <typename T>
void List<T>::Assign(const List& list)
{
    RemoveAll();

    Node<T>* node = list.m_head;

    while (node != nullptr)
    {
        AddTail(node->m_data);
        node = node->m_next;
    }
}

template <typename T>
void List<T>::Insert(const T& data, unsigned int index)
{
    if (index < m_size)
    {
        if (index == 0U)
        {
            AddHead(data);
        }
        else if (index == m_size - 1U)
        {
            AddTail(data);
        }
        else
        {
            Node<T>* current = NodeAt(index);

            Node<T>* node = new Node<T>(data);

            node->m_previous = current->m_previous;
            node->m_next = current;

            current->m_previous->m_next = node;
            current->m_previous = node;

            ++m_size;
        }
    }
}

template <typename T>
Node<T>* List<T>::NodeAt(unsigned int index) const
{
    Node<T>* node = nullptr;

    if (index < m_size)
    {
        if (index <= m_size / 2U)
        {
            node = m_head;

            unsigned int i = 0U;

            while (i < index)
            {
                node = node->m_next;
                i++;
            }
        }
        else
        {
            node = m_tail;

            unsigned int i = m_size - 1U;

            while (i > index)
            {
                node = node->m_previous;
                i--;
            }
        }
    }

    return node;
}

template <typename T>
void List<T>::PrintHead() const
{
    Node<T>* current = m_head;

    while (current != nullptr)
    {
        // Используем стандартный вывод без std.
        operator<<(operator<<(operator<<(1, current->m_data), ' '), '\n');
        current = current->m_next;
    }
}

template <typename T>
void List<T>::PrintTail() const
{
    Node<T>* current = m_tail;

    while (current != nullptr)
    {
        operator<<(operator<<(operator<<(1, current->m_data), ' '), '\n');
        current = current->m_previous;
    }
}

template <typename T>
void List<T>::RemoveAll()
{
    while (m_head != nullptr)
    {
        RemoveHead();
    }
}

template <typename T>
void List<T>::RemoveAt(unsigned int index)
{
    if (index < m_size)
    {
        if (index == 0U)
        {
            RemoveHead();
        }
        else if (index == m_size - 1U)
        {
            RemoveTail();
        }
        else
        {
            Node<T>* removeElement = NodeAt(index);

            removeElement->m_previous->m_next = removeElement->m_next;
            removeElement->m_next->m_previous = removeElement->m_previous;

            delete removeElement;

            --m_size;
        }
    }
}

template <typename T>
void List<T>::RemoveHead()
{
    if (m_head != nullptr)
    {
        Node<T>* temp = m_head;

        m_head = m_head->m_next;

        if (m_head != nullptr)
        {
            m_head->m_previous = nullptr;
        }
        else
        {
            m_tail = nullptr;
        }

        delete temp;

        --m_size;
    }
}

template <typename T>
void List<T>::RemoveTail()
{
    if (m_tail != nullptr)
    {
        Node<T>* node = m_tail;

        m_tail = m_tail->m_previous;

        if (m_tail != nullptr)
        {
            m_tail->m_next = nullptr;
        }
        else
        {
            m_head = nullptr;
        }

        delete node;

        --m_size;
    }
}

template <typename T>
unsigned int List<T>::GetSize() const
{
    return m_size;
}

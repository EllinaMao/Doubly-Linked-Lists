#pragma once

#include <iostream>
#include "Node.h"

class List
{

    // Голова.
    Node* m_head;
    // Хвост.
    Node* m_tail;

    // Количество элементов.
    unsigned int m_size;

public:

    List();
    List(const List& list);

    ~List();

    List& operator=(const List& right);

    // Добавление в начало списка.
    void AddHead(const char data);

    // Добавление в конец списка.
    void AddTail(const char data);

    void Assign(const List& list);

    // Вставка элемента в заданную позицию.
    void Insert(const char data, unsigned int index);

    // Получить элемент списка по индексу.
    Node* NodeAt(unsigned int index) const;

    // Печать списка, начиная с головы.
    void PrintHead() const;

    // Печать списка, начиная с хвоста.
    void PrintTail() const;

    // Удалить весь список.
    void RemoveAll();

    // Удаление элемента по индексу.
    void RemoveAt(unsigned int index);

    // Удаление головного элемента.
    void RemoveHead();

    // Удаление хвостового элемента.
    void RemoveTail();

    // Получение количества элементов, находящихся в списке.
    unsigned int GetSize() const;
};
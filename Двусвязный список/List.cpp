#include "List.h"

using namespace std;

List::List() :  m_head(nullptr), m_tail(nullptr), m_size(0U)
{
}

List::List(const List& list) :  m_head(nullptr),  m_tail(nullptr),  m_size(0U)
{
    Assign(list);
}

List::~List()
{
    RemoveAll();
}

List& List::operator=(const List& right)
{
    if (this != &right)
    {
        Assign(right);
    }

    return *this;
}

void List::AddHead(const char data)////Person obj, Point obj, double* arr     'a'
{
    Node* node = new Node(data);///'a'
 

       if (m_size > 0)
    {
        m_head->m_previous = node;/////  було  m_head   =   'h'  ,  'j'  'k'  
        node->m_next = m_head;/////тут попереднє значення m_head='h'
        m_head = node;/////перезаписуємо голову списку  стало  m_head   = 'a'  'h'  ,  'j'  'k'
    }
    else
    {
        m_head = node;
        m_tail = node;
    }

    ++m_size;

}

void List::AddTail(const char data)
{
    Node* node = new Node(data);

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

void List::Assign(const List& list)
{
    RemoveAll();

    Node* node = list.m_head;

    while (node != nullptr)
    {
        AddTail(node->m_data);

        node = node->m_next;
    }
}

unsigned int List::GetSize() const
{
    return m_size;
}

void List::Insert(const char data, unsigned int index)
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
			Node* current = NodeAt(index);

            Node* node = new Node(data);

            node->m_previous = current->m_previous;
            node->m_next = current;

            current->m_previous->m_next = node;
            current->m_previous = node;

            ++m_size;
        }
    }
}

Node* List::NodeAt(unsigned int index) const
{
    Node* node = nullptr;

	if (index < m_size)
	{
		if (index <= m_size / 2U)
		{
			node = m_head;

			unsigned int i = 0U;

			while(i < index)
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

void List::PrintHead() const
{
    Node* current = m_head;

    while (current != nullptr)
    {
        cout << current->m_data;

        current = current->m_next;
    }

    cout << endl;
}

void List::PrintTail() const
{
    Node* current = m_tail;
    int ind = m_size - 1;
    while (current != nullptr)
    {
        cout <<ind<< current->m_data;

        current = current->m_previous;
        ind--;
    }

    cout << endl;
}

void List::RemoveAll()
{
    while (m_head != nullptr)
    {
        RemoveHead();
    }
}

void List::RemoveAt(unsigned int index)
{
    if (index < m_size)
    {
        if (index == 0U)
        {
            RemoveHead();
        }
        else if(index == m_size - 1U)
        {
            RemoveTail();
        }
        else
        {
			Node* removeElement = NodeAt(index);

            removeElement->m_previous->m_next = removeElement->m_next;
            removeElement->m_next->m_previous = removeElement->m_previous;

            delete removeElement;

            --m_size;
        }
    }
}

void List::RemoveHead()
{
    if (m_head != nullptr)
    {
        Node* temp = m_head;

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

void List::RemoveTail()
{
    if (m_tail != nullptr)
    {
        Node* node = m_tail;

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
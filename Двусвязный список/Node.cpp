#include "Node.h"

Node::Node(const char data) : 
    m_data(data),
    m_next(nullptr),
    m_previous(nullptr)
{
}
#pragma once
#include "stdafx.h"

template <typename T, bool isReverse>
class CMyIterator : public std::iterator<std::input_iterator_tag, T>
{
public:
	CMyIterator()
		: m_isReverse(isReverse)
	{
	}
	CMyIterator(T* elementPtr)
		: m_node(elementPtr)
		, m_isReverse(isReverse)
	{
	}

	T& operator*() const;
	T* operator->() const;
	CMyIterator& operator++();
	CMyIterator& operator--();
	const CMyIterator operator++(int);
	const CMyIterator operator--(int);
	bool operator==(const CMyIterator& some);
	bool operator!=(const CMyIterator& some);

private:
	T * m_node;
	bool m_isReverse;
};

template<typename T, bool isReverse>
T & CMyIterator<T, isReverse>::operator*() const
{
	return *m_node;
}

template<typename T, bool isReverse>
T * CMyIterator<T, isReverse>::operator->() const
{
	return m_node;
}

template <typename T, bool isReverse>
CMyIterator & CMyIterator<T, isReverse>::operator++()
{
	isReverse ? --m_node : ++m_node;
	return *this;
}

template <typename T, bool isReverse>
CMyIterator & CMyIterator<T, isReverse>::operator--()
{
	return (isReverse) ? (++m_node) : (--m_node);
}

template <typename T, bool isReverse>
const CMyIterator CMyIterator<T, isReverse>::operator++(int)
{
	auto temp = *this;
	if (isReverse)
	{
		--m_node
	}
	else
	{ 
		++m_node
	}
	return temp;
}

template <typename T, bool isReverse>
const CMyIterator CMyIterator<T, isReverse>::operator--(int)
{
	auto temp = *this;

	if (isReverse)
	{
		++m_node
	}
	else
	{
		--m_node
	}

	return temp;
}

template <typename T, bool isReverse>
bool CMyIterator<T, isReverse>::operator==(const CMyIterator & some)
{
	return m_node == some.m_node;
}

template <typename T, bool isReverse>
bool CMyIterator<T, isReverse>::operator!=(const CMyIterator & some)
{
	return m_node != some.m_node;
}




#pragma once


template <typename T>
struct Node
{
	T data;
	Node<T> * prev;
	std::unique_ptr<Node<T>> next;
};

template <typename T>
class CMyList
{
public:
	CMyList() = default;
	
	//возвращает размер списка
	size_t GetSize();

	//добавляет элемент в начало списка
	void PushFront(T const& data);

	//добавлет элемент в конец списка
	void PushBack(T const& data);

	//делает вставку в указанное место
	void insert();
private:
	T m_begin = nullptr;
	T m_end = nullptr;
};

template<typename T>
inline size_t CMyList<T>::GetSize()
{
	return size_t();
}

template<typename T>
inline void CMyList<T>::PushFront(T const & data)
{
}

template<typename T>
inline void CMyList<T>::PushBack(T const & data)
{
}

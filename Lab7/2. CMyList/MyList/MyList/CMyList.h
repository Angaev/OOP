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
	
	//���������� ������ ������
	size_t GetSize();

	//��������� ������� � ������ ������
	void PushFront(T const& data);

	//�������� ������� � ����� ������
	void PushBack(T const& data);

	//������ ������� � ��������� �����
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

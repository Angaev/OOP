#pragma once

template <typename T>
class CMyList
{
public:
	CMyList() = default;
	
	size_t GetSize();

private:
	T m_begin = nullptr;
	T m_end = nullptr;
};


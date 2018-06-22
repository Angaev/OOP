#pragma once
#include "CArrayIterator.h"

template <typename T>
class CMyArray
{
	template <typename T, bool isReverse>
	friend class CArrayIterator;

public:
	typedef CArrayIterator<T, false> iterator;
	typedef CArrayIterator<const T, false> const_iterator;
	typedef CArrayIterator<T, true> reverse_iterator;
	typedef CArrayIterator<const T, true> const_reverse_iterator;


	CMyArray() = default;

	//констуктор копирования
	CMyArray(CMyArray const& arr);

	//констуктор перемещения
	CMyArray(CMyArray&& arr);

	//добавление элемента в конец массива
	void PushBack(T const& value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T *newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// Конструируем копию value по адресу newItemLocation
				new (newEnd)T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// Переключаемся на использование нового хранилища элементов
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	//возвращает количество элементов в массиве
	size_t GetSize() const noexcept
	{
		return m_end - m_begin;
	}

	//переопределяет размер массива
	void ReSize(size_t newSize)
	{
		size_t oldSize = GetSize();
		auto oldEnd = m_end;
		if (newSize < oldSize)
		{
			DestroyItems(m_begin + newSize, m_end);
			m_end = m_begin + newSize;
		}

		size_t currentSize = GetSize();
		while (newSize > currentSize)
		{
			try
			{
				PushBack(T{});
			}
			catch (std::exception const& e)
			{
				if (newSize > currentSize)
				{
					DeleteItems(oldEnd, oldEnd + (currentSize - oldSize));
					m_end = oldEnd;
				}
				throw(e.what());
			}
			currentSize++;
		}
	}
	
	//очищает массив
	void Clear() noexcept
	{
		DeleteItems(m_begin, m_end);
		m_end = m_begin = m_endOfCapacity = nullptr;
	}

	//возвращает размер разметки массива
	size_t GetCapacity() const noexcept
	{
		return m_endOfCapacity - m_begin;
	}

	//индексный доступ к элементам массива
	T& operator[](size_t index)
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("index out of range");
		}

		return *(m_begin + index);
	}
	
	//оператор копирования
	CMyArray& operator=(const CMyArray& arr) noexcept
	{
		if (&arr != this)
		{
			*this = std::move(CMyArray<T>(arr));
		}

		return *this;
	}

	//оператор перемещения
	CMyArray& operator=(CMyArray&& arr)
	{
		if (&arr != this)
		{
			Clear();
			m_begin = arr.m_begin;
			m_end = arr.m_end;
			m_endOfCapacity = arr.m_endOfCapacity;

			arr.m_begin = arr.m_end = arr.m_endOfCapacity = nullptr;

		}

		return *this;
	}

	const_iterator begin() const noexcept
	{
		return const_iterator(m_begin);
	}
	const_iterator end() const noexcept
	{
		return const_iterator(m_end);
	}
	iterator begin() noexcept
	{
		return iterator(m_begin);
	}
	iterator end() noexcept
	{
		return iterator(m_end);
	}
	const_reverse_iterator rbegin() const noexcept
	{
		return const_reverse_iterator(m_end - 1);
	}
	const_reverse_iterator rend() const noexcept
	{
		return const_reverse_iterator(m_begin - 1);
	}
	reverse_iterator rbegin() noexcept
	{
		return reverse_iterator(m_end - 1);
	}
	reverse_iterator rend() noexcept
	{
		return reverse_iterator(m_begin - 1);
	}

private:

	static void DeleteItems(T *begin, T *end)
	{
		// Разрушаем старые элементы
		DestroyItems(begin, end);
		// Освобождаем область памяти для их хранения
		RawDealloc(begin);
	}

	// Копирует элементы из текущего вектора в to, возвращает newEnd
	static void CopyItems(const T *srcBegin, T *srcEnd, T * const dstBegin, T * & dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd)T(*srcBegin);
		}
	}

	static void DestroyItems(T *from, T *to) noexcept
	{
		// dst - адрес объект, при конструирование которого было выброшено исключение
		// to - первый скорнструированный объект
		while (to != from)
		{
			--to;
			// явно вызываем деструктор для шаблонного типа T
			to->~T();
		}
	}

	static T *RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T *p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T *p)
	{
		free(p);
	}


private:
	T * m_begin = nullptr;
	T *m_end = nullptr;
	T *m_endOfCapacity = nullptr;
};

template<typename T>
inline CMyArray<T>::CMyArray(CMyArray const & arr)
{
	const size_t size = arr.GetSize();
	if (size != 0)
	{
		m_begin = RawAlloc(size);
		try
		{
			CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
			m_endOfCapacity = m_end;
		}
		catch (std::exception const& e)
		{
			DeleteItems(m_begin, m_end);
			throw(e.what());
		}

	}
}

template<typename T>
CMyArray<T>::CMyArray(CMyArray && arr)
	: m_begin(arr.m_begin)
	, m_end(arr.m_end)
	, m_endOfCapacity(arr.m_endOfCapacity)
{
	arr.m_begin = arr.m_end = arr.m_endOfCapacity = nullptr;
}


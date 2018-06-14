#pragma once

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	CMyArray(CMyArray const& arr);

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

	size_t GetSize()const
	{
		return m_end - m_begin;
	}

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
	
	void Clear()
	{
		DeleteItems(m_begin, m_end);
		m_end = m_begin = m_endOfCapacity = nullptr;
	}

	size_t GetCapacity()const
	{
		return m_endOfCapacity - m_begin;
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

	static void DestroyItems(T *from, T *to)
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
	const size = arr.getSize();
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
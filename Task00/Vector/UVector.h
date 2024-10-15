#pragma once
#include <assert.h>

// 과제 1. 릭 없애세요.
// 과제 2. 템플릿으로 바꾸세요.
// 5시까지
// 5~6시에 기존에 

//typedef int DataType;

// 중단점이나 디버깅할때 그냥 자료형이 
// 정해져 있는것이 보기가 더 편해서 이방법을 많이 사용했다.
template<typename DataType>
class UVector
{
public:
	~UVector()
	{
		delete[] Datas;
	}

	void reserve(size_t _capacity)
	{
		if (CapacityValue > _capacity)
		{
			return;
		}

		DataType* PrevData = Datas;

		Datas = new DataType[_capacity];

		if (nullptr != PrevData)
		{
			// 기존 데이터를 복사해줘야 한다.
			for (size_t i = 0; i < SizeValue; i++)
			{
				Datas[i] = PrevData[i];
			}

			delete[] PrevData;
			PrevData = nullptr;
		}

		CapacityValue = _capacity;
	}

	size_t capacity() const
	{
		return CapacityValue;
	}

	size_t size() const
	{
		return SizeValue;
	}

	void clear() 
	{
		SizeValue = 0;
	}

	void push_back(DataType _Data)
	{
		if (SizeValue + 1 > CapacityValue)
		{
			// 정확한지는 모르겠습니다.
			reserve(CapacityValue * 1.5);
		}

		// 내부 에러가 안납니다.
		// 그래서 만들때는 Typedef DataType으로 만들는걸선호합니다.
		// _Data->B;

		Datas[SizeValue] = _Data;

		++SizeValue;
	}

	DataType& operator[](size_t _index)
	{
		if (SizeValue <= _index)
		{
			assert(false);
		}

		return Datas[_index];
	}


private:
	DataType* Datas = nullptr;
	size_t CapacityValue = 0;
	size_t SizeValue = 0;
};


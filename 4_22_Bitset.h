#pragma once
namespace pjl
{
	template<size_t N>//用非类型模板参数---N为要往位图里存储多少个数
	class  BitSet
	{
		BitSet()
		{
			_bit.resize(N / 8 + 1);
		}

		void Set(size_t x)//把x值对应的标记为置为1
		{
			//计算x位于哪一个char上
			size_t i = x / 8;
			//计算x位于哪个bit上
			size_t j = x % 8;
			_bit[i] |= (1 << j);
		}

		void ReSet(size_t x)//把x值对应的标记置为0
		{
			//计算x位于哪一个char上
			size_t i = x / 8;
			//计算x位于哪个bit上
			size_t j = x % 8;
			_bit[i] &= (~(1 << j));
		}

		bool Test(size_t x)//判断x是否在这堆数里面
		{
			//计算x位于哪一个char上
			size_t i = x / 8;
			//计算x位于哪个bit上
			size_t j = x % 8;
			return _bit[i] & (1 << j);
		}

		vector<char> _bit;
	};
}
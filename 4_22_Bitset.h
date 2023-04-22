#pragma once
namespace pjl
{
	template<size_t N>//�÷�����ģ�����---NΪҪ��λͼ��洢���ٸ���
	class  BitSet
	{
		BitSet()
		{
			_bit.resize(N / 8 + 1);
		}

		void Set(size_t x)//��xֵ��Ӧ�ı��Ϊ��Ϊ1
		{
			//����xλ����һ��char��
			size_t i = x / 8;
			//����xλ���ĸ�bit��
			size_t j = x % 8;
			_bit[i] |= (1 << j);
		}

		void ReSet(size_t x)//��xֵ��Ӧ�ı����Ϊ0
		{
			//����xλ����һ��char��
			size_t i = x / 8;
			//����xλ���ĸ�bit��
			size_t j = x % 8;
			_bit[i] &= (~(1 << j));
		}

		bool Test(size_t x)//�ж�x�Ƿ������������
		{
			//����xλ����һ��char��
			size_t i = x / 8;
			//����xλ���ĸ�bit��
			size_t j = x % 8;
			return _bit[i] & (1 << j);
		}

		vector<char> _bit;
	};
}
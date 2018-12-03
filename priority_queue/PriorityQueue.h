#pragma once 
#include <iostream>
#include <vector>

using namespace std;
template <class T, class Container = vector<T>>
class PriorityQueue
{
public:
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) >> 1;
		while (parent > 0)
		{
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
		}
	}
	void AdjustDown(size_t parent)
	{
		size_t child = (parent << 1) + 1;
		while (child < _con.size())
		{
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
			{
				++child;
			}
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = (parent << 1) + 1;
			}
		}
	}
	void Push(const T& data)
	{
		_con.push_back(data);
		AdjustUp(_con.size() - 1);
	}
	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		AdjustDown(_con[0]);
	}
	bool Empty()
	{
		return _con.empty();
	}
	size_t Top()
	{

	}
private:
	Container _con;
};

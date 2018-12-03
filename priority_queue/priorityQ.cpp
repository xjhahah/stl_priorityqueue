#include "PriorityQueue.h"

void TestPriorityQ()
{
	PriorityQueue<int> pq;
	pq.Push(1);
	pq.Push(5);
	pq.Push(3);
	pq.Push(6);

	while (!pq.Empty())
	{
		cout << pq.Top() << " ";
		pq.Pop();
	}
	cout << endl;
}

int main()
{
	TestPriorityQ();
	return 0;
}
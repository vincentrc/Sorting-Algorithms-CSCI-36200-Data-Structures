//heap.h
#ifndef heap_H_
#define heap_H_

class heap
{
	public:
		heap();
		~heap();

		void insert(int num);
		int findmin();

	private:
		int heaparray[20000];
		int size;
};

#endif
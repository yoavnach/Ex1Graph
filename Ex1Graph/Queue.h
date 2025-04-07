#include <iostream>
namespace graph
{
	template<typename T> class Queue
	{
	private:
		T* arr;
		int start;
		int end;
		int size;
		int arrLength;

	public:
		Queue<T>()
		{
			this->arr = new T[5];
			this->arrLength = 5;
			this->start = 0;
			this->end = 0;
			this->size = 0;
		}

		bool isEmpty()
		{
			return this->size == 0;
		}

		T peek()
		{
			return this->arr[this->start];
		}
			void add(T add)
			{
				if (this->size == this->arrLength)
				{
					T* newArr = new T[this->arrLength * 2];

					if (this->end < this->start)
					{
						int i;
						for (i = 0; i < this->arrLength-this->start; i++)
						{
							newArr[i] = this->arr[this->start + i];
						}
						for (int j = 0; j < this->end; j++)
						{
							newArr[i + j] = this->arr[j];
						}
					}
					else
					{
						for (int i = 0; i < this->arrLength; i++)
						{
							newArr[i] = this->arr[i];
						}
					}
					delete[] this->arr;
					this->arr = newArr;
					this->start = 0;
					this->end = this->arrLength;
					this->arrLength *= 2;


				}
				if (this->end == this->arrLength)
				{
					this->end = 0;
				}
				this->arr[this->end] = add;
				this->end++;
				this->size++;

			}

			

		

		T pop()
		{
			if (this->isEmpty())
			{
				throw "Empty Queue exception";
			}
			if (this->start == this->arrLength-1)
			{
				this->start = 0;
			}
			T ans = this->arr[this->start];
			this->start++;
			this->size--;
			return ans;
		}

		

		void printQueue()
		{
			if (this->start < this->end)
			{
				std::cout << "{ ";
				for (int i = this->start; i < this->end - 1; i++)
				{
					std::cout << this->arr[i] << ", ";
				}
				std::cout << this->arr[this->end-1] << " }\n";
			}
		}


		~Queue()
		{
			delete[]this->arr;
		}
	};
}

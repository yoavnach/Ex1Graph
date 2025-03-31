#pragma once
namespace graph
{
	template<typename T>
	class MinHeap
	{
	private:
		T* arr;
		int arrLength;
		void pushUp(int index)
		{
			int i = index;
			while (i > 1)
			{
				if (this->arr[i / 2] > this->arr[i])
				{
					T temp = this->arr[i];
					this->arr[i] = this->arr[i / 2];
					this->arr[i / 2] = temp;
				}
				else
				{
					break;
				}
				i /= 2;
			}
		}

		void pushDown(int index)
		{
			int i = index;
			while (i*2<= this->size)
			{
				
				int left = i * 2;
				int right = i * 2 + 1;
				int min=left;
				if (this->arr[left]>this->arr[right])
				{
					min = right;
				}
				if (this->arr[i]<this->arr[min])
				{
					break;
				}
				T temp = this->arr[min];
				this->arr[min] = this->arr[i];
				this->arr[i] = temp;
				i = min;


			}
		}


	public:
		int size;

		MinHeap<T>()
		{
			this->arr = new T[2];
			this->arrLength = 2;
			this->size = 0;
		}

		void add(T add)
		{
			if (this->size == this->arrLength - 1)
			{
				T* newArr = new T[this->arrLength * 2];
				for (int i = 1; i <= this->size; i++)
				{
					newArr[i] = this->arr[i];
				}
				delete[] this->arr;
				this->arr = newArr;
				this->arrLength *= 2;
			}
			this->arr[this->size + 1] = add;
			this->size++;
			this->pushUp(this->size);
		}

		T getMin()
		{
			return this->arr[1];
		}

		T removeMin()
		{
			T ans = this->arr[1];
			this->arr[1] = this->arr[this->size];
			this->size--;
			this->pushDown(1);
			return ans;
		}

		void update(T update)
		{
			int old = 0;
			for (int i = 1; i <= this->size; i++)
			{
				if (this->arr[i] == update)
				{
					old = i;
					break;
				}
			}
			if (old != 0)
			{
				if (update < this->arr[old])
				{
					this->arr[old] = update;
					this->pushUp(old);
				}
				else if(update>this->arr[old])
				{
					this->arr[old] = update;
					this->pushDown(old);
				}
			}
		}

		bool isEmpty()
		{
			return this->size == 0;
		}

		~MinHeap()
		{
			delete[] this->arr;
		}

		
	};
}



namespace graph
{
	template<typename T>
	class Stack
	{
	private:
		T* arr;
		int arrlength;
		
	public:
		int size;
		Stack<T>()
		{
			this->arr = new T[5];
			this->arrlength = 5;
			this->size = 0;
		}

		void push(T add)
		{
			if (this->arrlength == this->size)
			{
				T* newArr = new T[this->arrlength * 2];
				for (int i = 0; i < this->arrlength; i++)
				{
					newArr[i] = this->arr[i];
				}
				delete[] this->arr;
				this->arr = newArr;
				this->arrlength *= 2;
			}
			this->arr[this->size] = add;
			this->size++;
		}

		T peek()
		{
			if (this->isEmpty())
			{
				throw "Empty Stack exception";
			}
			return this->arr[this->size-1];
		}

		T pop()
		{
			if (this->isEmpty())
			{
				throw "Empty Stack exception";
			}
			T ans = this->arr[this->size-1];
			this->size--;
			return ans;
		}

		bool isEmpty()
		{
			return this->size == 0;
		}

		~Stack<T>()
		{
			delete[]this->arr;
		}

	};
}



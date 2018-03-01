
class MinStack
{
	class MinStack
	{
	  private:
		int *elements;
		int size;
		int index; //for top

	  public:
		MinStack()
		{
			// do intialization if necessary
			elements = new int[100];
			size = 100;
			index = 0;
		}
		~MinStack()
		{
			delete[] elements;
		}

		/*
     * @param number: An integer
     * @return: nothing
     */
		void push(int number)
		{
			// write your code here

			if (index >= size)
			{
				// size *= 2;
				int *_eles = new int[size * 2];

				// copy
				for (int i = 0; i != size; ++i)
				{
					_eles[i] = elements[i];
				}

				//update
				delete[] elements;
				elements = _eles;
				size *= 2;
			}

			elements[index] = number;
			++index;
		}

		/*
     * @return: An integer
     */
		int pop()
		{
			// write your code here
			int rv = elements[index - 1];
			index -= 1;
			return rv;
		}

		/*
     * @return: An integer
     */
		int min()
		{
			// write your code here
			int min = elements[0];
			for (int i = 0; i != index; ++i)
			{
				if (elements[i] < min)
					min = elements[i];
			}
			return min;
		}
	};
};
#ifndef Graph_H
#define Graph_H

class DynamicArray {
	public:
		DynamicArray();
		DynamicArray(int arraySize);
		DynamicArray(const DynamicArray &a);
		DynamicArray& operator=(const DynamicArray& rhs);

		int getArraySize() const;
		int getNumOfElements() const;

		string toString() const;
		string toString(int pos) const;

		void addElement(int num);
		void deleteElement(int num);

		~DynamicArray();

	private:
		int *arr;
		int arraySize;
		int numOfElements;
};

#endif
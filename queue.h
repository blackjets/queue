//���� "queue.h" �������� �������� ������ iqueue
//� ��������� "queue.vcproj"
//�����: ������� ��������� ���� ������ 13501/2
#ifndef __iqueue_h
#define __iqueue_h


#include <iostream>
#include <clocale>
	#include <stdlib.h>

using namespace std;


template <class T> class iqueue 
{

protected:

	T massiv[1];

	int size;

public:
	
//�����������

	iqueue(int nsize = 1);


//����������

	~iqueue(void);


 // �������� � �����
 virtual void put(const T& elem) = 0;


 // ����� �� ������
 virtual T take() = 0;


 // �������� ������� �� ������ 0...size-1,
 // 0 ��� ������, size-1 ��� �����
 virtual T get(int i) const = 0;


 // ������ ������ �������
 virtual int size() const = 0;


};


//�����������
iqueue::iqueue(int size)
{
	size = nsize;

	T massiv [size];

	
}
//*******************************************
//����������
iqueue ::~iqueue()
{
	delete [] massiv;
}
//*******************************************
//�������� � �����
virtual void iqueue :: put(const T& elem)
{
T element = elem;

size++;

T tempmass [size];

for (int i=0; i<size-1; i++)
{
	tempmass[i] = massiv[i];
}

delete [] massiv;

tempmass[size] = nelem;

T massiv [size];

for (int i=0; i<size; i++)
{
	massiv[i] = tempmass[i];
}

delete [] tempmass;

			  
};

//*******************************************
//����� �� ������
 virtual T iqueue :: take()
 {
	T tmp;
	
	tmp = massiv[0];
	
	T tempmass[size-1];

	for (int i=1; i<size; i++)
	{
		tempmass[i-1] = massiv[i];
	}

	size--;
	
	delete [] massiv;

	T massiv[size];

	for (int i = 1; i<size; i++)
	{
		massiv[i] = tempmass[i]
	}

	
	delete [] tempmass;


	return tmp;
 };	
 //******************************************
 // �������� ������� �� ������ 0...size-1,
 // 0 ��� ������, size-1 ��� �����
 virtual T iqueue<T> :: get(int i)
 {
	 T temporary;
	
	 int nomer = i;

	 temporary = massiv[nomer];

	 T *tempmass [size-nomer+1];	 
		
	 for (int i=nomer; i<size; i++)
	 {
		 tempmass[i-nomer]=massiv[i];
	 }
		
	 size = size-nomer+1;
		
	delete [] massiv;

	T massiv[size];

	 for (int i=0; i<size; i++)
	 {
		 massiv[i] = tempmass[i];
	 }

	delete [] tempmass;


	 return temporary;
 }
 //******************************************
 // ������ ������ �������
 virtual int iqueue :: size()
 {
	 
 };
#endif


//Файл "queue.h" содержит описание класса iqueue
//в программе "queue.vcproj"
//Автор: Никитин Александр ИИТУ группа 13501/2
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
	
//Конструктор

	iqueue(int nsize = 1);


//Деструктор

	~iqueue(void);


 // добавить в хвост
 virtual void put(const T& elem) = 0;


 // взять из головы
 virtual T take() = 0;


 // получить элемент по номеру 0...size-1,
 // 0 это голова, size-1 это хвост
 virtual T get(int i) const = 0;


 // узнать размер очереди
 virtual int size() const = 0;


};


//Конструктор
iqueue::iqueue(int size)
{
	size = nsize;

	T massiv [size];

	
}
//*******************************************
//Деструктор
iqueue ::~iqueue()
{
	delete [] massiv;
}
//*******************************************
//Добавить в хвост
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
//Взять из головы
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
 // получить элемент по номеру 0...size-1,
 // 0 это голова, size-1 это хвост
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
 // узнать размер очереди
 virtual int iqueue :: size()
 {
	 
 };
#endif


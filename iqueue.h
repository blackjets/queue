#ifndef __IQUEUE_H
#define __IQUEUE_H	

	#include <iostream> 
	#include <clocale>
	#include <stdlib.h>
	
	
	using namespace      // Используем стандартное
               std;      // пространство имен

template < class T > class IQueue
{
public:
	 virtual void put ( const T& elem ) = 0 ;

	 virtual T take ( ) = 0;

	 virtual T get ( int i ) const = 0 ;

	 virtual int size( ) const = 0 ;
};


template < class T > class MyQueue : public IQueue < T >
{
protected:

	T *massiv;  // очередь
	int sizeq;  // Размер очереди

public:
		MyQueue ( )
		{
			sizeq = 0;
			T *massiv;
			massiv = new (nothrow) T [sizeq];
		}

		void put ( const T& elem )
		{
			T element = elem;

			sizeq++;

			T *tempmass;
			tempmass = new (nothrow) T [sizeq];

			for (int i=0; i<sizeq-1; i++)
			{
				tempmass[i] = massiv[i];
			}

			delete [] massiv;

			tempmass[sizeq] = element;

			T *massiv;
			massiv = new (nothrow) T [sizeq];

			for (int i=0; i<sizeq; i++)
			{
				massiv[i] = tempmass[i];
			}

			delete [] tempmass;
		}
							
		T take ( )
		{
		 	T tmp;
	
			tmp = massiv[0];
			
			T *tempmass;
			tempmass = new (nothrow) T [sizeq-1];

			for (int i=1; i<sizeq; i++)
			{
				tempmass[i-1] = massiv[i];
			}

			sizeq--;
			
			delete [] massiv;

			T *massiv;
			massiv = new (nothrow) T [sizeq];

			for (int i = 1; i<sizeq; i++)
			{
				massiv[i] = tempmass[i];
			}

			
			delete [] tempmass;


			return tmp;
		}

		T get ( int i ) const
		{
			 T temporary;
	
			 int nomer = i;

			 temporary = massiv[nomer];

			 T *tempmass;
			 tempmass = new (nothrow) T [sizeq-nomer+1];	 
				
			 for (int i=nomer; i<sizeq; i++)
			 {
				 tempmass[i-nomer]=massiv[i];
			 }
			
			const T hui =sizeq - nomer + 1; 
			sizeq = hui;// sizeq - nomer + 1;
				
			delete [] massiv;

			T *massiv;
			massiv = new (nothrow) T [sizeq];

			 for (int i=0; i<sizeq; i++)
			 {
				 massiv[i] = tempmass[i];
			 }

			delete [] tempmass;


			 return temporary;
		}

		int size() const
		{
				return sizeq;
		}
};
#endif
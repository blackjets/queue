/*Данный класс iqueue реализует контейнер очередь
Программа написана студентом первого курса группы 13501/2
Никитиным Александром, в качестве домашней работы.
Класс написан в MVS 2008, поэтому на более поздних версиях не тестирвоалось.
*/


#ifndef __IQUEUE_H
#define __IQUEUE_H	

	#include <iostream> 
	#include <clocale>
	#include <cstdlib>
	#include <new>
	
	
	using namespace  std;   // Используем стандартное
                            // пространство имен
const int StdSize = 10;

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
	int sizeqm;  // Размер очереди максимальный
	int sizeqc;  //Текущий размер очереди
private:
	void increasesizeqm( unsigned int NewMaximum )
	{
		sizeqm = NewMaximum < sizeqm + 1 ? sizeqm + 1 : NewMaximum;
		T* newqueue = new T [ sizeqm ];
		for ( int i = 0; i < sizeqc; i++)
		{
			newqueue [ i ] = massiv [ i ];
		}
		delete [ ] massiv;
		massiv = newqueue;
	}
public:
	//Конструктор без аргументов
		MyQueue ( )
		{
			sizeqm = StdSize;
			massiv = new (nothrow) T [sizeqm];
			sizeqc = 0;
		}
	//Конструктор копирования
		MyQueue (const MyQueue& MyQueue )
		{
			massiv = new (nothrow) T [MyQueue.sizeqm ];
			sizeqc = MyQueue.sizeqc;
			sizeqm = MyQueue.sizeqm;
			for (unsigned int i = 0; i < sizeqc; i++ )
				massiv [ i ] = MyQueue.massiv [ i ];
		}
	//Деструктор
		~MyQueue ()
		{
			delete [] massiv;
		}

	//перегрузка оператора присваивания
		MyQueue& operator = (const MyQueue& MyQueue )
		{
			if ( this == &MyQueue )
				return *this;
			if ( sizeqm != MyQueue.sizeqm)
			{
				delete [] massiv;
				massiv = new (nothrow) T [MyQueue.sizeqm];
				sizeqm = MyQueue.sizeqm;
			}
			sizeqc = MyQueue.sizeqc;
			for ( unsigned int i = 0; i < sizeqc; i++)
				massiv [ i ] = MyQueue.massiv [i];
			return *this;
		}
	//Вывод в поток
		friend ostream& operator << (ostream& out, const MyQueue& MyQueue )
		{	
			for (int i = 0; i< MyQueue.size(); i++ )
				out << MyQueue.massiv [i] << endl;
			return out;
		}

//*********************************************
	// Сложность O ( n )
//Добавление Элемента в конец очереди
		void put ( const T& elem )
		{
			if ( sizeqc == sizeqm )
				increasesizeqm ( sizeqc + 1 );

				massiv[ sizeqc ] = elem;
				sizeqc++;
			
			return;
					
		}
//*********************************************
	// Сложность О ( n )
	// Т.к. условие блока if выполниться всего один раз =>
	// На каждое действие не будет приходиться ешё n действий, тогда получается, что 
	// f(n) будет иметь вид k*n + m, где k - количество команд, зависящих от n
									  // m - количество команд, не зависящих от n.
//Удаление Элемента из головы очереди
		T take ( )
		{
			cout<<"take is on";
		 	T tmp;
	
			tmp = massiv[0];
			
			for (int i=0; i < sizeqc-1; i++)
			{
				massiv [ i ] = massiv [ i+1 ];
			}
			
			massiv [ sizeqc ] = 0;

			sizeqc--;	

			cout<<"take is off";
			return tmp;
		}
//*********************************************
		//Сложность O(1) так как небходимо вернуть всего 1 элемент
//Полечение элемента по индексу
		T get ( int i ) const
		{
			 T temporary;
	
			 int nomer = i;
			 if ( nomer <= sizeqc )
			 {
			 temporary = massiv[nomer];

			 return temporary;
			 }
			 else exit(-3);
		}
//*********************************************
		//Сложность O(1) так как необходимо вернуть всего 1 элемент
//Возвращает размер очереди(текущий)
		int size() const
		{
				return sizeqc;
		}
};
#endif
/*������ ����� iqueue ��������� ��������� �������
��������� �������� ��������� ������� ����� ������ 13501/2
��������� �����������, � �������� �������� ������.
����� ������� � MVS 2008, ������� �� ����� ������� ������� �� �������������.
*/


#ifndef __IQUEUE_H
#define __IQUEUE_H	

	#include <iostream> 
	#include <clocale>
	#include <cstdlib>
	#include <new>
	
	
	using namespace  std;   // ���������� �����������
                            // ������������ ����
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

	T *massiv;  // �������
	int sizeqm;  // ������ ������� ������������
	int sizeqc;  //������� ������ �������
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
	//����������� ��� ����������
		MyQueue ( )
		{
			sizeqm = StdSize;
			massiv = new (nothrow) T [sizeqm];
			sizeqc = 0;
		}
	//����������� �����������
		MyQueue (const MyQueue& MyQueue )
		{
			massiv = new (nothrow) T [MyQueue.sizeqm ];
			sizeqc = MyQueue.sizeqc;
			sizeqm = MyQueue.sizeqm;
			for (unsigned int i = 0; i < sizeqc; i++ )
				massiv [ i ] = MyQueue.massiv [ i ];
		}
	//����������
		~MyQueue ()
		{
			delete [] massiv;
		}

	//���������� ��������� ������������
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
	//����� � �����
		friend ostream& operator << (ostream& out, const MyQueue& MyQueue )
		{	
			for (int i = 0; i< MyQueue.size(); i++ )
				out << MyQueue.massiv [i] << endl;
			return out;
		}

//*********************************************
	// ��������� O ( n )
//���������� �������� � ����� �������
		void put ( const T& elem )
		{
			if ( sizeqc == sizeqm )
				increasesizeqm ( sizeqc + 1 );

				massiv[ sizeqc ] = elem;
				sizeqc++;
			
			return;
					
		}
//*********************************************
	// ��������� � ( n )
	// �.�. ������� ����� if ����������� ����� ���� ��� =>
	// �� ������ �������� �� ����� ����������� ��� n ��������, ����� ����������, ��� 
	// f(n) ����� ����� ��� k*n + m, ��� k - ���������� ������, ��������� �� n
									  // m - ���������� ������, �� ��������� �� n.
//�������� �������� �� ������ �������
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
		//��������� O(1) ��� ��� ��������� ������� ����� 1 �������
//��������� �������� �� �������
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
		//��������� O(1) ��� ��� ���������� ������� ����� 1 �������
//���������� ������ �������(�������)
		int size() const
		{
				return sizeqc;
		}
};
#endif
#include "iqueue.h"

int main (void)
{
	MyQueue < int > ochered;

	cout<<ochered.size();
	ochered.put(5);
	ochered.put(5);
	ochered.put(5);
	ochered.put(5);
	ochered.put(5);
	cout<<ochered.size();
	int y = ochered.take();
	cout<<ochered.size();
	cout<<ochered.get(3);


}
#include <iostream>
#include "Autocomplete.h"
using namespace std;

int main()
{
	
	Autocomplete autocompete;
	autocompete.insert("hello");
	autocompete.insert("help");
	autocompete.insert("horor");
	autocompete.insert("horse");
	autocompete.insert("half");


	autocompete.insert("win");
	autocompete.insert("won");
	autocompete.insert("winner");

	autocompete.start();
	

	
	
	return 0;
}
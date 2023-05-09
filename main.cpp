#include <iostream>
#include "library.h"

using namespace std;

int main() {


	book tempbook;
	library myLibrary(tempbook);


	myLibrary.createEntry("book", "factoryBook1", "2023", "Tim Atkinson", "Cardiff", "1st");
	myLibrary.createEntry("book", "factoryBook2", "2222", "Kieran", "Cardiff", "2st");
	myLibrary.createEntry("album", "Animals", "1978", "Pink Floyd", "Paramount");
	myLibrary.createEntry("album", "Earthtones", "2001", "Bahamas", "Golden");

	myLibrary.bootUI();





	return 0;
}
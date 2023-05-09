#include "library.h"

using namespace std;

void entry::setInfo(string new_name, string new_borrowedBy, string new_year, bool new_borrowed) {

	name = new_name;
	borrowedBy = new_borrowedBy;
	year = new_year;
	borrowed = new_borrowed;

}


musicAlbum::musicAlbum() {

	artist = "";
	recordLabel = "";

	setInfo("", "", "", false); // Creates the 'entry' object assuming that the item is not being borrowed
}


musicAlbum::musicAlbum(string new_name, string new_borrowedBy, string new_year, bool new_borrowed,
	string new_artist, string new_recordLabel){

	setInfo(new_name, new_borrowedBy, new_year, new_borrowed);
	artist = new_artist; recordLabel = new_recordLabel;


}

void musicAlbum::printDetails() {

	cout << "Name: " << get_name() << ", Artist: " << artist << endl
		<< "Year: " << get_year() << ", Record Label: " << recordLabel << endl;

}

void musicAlbum::setAlbumDetails(string new_name, string new_borrowedBy, string new_year, bool new_borrowed,
	string new_artist, string new_recordLabel) {

	setInfo(new_name, "", new_year, false);
	artist = new_artist;
	recordLabel = new_recordLabel;

}


book::book() {

	author = "";
	publisher = "";
	edition = "";

	setInfo("", "", "", false);


}

book::book(string _author, string _publisher, string _edition, string _name, string _year) {

	author = _author;
	publisher = _publisher;
	edition = _edition;

	setInfo(_name, "", _year, false);

}

void book::printDetails() {

	cout << "Name: " << get_name() << ", Author: " << author << endl
		<< "Year: " << get_year() << ", Publisher: " << publisher << endl
		<< "Edition: " << edition << endl;
}

void book::set_bookInfo(string _author, string _publisher, string _edition, string _name, string _year) {

	author = _author;
	publisher = _publisher;
	edition = _edition;

	setInfo(_name, "", _year, false);

}


entry* library::createEntry(string _type, string _name, string _year, string _author, string _publisher, string _edition) {

	book* newBook = bookFactory();
	newBook->set_bookInfo(_author, _publisher, _edition, _name, _year);
	entries.push_back(newBook);
	return newBook;

}
entry* library::createEntry(string _type, string _name, string _year, string _artist, string _recordLabel) {

	musicAlbum* newAlbum = albumFactory();
	newAlbum->setAlbumDetails(_name, "", _year, false, _artist, _recordLabel);
	entries.push_back(newAlbum);
	return newAlbum;

}



void library::listItems() {

	cout << "Listing Items: \n";

	for (unsigned int i = 0; i < entries.size(); i++) {

		entries.at(i)->printDetails();
		cout << endl;
	}
}

entry* library::searchName(string search) {

	for (unsigned int i = 0; i < entries.size(); i++){

		if (entries.at(i)->get_name() == search) {

			cout << "Item found\n";
			return entries.at(i); break;

		}
	}

	cout << "Item NOT found\n";
	return NULL;

}

void library::borrowItem() {

	string personName, search;

	listItems();

	cout << "Borrowing Item: What is your name? ";
	cin >> personName;


	cout << "Borrowing Item: What is the item you're looking for?";
	cin >> search;

	item = searchName(search);
	item->entryBorrowed(personName);

	cout << "You have borrowed: " << item->get_name() << endl;

	bootUI();


}

void library::returnItem() {

	string itemName;

	cout << "What is the name of the item you're returning? ";
	cin >> itemName;

	item = searchName(itemName);
	item->entryReturned();

	cout << "Item Successfully Returned\n\n";

	bootUI();

}

void library::addItem() {

	string type;

	cout << "Adding new Item: \n";
	cout << "What type of item would you like to add? ('book'/'album')";
	cin >> type;
	cout << "Please enter the following details...\n\n";

	if (type == "book") {

		string _name, _author, _publisher, _edition, _year;
		cout << "Name: "; cin >> _name;
		cout << "Author: "; cin >> _author;
		cout << "Publisher: "; cin >> _publisher;
		cout << "Edition: "; cin >> _edition;
		cout << "Year: "; cin >> _year;

		createEntry(type, _name, _year,_author, _publisher, _edition);

	}

	bootUI();

}

void library::deleteItem() {

	listItems();

	string itemName;

	cout << "What is the name of the item you're deleting? ";
	cin >> itemName;

	for (unsigned int i = 0; i < entries.size(); i++) {

		if (entries.at(i)->get_name() == itemName) {

			cout << "Item found\n";
			entries.erase(entries.begin() + i);
			cout << "Item Erased\n";
		}
	}

	bootUI();
}

void library::bootUI() {

	unsigned int answer;

	cout << "\n--Hello! Welcome to the Library--"
		<< "\nWhat Would you like to do? (int)\n"
		<< "1. List Items\n"
		<< "2. Add Item\n"
		<< "3. Delete Item\n"
		<< "4. Borrow Item\n"
		<< "5. Return Item\n"
		<< "6. Exit UI\n";

	cin >> answer;
	cout << endl;

	if (answer == 1) { listItems(); }
	if (answer == 2) { addItem(); }
	if (answer == 3) { deleteItem(); }
	if (answer == 4) { borrowItem(); }
	if (answer == 5) { returnItem(); }

	else {};




}


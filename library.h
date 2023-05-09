#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class entry {
	 
	bool borrowed;
	string borrowedBy, name, year;


public:

	entry() : borrowed(false), borrowedBy(""), name(""), year("") {};

	void setInfo(string name, string borrowedBy, string year, bool borrowed);
	string get_name() const { return name; }
	string get_year() const { return year; } // done this bc bla bla
	string get_borrowedBy() const { return borrowedBy; }
	bool get_borrowed() const { return borrowed; }

	void entryBorrowed(string borrower) { borrowedBy = borrower, borrowed = true; }
	void entryReturned() { borrowedBy = "", borrowed = false; }

	void virtual printDetails() = 0;

};

class musicAlbum : public entry {

	string artist, recordLabel;

public:
	musicAlbum();// : artist(""), recordLabel("") {};
	musicAlbum(string new_name, string new_borrowedBy, string new_year, bool new_borrowed,
		string new_artist, string new_recordLabel);
	void printDetails() override;
	string get_artist() const { return artist; }
	string get_recordLabel() const { return recordLabel; }
	void setAlbumDetails(string new_name, string new_borrowedBy, string new_year, bool new_borrowed,
		string new_artist, string new_recordLabel);

};

class book : public entry {

	string author, publisher, edition;

public:
	book(); // : author(""), publisher(""), edition("") {};
	book(string _author, string _publisher, string _edition, string _name, string _year);

	string get_author()		const { return author; }
	string get_publisher()	const { return publisher; }
	string get_edition()	const { return edition; }

	void set_bookInfo(string _author, string _publisher, string _edition, string _name, string _year);

	void printDetails() override;
	
};

class library {

private:

	entry* item;
	vector<entry*> entries; // pointer type very important, allows for access to the kids

public:
	library(book iniBook) : item(&iniBook) {};
	book* bookFactory() { return new book; }
	musicAlbum* albumFactory() { return new musicAlbum; }
	entry* createEntry(string _type, string _name, string _year, string _author, string _publisher, string _edition);
	entry* createEntry(string _type, string _name, string _year, string _artist, string _recordLabel);
	entry* get_entry(int i) const { return entries.at(i); }
	entry* searchName(string search);

	// Library UI Functions
	void bootUI();
	void addItem();
	void deleteItem();
	void listItems();
	void borrowItem();
	void returnItem();

};

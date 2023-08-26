#ifndef __INPUT_H_
#define __INPUT_H_

#include <string>

template<typename T> 
void read(map<size_t, T>& books, istream& in);

template<>
void read<Book>(map<size_t, Book>& books, istream& in)
{
	size_t id;

	while (in >> id)
	{
		in.ignore();

		Book b(id, in);
		books[id] = b;
	}
	in.clear();
	in.ignore(1000, '\n');
}

template<typename T>
void print(T obj, ostream& out) {}

template<>
void print<Book>(Book b, ostream& out)
{
	out << "book " << b.getId() << " \"" << b.getTitle() << "\" by \"" << b.getAuthor() << "\" is ";
	if (b.getBorrower().empty())
		out << "\"available\"" << endl;
	else
		out << "\"borrowed by " << b.getBorrower() << "\"" << endl;
}

template<>
void print<map<size_t, Book>*>(map<size_t, Book>* books, ostream& out)
{
	out << "-----\ntotal books: " << books->size() << endl;

	for (auto p : *books)
	{
		print<Book>(p.second, out);
	}
}

template<typename T>
void borrow(T& obj, const string& borrower) {}

template<>
void borrow<Book>(Book& b, const string& borrower)
{
	b.setBorrowed(borrower);
	print<Book>(b, cout);
}

template<typename T>
void borrow(T& obj) {}

template<>
void borrow<Book>(Book& b)
{
	b.setBorrowed();
	print<Book>(b, cout);
}

#endif

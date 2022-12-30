#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <string.h>
using namespace std;

class Book {
public:
	string name;  //����
	string author; //����
	string publisher; //������
	int data;  //����

	friend istream& operator>>(istream& in, Book& book);  // ����>>
	friend ostream& operator<<(ostream& out, const Book& book); // ����<<
	bool operator <(const Book& rhs) const {	// ���� <
		return this->name < rhs.name;
	}
};
istream& operator>>(istream& in,  Book& book) {
	return in >> book.name >> book.author >> book.publisher >> book.data;
}
ostream& operator<<(ostream& out, const Book& book) {
	
	if (book.name == "") {//�������
		return out;
	}
	
	out.setf(std::ios::left);
	out.width(50); out << book.name;
	out.width(20); out << book.author;
	out.width(30); out << book.publisher;
	out.width(10); out << book.data ;
	return out << "\n";
}
void read_books(set<Book> &library) {
	ifstream f("books.txt");
	//ifstream f("C:/Users/ljh/Desktop/books.txt");
	if (!f.is_open()) {
		cout << "can't open f";
		exit(0);
	}
	while (!f.eof()) {
		Book temp_book;
		f >> temp_book;
		library.insert(temp_book);
	}
}
void save(set<Book> &library) {
	ofstream of("ordered.txt");
	//ofstream of("C:/Users/ljh/Desktop/ordered.txt");
	if (!of.is_open()) {
		cout << "can't open f";
		exit(0);
	}
	for (Book b : library) {
		of << b;
	}
}
void sign_in(set<Book>& library) {
	Book temp_book;
	cin >> temp_book;
	library.insert(temp_book);
}
void find_book(set<Book>& library) {
	string in_name;
	cin >> in_name;
	for (const Book &b : library) {
		if (b.name.find(in_name) != string::npos) { //ƥ��ɹ�
			cout << b;
		}
	}
}
void delete_book(set<Book>& library) {
	string in_name;
	cin >> in_name;
	vector<set<Book>::iterator> to_be_delete;//����Ҫɾ�����飬��Ϊһ�߱���һ��ɾ���������
	for (set<Book>::iterator p = library.begin(); p != library.end();p++) {
		if (p->name.find(in_name) != string::npos) { //ƥ��ɹ�
			to_be_delete.push_back(p);
		}
	}
	for (set<Book>::iterator p : to_be_delete) {
		library.erase(p);
	}
}

int main() {
	set<Book> library;
	read_books(library);

	int control_num;
	while (cin >> control_num) {
		switch(control_num) {
		case 0:
			save(library);
			exit(0);
			break;
		case 1:
			sign_in(library);
			break;
		case 2:
			find_book(library);
			break;
		case 3:
			delete_book(library);
			break;

		}
	}
}
#include "BookShop.hpp"

void menu() {
	cout << "-----------> MENU <-----------\n";
	cout << "|                            |\n";
	cout << "|  0. End program            |\n";
	cout << "|  1. Print all books        |\n";
	cout << "|  2. Show available books   |\n";
	cout << "|  3. Show missing books     |\n";
	cout << "|  4. Extract books          |\n";
	cout << "|  5. Add books              |\n";
	cout << "|  6. Add new book           |\n";
	cout << "|  7. Search by genre        |\n";
	cout << "|  8. Search by language     |\n";
	cout << "|  9. Search by price range  |\n";
	cout << "| 10. Remove book            |\n";
	cout << "| 11. Show book shop info    |\n";
	cout << "|                            |\n";
	cout << "------------<><><>------------\n\n";
}

int main()
{
	BookShop bookshop;
	bookshop.getFromFile();
	while (true) {
		system("cls");
		menu();
		cout << "Choose an option: ";
		int o;
		cin >> o;
		system("cls");
		if (o == 0) {
			bookshop.putInFile();
			break;
		}
		else if (o == 1) {
			bookshop.printAll();
		}
		else if (o == 2) {
			bookshop.availableBooks();
		}
		else if (o == 3) {
			bookshop.missingBooks();
		}
		else if (o == 4) {
			bookshop.minusBook();
		}
		else if (o == 5) {
			bookshop.plusBook();
		}
		else if (o == 6) {
			bookshop.addBook();
		}
		else if (o == 7) {
			bookshop.searchByGenre();
		}
		else if (o == 8) {
			bookshop.searchByLanguage();
		}
		else if (o == 9) {
			bookshop.searchByPriceRange();
		}
		else if (o == 10) {
			bookshop.removeBook();
		}
		else if (o == 11) {
			bookshop.printInfo();
		}
		else {
			cout << "Invalid data!\n";
		}
		system("pause");
	}
}


#include <iostream>
#include "LinkedList.h"
#include "Part.h"
#include "OutOfListRange.h"
#include "EmptyList.h"

using namespace std;

int getInt() {
	int num;

	cin >> num;

	// Validation
	while (cin.fail() || num < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid integer >= 0: ";
		cin >> num;
	}

	return num;
}

int main() {
	cout << "Welcome to the part program. View in fullscreen to appreciate the beautiful ASCII art." << endl;
	int n;
	int index;
	int prodNum;
	Part* item;
	LinkedList<Part> list = LinkedList<Part>();

	double price;
	string description;
	string UOM;
	int quantity;

	char run = 'y';

	while (run == 'y') {
		cout << "What would you like to do?\n" << endl;
		cout << " 1) AddItem\n 2) GetItem\n 3) IsInList\n 4) IsEmpty\n 5) Size\n 6) SeeNext\n 7) SeeAt\n 8) Reset\n 9) Display full list\n 10) End\n " << endl;
		cin >> n;

		switch (n) {
		case 1:
			cout << "Enter product number: " << endl;
			cin >> prodNum;

			cout << "Enter description: " << endl;
			cin >> description;

			cout << "Enter price: " << endl;
			cin >> price;

			cout << "Enter UOM: " << endl;
			cin >> UOM;

			cout << "Enter quantity: " << endl;
			cin >> quantity;

			item = new Part(prodNum, description, price, UOM, quantity);
			list.addItem(item);
			break;

		case 2:
			cout << "What item number would you like to get and remove?" << endl;
			prodNum = getInt();
			item = list.getItem(prodNum);

			if (item) {
				cout << "This item was removed: " << endl;
				cout << item->getPartInfo() << endl;
			}
			else {
				cout << "No such item is in the list." << endl;
			}

			delete item;
			break;

		case 3:
			cout << "What item number would you like to check?" << endl;
			prodNum = getInt();
			if (list.isInList(prodNum)) {
				cout << "the item is in the list." << endl;
			}
			else {
				cout << "there is no such item in the list." << endl;
			}
			break;

		case 4: // executes isEmpty function
			if (list.isEmpty()) {
				cout << "The list is empty.";
			}
			else {
				cout << "The list is not empty.";
			}
			cout << endl;
			break;

		case 5: // executes size function
			cout << "Size of List: " << list.size() << endl;
			break;

		case 6: // executes seeNext function
			try {
				item = list.seeNext();
			}
			catch (EmptyList e) {
				cout << "Error: the list is empty." << endl;
				cout << e.what() << endl;
				break;
			}

			if (item != nullptr) {
				item->display();
			}
			else {
				cout << "There are no more items in the list." << endl;
			}

			break;

		case 7:
			cout << "What list position would you like to view? (first position = 0)" << endl;

			index = getInt();
			try {
				list.seeAt(index)->display();
			}
			catch (OutOfListRange e) {
				cout << "Error: item does not exist. (remember the list is zero indexed.)" << endl;
				cout << e.what() << endl;
			}
			break;

		case 8:
			cout << "List position has been reset." << endl;
			list.reset();
			break;

		case 9:
			list.display();
			break;

		case 10:
			run = 'n';
			continue;
		}

		cout << "Continue? y/n" << endl;
		cin >> run;
	}
}
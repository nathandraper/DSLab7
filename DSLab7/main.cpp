#include <iostream>
#include "LinkedList.h"
#include "Part.h"

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
	int n;
	int index;
	int prodNum;
	bool choice;
	Part* item;
	Part* dummy;
	LinkedList<Part> list = LinkedList<Part>();

	double price;
	string description;
	string UOM;
	int quantity;

	char run = 'y';

	while (run == 'y') {
		cout << "Which function would you like to test?\n" << endl;
		cout << " 1) AddItem\n 2) GetItem\n 3) IsInList\n 4) IsEmpty\n 5) Size\n 6) SeeNext\n 7) SeeAt\n 8) Reset\n 9) End\n " << endl;
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
			cin >> prodNum;
			dummy = new Part(prodNum);
			item = list.getItem(dummy);
			cout << "This item was removed: " << endl;
			cout << item->getPartInfo() << endl;
			delete item;
			delete dummy;
			break;

		case 3:
			cout << "What item number would you like to check?" << endl;
			cin >> prodNum;
			dummy = new Part(prodNum);
			if (list.isInList(dummy)) {
				cout << "the item is in the list." << endl;
			}
			else {
				cout << "there is no such item in the list." << endl;
			}
			delete dummy;
			break;

		case 4: // executes isEmpty function
			cout << "Is empty status: ";
			if (list.isEmpty()) {
				cout << "empty";
			}
			else {
				cout << "not empty";
			}
			cout << endl;
			break;

		case 5: // executes size function
			cout << "Size of List: " << list.size() << endl;
			break;

		case 6: // executes seeNext function
			choice = 1;
			while (choice == 1) {
				Part* node = list.seeNext();
				if(node != nullptr)
					cout << node->getPartInfo() << endl;
				else {
					cout << "The next node does not exist" << endl;
				}
				cout << "Would you like to continue to the next node? " << endl;
				choice = getInt();
			}
			break;

		case 7:
			cout << "What list position would you like to view? (first position = 0)" << endl;
			cin >> index;
			list.seeAt(index);
			break;

		case 8:
			cout << "List position has been reset." << endl;
			list.reset();
			break;

		case 9:
			return 0; //executes destructors
		}
		cout << "Continue? y/n" << endl;
		cin >> run;
	}
}
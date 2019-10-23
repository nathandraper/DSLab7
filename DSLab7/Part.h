#pragma once

#include <string>
#include <iostream>

using namespace std;

class Part {

private:

	int partNumber;

	string description;

	double price;

	string UOM;

	int quantityOnHand;

	int leadTime = 5;

public:

	Part(int partNumber = 0) {
		this->partNumber = partNumber;

		this->description = "";

		this->price = 0;

		this->UOM = "";

		this->quantityOnHand = 0;

	}

	Part(int partNumber, string description, double price, string UOM, int quantityOnHand = 0) {

		this->partNumber = partNumber;

		this->description = description;

		this->price = price;

		this->UOM = UOM;

		this->quantityOnHand = quantityOnHand;

	}

	~Part() {



	}

	string getPartInfo() {

		string s = "Part Number: " + to_string(partNumber);

		s += ", Description: " + description;

		return s;

	}

	double getPrice() {

		return price;

	}

	bool inStock() {

		return quantityOnHand > 0;

	}

	bool available(int daysAhead) {

		if (quantityOnHand > 0)

			return true;

		else return daysAhead > leadTime;

	}

	bool operator < (Part const& other) {

		return partNumber < other.partNumber;

	}

	bool operator > (Part const& other) {

		return partNumber > other.partNumber;

	}

	bool operator == (Part const& other) {

		return partNumber == other.partNumber;

	}

	void display() {

		cout << "Part Number: " << partNumber << ", Description: " << description << ", Price: " << price;

	}

};
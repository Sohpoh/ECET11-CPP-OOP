#include<iostream>
#include<string>
using namespace std;

/*(Invoice Class) Create a class called Invoice that a hardware store
might use to represent an invoice for an item sold at the store. An
Invoice should include four pieces of information as data members
a part number (type string), a part description (type string), a
quantity of the item being purchased (type int) and a price per item
(type int). [Note: In subsequent chapters, we'll use numbers that
contain decimal points (e.g., 2.75) called floating-point values to
represent dollar amounts.] Your class should have a constructor
that initializes the four data members. Provide a set and a get
function for each data member. In addition, provide a member
function named getInvoiceAmount that calculates the invoice
amount (i.e., multiplies the quantity by the price per item), then
returns the amount as an int value. If the quantity is not positive, it
should be set to 0. If the price per item is not positive, it should be
set to 0. Write a test program that demonstrates class Invoice's
capabilities.*/

class Invoice {
private:
	string description;
	int partNumber;
	int quantity;
	double price;
public:
	Invoice(string, int, int, double);
	string getDescription();
	void setDescription(string);
	int getPartNumber();
	void setPartNumber(int);
	int getQuantity();
	void setQuantity(int);
	double getPrice();
	void setPrice(double);
	double getInvoiceAmount();
};

Invoice::Invoice(string description, int partNumber, int quantity, double price) {
	setDescription(description);
	setPartNumber(partNumber);
	setQuantity(quantity);
	setPrice(price);
}

string Invoice::getDescription() {
	return description;
}

void Invoice::setDescription(string description) {
	this->description = description;
}

int Invoice::getPartNumber() {
	return partNumber;
}

void Invoice::setPartNumber(int partNumber) {
	this->partNumber = partNumber;
}

int Invoice::getQuantity() {
	return quantity;
}

void Invoice::setQuantity(int quantity) {
	this->quantity = (quantity < 0) ? 0 : quantity;
}

double Invoice::getPrice() {
	return price;
}

void Invoice::setPrice(double price) {
	this->price = (price < 0) ? 0 : price;
}

double Invoice::getInvoiceAmount() {
	return price*quantity;
}



int main() {
	Invoice inv = Invoice();
	inv.setDescription("hello");
	cout << inv.getDescription();
}
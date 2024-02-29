#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
struct Medicine {
	std::string name;
	int quantity;
	double price;
	std::string supplier;
	std::time_t expirationDate;
};
struct Sale {
	std::string medicineName;
	int quantitySold;
	std::time_t saleDate;
	double price;
	double discount;
	double tax;

};
struct Return {
	std::string medicineName;
	int quantity;
	std::time_t returnDate;
	std::string quantityReturned;
};

struct SupplierPayment {
	std::string supplier;
	double amountPaid;
	std::time_t paymentDate;
};

struct Customer {
	std::string name;
	std::string address;
	};
struct CustomerPayment {
	std::string customerName;
	double amountPaid;
	std::time_t paymentDate;
};
struct Employee {
	std::string name;
	std::string position;
	double salary;
};

struct Bill {
	std::string customerName;
	std::vector<Sale> sales;
};

class Chemist {
private:
	std::vector<Medicine> inventory;
	std::vector<Sale> sales;
	std::vector<Return> returns;
	std::vector<SupplierPayment> supplierPayments;
	std::vector<Customer> customers;
	std::vector<CustomerPayment> customerPayments;
	std::vector<Employee> employees;
	std::vector<Bill> bills;

public:
	void addMedicine(const Medicine& medicine) {
		inventory.push_back(medicine);
	}
	void inputMedicine() {
		Medicine medicine;
		cout << "Enter Medicine name: ";
		cin >> medicine.name;
		cout << "Enter quantity: ";
		cin >> medicine.quantity;
		cout << "Enter price: ";
		cin >> medicine.price;
		cout << "Enter supplier: ";
		cin >> medicine.supplier;
		medicine.expirationDate = std::time(0) + 365 * 24 * 60 * 60;//expiration date set one year from now.
		addMedicine(medicine);
	}
#pragma warning(disable : 4996)
	void displayInventory() {
		std::cout << "Inventory:\n";
		for (const auto& medicine : inventory) {
			std::cout << "NAme: " << medicine.name << ", Quantity: " << medicine.quantity << ", Price: " << medicine.price << ", Supplier: " << medicine.supplier << ", Expiration Date: " << ctime(&medicine.expirationDate);
		}
	}

	void displaySales() {
		std::cout << "Sales:\n";
		for (const auto& sale : sales) {
			std::cout << "Medicine Name: " << sale.medicineName << ", Quantity sold: " << sale.quantitySold << ", Sale Date: " << std::ctime(&sale.saleDate) << ", Discount: " << sale.discount << ", Tax: " << sale.tax << "\n";
		}
	}
void displayCustomers() {
	std::cout << "Customers: \n";
	for (const auto& customer : customers) {
		std::cout << "Name: " << customer.name << ", Address: " << customer.address << "\n";

	}
}
void displayReturns() {
	std::cout << "return:\n";
	for (const auto& returnItem : returns) {
		std::cout << "Medicine Name: " << returnItem.medicineName << ", Quantity Returned: " << returnItem.quantityReturned << ", Return Date: " << std::ctime(&returnItem.returnDate);
	}
}
Medicine* searchMedicine(const std::string& name) {
	for (auto& medicine : inventory) {
		if (medicine.name == name) {
			return &medicine;
		}
	}
}

void displayCustomerPayments() {
	std::cout << "Customer Payments:\n";
	for (const auto& payment : customerPayments) {
		std::cout << "Customer Name: " << payment.customerName << ", Amount Paid: " << payment.amountPaid << ", Payment Date: " << std::ctime(&payment.paymentDate);
	}
}
void addSale(const Sale& sale) {
	sales.push_back(sale);
}
void addreturn(const Return& returnItem) {
	returns.push_back(returnItem);
}

void displayEmployees() {
	std::cout << "Employees: \n";
	for (const auto& employee : employees) {
		std::cout << "Name: " << employee.name << ", Position: " << employee.position << ", Salary: " << employee.salary << "\n";
	}
}
void displaySupplierPayments() {
	std::cout << "Supplier Payments:\n";
	for (const auto& payment : supplierPayments) {
		std::cout << "Supplier; " << payment.supplier << ", Amount Paid: " << payment.amountPaid << ", Payment Date: " << std::ctime(&payment.paymentDate);

	}
}
void generateSalesReport() {
	double totalSales = 0.0;
	for (const auto& sale : sales) {
		totalSales += sale.quantitySold * sale.price;	
	}
	std::cout << "Total Sales: " << totalSales << "\n";
}

void addBill(const Bill& bill) {
	bills.push_back(bill);
}
void displayBills() {
	std::cout << "Bills:\n";
	for (const auto& bill : bills) {
		std::cout << "Customer Name: " << bill.customerName << "\n";
		for (const auto& sale : bill.sales) {
			std::cout << "Medicine Name" << sale.medicineName << ", Quantity Sold: " << sale.quantitySold << ", Discount: " << sale.discount << ", Tax: " << sale.tax << "\n";
		}
	}
}
 };
int main() {
	Chemist chemist;
//Input medicine to the inventory
	cout << "Input medicine details: \n";
	chemist.inputMedicine();

	//display the inventory
	chemist.displayInventory();

//Search for medicine
	cout << "Searching for Ibuprofen...\n";
	chemist.searchMedicine("Ibuprofen");
//Add a sale
	cout << "Adding a sale...\n";
	chemist.addSale({"Paracetamol", 5, std::time(0), 0.1, 0.05});
//Add a return
	cout << "Adding a return...\n";
	chemist.addreturn({ "Paracetamol", 1, std::time(0) });
//Display returns
	chemist.displayReturns();
//Add a supplier payment
	cout << "Adding Supplier payments...\n";
	chemist.displaySupplierPayments();
//Display employees
	chemist.displayEmployees();
//Generate a sales report
	cout << "Generating a sales report...\n";
	chemist.displaySales();
//Display returns
	chemist.generateSalesReport();
	return 0;
}
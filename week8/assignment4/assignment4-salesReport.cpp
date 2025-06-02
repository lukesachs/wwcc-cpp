#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct SaleRecord {
    string saleDate;
    string productName;
    string productCategory;
    int quantitySold;
    double pricePerUnit;
    double totalSaleAmount;
};

// Function declarations
void loadSalesData(const string& filename, vector<SaleRecord>& salesList);
bool checkLine(const string& line, vector<SaleRecord>& salesList, int lineNum);
void printReportHeader(ofstream& output);
void printCategoryTotals(ofstream& output, const vector<SaleRecord>& salesList);
void printSalesSummary(ofstream& output, const vector<SaleRecord>& salesList);
void generateReport(const string& outputFilename, const vector<SaleRecord>& salesList);
vector<string> getCategories(const vector<SaleRecord>& salesList);
int main() {

    vector<SaleRecord> salesList;
    const string inputFile = "sales.txt";
    const string outputFile = "salesReport.txt";

    loadSalesData(inputFile, salesList);
    generateReport(outputFile, salesList);

    return 0;
}

// Function definitions
void loadSalesData(const string& filename, vector<SaleRecord>& salesList) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return;
    }

    string line;
    int lineNum = 0;

    while (getline(inputFile, line)) {
        lineNum++;
        bool validLine = checkLine(line, salesList, lineNum);
        if (!validLine) continue;
    }

    inputFile.close();
}

bool checkLine(const string& line, vector<SaleRecord>& salesList, int lineNum) {
    if (line.empty() || line[0] == '#') return false;

    stringstream ss(line);
    string dateStr, productStr, categoryStr, unitsStr, unitPriceStr;

    if (!(ss >> dateStr >> productStr >> categoryStr >> unitsStr >> unitPriceStr)) {
        cerr << "Line " << lineNum << ": Incorrect data format." << endl;
        return false;
    }

    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
        cerr << "Line " << lineNum << ": Date must be in YYYY-MM-DD format." << endl;
        return false;
    }

    int units = stoi(unitsStr);
    double unitPrice = stod(unitPriceStr);

    if (units <= 0 || unitPrice <= 0) {
        cerr << "Line " << lineNum << ": Quantity and price must be positive numbers." << endl;
        return false;
    }

    SaleRecord record;
    record.saleDate = dateStr;
    record.productName = productStr;
    record.productCategory = categoryStr;
    record.quantitySold = units;
    record.pricePerUnit = unitPrice;
    record.totalSaleAmount = unitPrice * static_cast<double>(units);

    salesList.push_back(record);
    return true;
}

vector<string> getCategories(const vector<SaleRecord>& salesList){
    vector<string> categories;
    for (const auto& sale : salesList) {
        bool exists = false;
        for (const auto& cat : categories) {
            if (cat == sale.productCategory) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            categories.push_back(sale.productCategory);
        }
    }
    return categories;
}

void printCategoryTotals(ofstream& output, const vector<SaleRecord>& salesList) {
    output << "Product              Category         Units Sold   Unit Price   Total Revenue" << endl;
    output << "--------------------  ---------------  -----------  -----------  -------------" << endl;
    output << fixed << setprecision(2);

	vector<string> categories = getCategories(salesList);

    for (const auto& category : categories) {
        int totalUnits = 0;
        double totalRevenue = 0.0;
        for (const auto& sale : salesList) {
            if (sale.productCategory == category) {
				output << left << setw(20) << sale.productName << setw(15) << category << right << setw(12) 
				<< sale.quantitySold << setw(12) << sale.pricePerUnit << setw(12) << sale.totalSaleAmount;
                totalUnits += sale.quantitySold;
                totalRevenue += sale.totalSaleAmount;
				output << endl;
            }
        }
		output << "                                     -----------                 -------------" << endl;
        output << left << setw(11) << category << "Subtotal:" << right << setw(27) << totalUnits
			<< setw(24) << totalRevenue << endl;
		output << endl;
    }
    output << endl;
}

void printSalesSummary(ofstream& output, const vector<SaleRecord>& salesList) {
    int totalRecords = salesList.size();
    int totalUnitsSold = 0;
    double totalRevenueSum = 0.0;
    string topProduct;
    double maxRevenue = 0.0;

    for (const auto& sale : salesList) {
        totalUnitsSold += sale.quantitySold;
        totalRevenueSum += sale.totalSaleAmount;
        if (sale.totalSaleAmount > maxRevenue) {
            maxRevenue = sale.totalSaleAmount;
            topProduct = sale.productName;
        }
    }
	double avgSaleValue = 0.0;
	if(totalUnitsSold > 0){
    	avgSaleValue = totalRevenueSum / static_cast<double>(totalUnitsSold);
	}
    output << "=====================================" << endl;
    output << "SUMMARY STATISTICS" << endl;
    output << "=====================================" << endl;
    output << "Total Products Sold: " << totalRecords << endl;
    output << "Total Units Sold: " << totalUnitsSold << endl;
    output << "Total Revenue: $" << fixed << setprecision(2) << totalRevenueSum << endl;
    output << "Average Sale Value: $" << avgSaleValue << endl;
    output << "Best-Selling Product: " << topProduct << " ($" << maxRevenue << ")" << endl;
}

void generateReport(const string& outputFilename, const vector<SaleRecord>& salesList) {
    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "Error: Unable to create output file." << endl;
        return;
    }

    printReportHeader(outputFile);
    printCategoryTotals(outputFile, salesList);
    printSalesSummary(outputFile, salesList);

    outputFile.close();
}

void printReportHeader(ofstream& output) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localTime);

    output << "SALES SUMMARY REPORT" << endl;
    output << "Generated: " << timestamp << endl;
    output << "=====================================" << endl << endl;
}

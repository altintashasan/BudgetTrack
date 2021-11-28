//Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

# include<string>
#include "Category.h"

#define MAX_TRANS 500
using namespace std;
/**\struct transactionData
*\brief Structure for keeping transactionData Info.
*
* 	This structure keeps transaction  informations which
* are each transaction time, amount and short description.
*
*/
struct transactionData
{
	int CatNum,Year,Day,Month;
	double TransAmount;
	string TransDes;
};
/**\class Transaction
*\brief Class for reading from "transaction.txt" file and sorting by date and reporting.
*
* 	This class is reading necessary information from "transaction.txt" file
*  and keeping this information inside of array which has a type of transactionData struct. Then,
*  sorts those transactions  by date.Finally, a report is generated.
*/
class Transaction
{
	public:
		Transaction(Category&);
		//
		transactionData TransArray[MAX_TRANS];
		//
		
		string fileLine;
		//
		void applyTransaction();
	private:
		Category &category;
		void readfile();	
		//
		
		//
		void sortTransDate();
		//
		void printCategory();
		//
		int count;
};

#endif

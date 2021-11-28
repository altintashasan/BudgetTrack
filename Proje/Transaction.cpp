//Transaction.cpp
/* ******************************************************* 
 * Filename		:	Transaction.cpp
 * Author		:	Hasan Altintas		
 * Date			:	08.12.2018
 * Description	:	Transaction Class Implementation
 * ******************************************************/
# include<iostream>
# include<string>
# include<fstream>
#include <iomanip>
#include <algorithm>
#include "Transaction.h"

using namespace std;
/**\brief Constructor For a Transaction object.
*
* The constructor is created an object. When the object is created
* readfile and sorting functions are called.
*/
Transaction::Transaction(Category &a ):count(0),category(a)
{
	readfile();
	sortTransDate();
	cout<<endl;
	
}

/**\brief  Reads informations from "transactions.txt" file.
*
*  This function is used for reading line by line informations
* from "transactions.txt" file. And those are stored in Trans_Array array.
* 
*/
void Transaction::readfile()
{
	fstream fileread;
    fileread.open("transactions.txt", ios::in);
    
	if(fileread.is_open()){
	
    	while(!fileread.eof() && count<500 )
    	{
		
      
			getline(fileread,fileLine);
    
			// stoi converts int from string
			
			TransArray[count].CatNum=stoi(fileLine.substr(0,3));
		
			
			TransArray[count].Year=stoi(fileLine.substr(4,4));
			TransArray[count].Month=stoi(fileLine.substr(9,2));
			TransArray[count].Day=stoi(fileLine.substr(12,2));
			// stod converts string to double
			TransArray[count].TransAmount=stod(fileLine.substr(15,8));
				
			TransArray[count].TransDes=fileLine.substr(24,54);
			count++;
		}
	fileread.close();
	}
	else
	cout<<"Ooops, Something went wrong."<<endl;	    

}

/**\brief Comparing two transactionData struct.
*
*  compareDate() compares two transaction datas
* by category number and year and month and day in a transactionData struct.
* \param a A transactionData object
* \param b Another transactionData object 
*/
bool compareDate(transactionData a,transactionData b)
{
	
		if (a.CatNum != b.CatNum)
			return a.CatNum<b.CatNum;
		if (a.Year != b.Year)
			return a.Year < b.Year;
		if (a.Month != b.Month)
			return a.Month < b.Month;
		
		return a.Day < b.Day;	
}
/**\brief Sorting by budget category number.
*
*  This function sorts TransArray array by Category Number, year, month and day. 
* It uses the sort function which is in algorithm library. 
*/
void Transaction::sortTransDate()
{	
	sort(TransArray,TransArray+count,compareDate);
}

/**\brief Printing Report.
*
*  This function prints a report listing the starting balance for each category, all of the
*transactions for the category, and the ending balance for the category.Each column of 
*the report is labeled in a heading line.Each transaction line of the report 
*includes the date of the transaction, the amount, the current
*category balance and the description (name) of the transaction.
*The transaction description is left justified within its column; all other values is right
*justified.All balance values is rounded to 2 decimal places.  
*/
void Transaction::applyTransaction()
{
	cout.precision(2);//rounding 2 decimal places
	for (int i=0;i<category.getCount();i++)
			{
				cout<<fixed<<right<<category.category_101[i].catName<<endl;
				cout<<"Category:"<<"\t"<<category.category_101[i].catNum<<"\t"
				<<setw(8)<<setfill(' ')<<right<<category.category_101[i].catBal<<endl;
			for(int j=0;j<count;j++)
			{	
				if (category.category_101[i].catNum== TransArray[j].CatNum)
					{
						cout<<"\t"<<right<<TransArray[j].Year<<"/"<<setfill('0')<<setw(2)
						<<right<<TransArray[j].Month
						<<"/"<<setfill('0')<<setw(2)
						<<right<<TransArray[j].Day;
						
						cout<<"\t"<<setw(8)<<setfill(' ')<<right<<TransArray[j].TransAmount;
																		
						cout<<"\t"<<setw(8)<<setfill(' ')<<right<<(category.category_101[i].catBal+=TransArray[j].TransAmount);
						cout<<"\t"<<left<<TransArray[j].TransDes<<endl;
					}
			}	
			cout<<"Category:"<<"\t"<<category.category_101[i].catNum<<"\t"<<setw(8)<<setfill(' ')
			<<right<<category.category_101[i].catBal<<endl;
		}
}
	

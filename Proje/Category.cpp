//Category.cpp
/* ******************************************************* 
 * Filename		:	Category.cpp
 * Author		:	Hasan Altintas		
 * Date			:	08.12.2018
 * Description	:	Category Class Implementation
 * ******************************************************/
# include<iostream>
# include<string>
# include<fstream>
#include <algorithm>
#include "Category.h"
/**\brief Constructor For a Category object.
*
* The constructor is created an object. When the object is created
* readfile and sorting functions are called.
*/
Category::Category():count(0)
{
	
	readfile();

	sortBudgetCategory();

}

/**\brief Reads informations from "budget.txt" file.
*
*  This function is used for reading line by line informations
* from "budget.txt" file. And those are stored in category_101 array.
* 
*/

void Category::readfile()
{
	fstream fileread;
    fileread.open("budget.txt", ios::in);
    
	if(fileread.is_open()){
	
    	while(!fileread.eof() && count<MAX_BUDGET )
    	{
		
      
			getline(fileread,fileLine);
    
			// stoi converts int from string
			
			category_101[count].catNum=stoi(fileLine.substr(0,3));
		
			// stod converts string to double
			category_101[count].catBal=stod(fileLine.substr(4,8));
	
			category_101[count].catName=fileLine.substr(12,65);
			count++;
		}
	fileread.close();
	}
	else
	cout<<"Ooops, Something went wrong."<<endl;	    

}


/**\brief Comparing two integer.
*
*  compareCat() compares two category number in a budget struct.
* \param a is a budget object
* \param b is a budget object 
*/
bool compareCat(budget a,budget b)
{
	return a.catNum < b.catNum;
}

/**\brief Sorting by budget category number.
*
*  This function sorts Budget array by Category Number 
* It uses the sort function which is in algorithm library. 
*/

void Category::sortBudgetCategory()
{	
	sort(category_101,category_101+count,compareCat);
}


/**\brief To reach lines in "budget.txt".
*
*  This function returns a number of line/lines in "budget.txt" file. 
* 
*/
int Category::getCount()
{
	return count;
}

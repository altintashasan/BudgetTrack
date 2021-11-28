//Category.h

#ifndef CATEGORY_H
#define CATEGORY_H

# include<iostream>
# include<string>
# include<fstream>

#define MAX_BUDGET 50

using namespace std;
/**\struct budget
*\brief Structure for keeping Budget Category Info.
*
* 	This structure keeps Budget category informations which
* are each Category Number, Balance and Name.
*
*/
struct budget{
	int		catNum;		/*!< Category Number */
	double	catBal;		/*!< Category Balance */
	string	catName;  	/*!< Category Name */
};
/**\class Category
*\brief Class for reading from "budget.txt" file and sorting by budget categories.
*
* 	This class is reading necessary information from "budget.txt" file
*  and keeping this information inside of array which has a type of budget struct. Then,
*  sorting those categories by their number.
*/
class Category
{
	public:
	Category();
	//
	budget category_101[MAX_BUDGET];/*!< Array of budgets */
	//
	string fileLine;/*!< to store one line from budget.txt*/
	//
	int getCount();/*!< to access count member */
	
	
	void printCategory();
	//
	void readfile();	
	//
	void sortBudgetCategory();
	//
	private:
	int count;/*!< it counts how many Category is in txt file.*/
	//
		
};

#endif

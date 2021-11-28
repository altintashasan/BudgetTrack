//proj.cpp
/* ******************************************************* 
 * Filename		:	proj.cpp
 * Author		:	Hasan Altintas		
 * Date			:	08.12.2018
 * Description	:	Driver program for printing a report;
 *This program code is written C++11.
 * ******************************************************/

#include "Transaction.h" 
/**\brief Driver Program.
* 	In driver program, one category object is created. Then, this object is a parameter for Transaction object.
*  Finally,applyTransaction public function is called to print a report.
*/
int main () {

   Category read;
   Transaction reading(read);
   reading.applyTransaction();
   
   
	system("pause");
  
 	return 0;
}


#include "CustomerType.h"

using namespace std;

	//overloaded constructor
CustomerType::CustomerType(int theCustomerNumber, int theArrivalTime,
					int theWaitingTime, int theTransactionTime)
{
	customerNumber = theCustomerNumber;
    arrivalTime = theArrivalTime;
    waitingTime = theWaitingTime; 
    transactionTime = theTransactionTime;
}

	//setCustomerInformation
void CustomerType::setCustomerInfo(int theCustomerNumber, int theArrivalTime,
	int theWaitingTime, int theTransactionTime)
{
	customerNumber = theCustomerNumber;
	arrivalTime = theArrivalTime;
	waitingTime = theWaitingTime;
	transactionTime = theTransactionTime;
}

	//setWaitingTime
void CustomerType::setWaitingTime(int theWaitingTime)
{
	/*********************************************************************************
		your code here...
	*********************************************************************************/
	waitingTime = theWaitingTime;
}

	//getWaitingTime
int CustomerType::getWaitingTime() const
{
	return waitingTime;
}

	//getArrivalTime
int CustomerType::getArrivalTime() const
{
	/*********************************************************************************
		your code here...			
	*********************************************************************************/
	return arrivalTime;
}

	//getTransactionTime
int CustomerType::getTransactionTime() const
{
	/*********************************************************************************
		your code here...			
	*********************************************************************************/
	return transactionTime;
}

	//getCustomerNumber
int CustomerType::getCustomerNumber() const
{
	/*********************************************************************************
		your code here...				
	*********************************************************************************/
	return customerNumber;
}

	//incrementWaitingTime
void CustomerType::incrementWaitingTime()
{
	/*********************************************************************************
		your code here...
	*********************************************************************************/
	++waitingTime;
}

	//destructor
CustomerType::~CustomerType(){}

#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H

#include <queue>

class CustomerType
{
public:
	CustomerType() : customerNumber(0), arrivalTime(0),
		waitingTime(0), transactionTime(0) {}

	CustomerType(int theCustomerNumber, int theArrivalTime,
					int theWaitingTime, int theTransactionTime);

    void setCustomerInfo(int theCustomerNumber, int theArrivalTime,
				         int theWaitingTime, int theTransactionTime);

	void setWaitingTime(int theWaitingTime);
		//Sets the waiting time of a customer.

    int getWaitingTime() const;
		//Returns the waiting time of a customer.

    int getArrivalTime() const;
		//Returns the arrival time of a customer.

    int getTransactionTime() const;
		//Returns the transaction time of a customer.

    int getCustomerNumber() const;
		//Returns the customer number.

	void incrementWaitingTime();
		//Increments the waiting time. 

	~CustomerType();

private:
    int customerNumber;
    int arrivalTime;
    int waitingTime; 
    int transactionTime;
};

#endif
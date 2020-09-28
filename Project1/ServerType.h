#ifndef SERVERTYPE_H
#define SERVERTYPE_H

#include "CustomerType.h"

#include <string>

class ServerType
{
public:
    ServerType() : status("free"), transactionTime(0) {}
           
    void setBusy();
		//Function sets the status of a server to "busy".

    void setFree();
		//Function sets the status of a server to "free".

    void setTransactionTime(int t);
		//Function sets the transaction time according 
        //to the parameter t.

    void setTransactionTime();
		//Function sets the transaction time according 
        //to the transaction time of the current customer.

    void setCurrentCustomer(const CustomerType& theCurrentCustomer);
        //Function sets the info of the current customer 
        //according to the parameter theCurrentCustomer.

    int getCurrentCustomerNumber() const;
        //Function returns the customer number of the 
        //current customer.
        
    int getCurrentCustomerArrivalTime() const;
        //Function returns the arrival time of the current customer.

    int getCurrentCustomerWaitingTime() const;
        //Function returns the current waiting time of the 
        //current customer.

    int getCurrentCustomerTransactionTime() const;
        //Function returns the transaction time of the 
        //current customer.     
    
    int getRemainingTransactionTime() const;
		//Function returns the remaining transaction time.
     
    void decreaseTransactionTime();
		//Function decreases the transaction time by 1.

    bool isFree() const;
        //Function returns true if the server is free; 
        //otherwise, returns false.

	~ServerType();

private:
    CustomerType currentCustomer;
    std::string status;
    int transactionTime; 
};

#endif
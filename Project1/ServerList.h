#ifndef SERVERLIST_H
#define SERVERLIST_H

#include "CustomerType.h"
#include "ServerType.h"

#include <iostream>

class ServerList
{
public:
    ServerList();

    ServerList(int theNumOfServers);
   
    void setServerBusy(int serverID, const CustomerType& theCustomer);
        //To serve the customer specified by theCustomer, the server 
        //    specified by serverID is set to "busy", and the 
        //    transaction time is set according to the customer’s 
        //    transaction time.

    void setServerBusy(int serverID, const CustomerType& theCustomer,
			          int theTransactionTime);
		//To serve the customer specified by theCustomer, the server 
		//	  specified by serverID is set to busy, and the transaction 
		//    time is set according to the parameter theTransactionTime. 

    int getFreeServerID() const;
        //Function searches the list of servers and if a 
        //   free server is found, the function returns its ID; 
        //   otherwise, it returns -1.

    int getNumberOfBusyServers() const;
		//Function returns the number of busy servers.

    void updateServers();
 		//The transaction time of each busy server is decremented
		//    by one time unit. If the transaction time of a busy 
		//    server is reduced to zero, the server is set to
		//    free and a message indicating which customer 
		//    was served, together with the customer's departing 
		//    time, is printed on the screen.

    ~ServerList();

private:
    int numOfServers;
    ServerType *servers;
};

#endif


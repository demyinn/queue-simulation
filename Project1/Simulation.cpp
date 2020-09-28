#include "Simulation.h"

#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

void runSimulation()
{
	/*********************************************************************************
		your code here...
	*********************************************************************************/
	int simulationTime = 0;
	int numOfServers = 0;
	int transactionTime = 0;
	int timeBtwCustArr = 0;
	queue<CustomerType> waitingQ;
	int totalNumOfCustomers = 0;
	int totalWaitingTime = 0;
	setSimulationParameters(simulationTime, numOfServers,
		transactionTime, timeBtwCustArr);
	ServerList servers(numOfServers);
	for (int clock = 1; clock <= simulationTime; ++clock)
	{
		//1)
		servers.updateServers();
		//2)
		if(!waitingQ.empty()) {
			updateCustQueue(waitingQ);
		}
		//3)
		if (isCustomerArrived(timeBtwCustArr)) {
			totalNumOfCustomers++;
			cout << "Customer number " << totalNumOfCustomers
				<< " arrived at time unit " << clock << endl; 
			CustomerType customer(totalNumOfCustomers, 
									clock, 0, transactionTime);
			waitingQ.push(customer);
		}
		//4)
		if (servers.getNumberOfBusyServers() < numOfServers &&
			!waitingQ.empty())
		{
			int serverID = servers.getFreeServerID();
			auto customer = waitingQ.front();
			servers.setServerBusy(serverID, customer);
			totalWaitingTime += customer.getWaitingTime();
			waitingQ.pop();
		}
	}
	cout << "\nSimulation ran for " << simulationTime <<
			" time units" << endl;
	cout << "Number of servers: " << numOfServers << endl;
	cout << "Average transaction time: " << transactionTime << endl;
	cout << "Average arrival time difference between customers: "
		<< timeBtwCustArr << endl;
	generateStatistics(servers, waitingQ, 
		totalNumOfCustomers, totalWaitingTime);
}

void setSimulationParameters(int& simulationTime, int& numOfServers,
	int& transactionTime,
	int& timeBetweenCustomerArrival)
{
	cout << "Enter the simulation time: " << flush;
	cin >> simulationTime;
	cout << endl;

	cout << "Enter the number of servers: " << flush;
	cin >> numOfServers;
	cout << endl;

	cout << "Enter the transaction time: " << flush;
	cin >> transactionTime;
	cout << endl;

	cout << "Enter the time between customer arrivals: " << flush;
	cin >> timeBetweenCustomerArrival;
	cout << endl;
}

bool isCustomerArrived(double arrivalTimeDifference)
{
	double value = 0.0;

	value = static_cast<double> (rand()) / static_cast<double>(RAND_MAX);

	return (value > exp(-1.0 / arrivalTimeDifference));
}


void generateStatistics(ServerList& serverList,
	queue<CustomerType>& customerQueue,
	int numOfCustomersArrived,
	int waitTimeServedCustomers)
{
	int customersLeftInQueue = 0;

	int totalWaitTime = waitTimeServedCustomers;

	CustomerType customer;

	while (!customerQueue.empty())
	{
		customer = customerQueue.front();
		customerQueue.pop();
		totalWaitTime = totalWaitTime + customer.getWaitingTime();
		customersLeftInQueue++;
	}

	//Find number of customers left in servers
	int customersLeftInServers = serverList.getNumberOfBusyServers();
	//Find number of customers completely served
	int numberOfCustomersServed = numOfCustomersArrived -
		customersLeftInServers -
		customersLeftInQueue;

	double averageWaitTime = 0;

	cout << "Total wait time: " << totalWaitTime << endl;
	cout << "Number of customers who completed a transaction: "
		<< numberOfCustomersServed << endl;
	cout << "Number of customers left in the servers: "
		<< customersLeftInServers << endl;
	cout << "Number of customers left in the queue: " << customersLeftInQueue
		<< endl;

	if (numOfCustomersArrived > 0)  // If number of customers arrived is > 0
		averageWaitTime = (static_cast<double>(totalWaitTime)) / numOfCustomersArrived;

	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Average wait time: " << averageWaitTime << endl;

	cout << "\n************** END SIMULATION *************" << endl;

}

void updateCustQueue(queue<CustomerType>& customerQueue)
{
	CustomerType customer;

	customer.setWaitingTime(-1);
	int wTime = 0;

	customerQueue.push(customer);

	while (wTime != -1)
	{
		customer = customerQueue.front();
		customerQueue.pop();
		wTime = customer.getWaitingTime();
		if (wTime != -1)
		{
			customer.incrementWaitingTime();
			customerQueue.push(customer);
		}
	}
}


// Simulation.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX_QUEUE_SIZE	100


typedef struct element {
	int id;
	int arrival_time;
	int service_time_A;
	int service_time_B;
} element;	 	// Customer structure

typedef struct QueueType {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
QueueType queue;
QueueType queueA;
QueueType queueB;
// Real random number generation function between 0 and 1
double random() {
	return rand() / (double)RAND_MAX;
}

// Various state variables needed for simulation
int duration = 100; // Simulation time
double arrival_prob = 0.7; // Average number of customers arriving in one time unit
int max_serv_time = 5; // maximum service time for one customer
int clock;


// Results of the simulation
int customers; // Total number of customers
int served_customers; // Number of customers served
int waited_time; // Time the customers waited

// Empty state detection function
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// Full state detection function
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Insert function
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		printf("Queue is full\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// delete function
element dequeue(QueueType* q)
{
	if (is_empty(q))
		printf("Queue is empty\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

// Generate a random number.
// If it is smaller than ¡®arrival_prov¡¯, assume that new customer comes in the bank.
int is_customer_arrived()
{
	if (random() < arrival_prob)
		return true;
	else return false;
}
// Insert newly arrived customer into queue
void insert_customer_in_A(int arrival_time)
{
	element customer_at_A;

	customer_at_A.id = customers++;
	customer_at_A.arrival_time = arrival_time;
	customer_at_A.service_time_A = (int)(max_serv_time * random()) + 1;
	enqueue(&queueA, customer_at_A);
	printf("Customer %d comes in A at %d minutes. Service time is %d minutes.\n", customer_at_A.id, customer_at_A.arrival_time, customer_at_A.service_time_A);
}
void insert_customer_in_B(int arrival_time)
{
	element customer_at_B;

	customer_at_B.id = customers++;
	customer_at_B.arrival_time = arrival_time;
	customer_at_B.service_time_B = (int)(max_serv_time * random()) + 1;
	enqueue(&queueB, customer_at_B);
	printf("Customer %d comes in B at %d minutes. Service time is %d minutes.\n", customer_at_B.id, customer_at_B.arrival_time, customer_at_B.service_time_B);
}

// Retrieve the customer waiting in the queue and return the customer's service time.
int remove_customer_at_A()
{
	element customer_at_A;
	int service_time_A = 0;

	if (is_empty(&queueA)) return 0;
	customer_at_A = dequeue(&queueA);
	service_time_A = customer_at_A.service_time_A - 1;
	served_customers++;
	waited_time += clock - customer_at_A.arrival_time;
	printf("Customer %d starts service in A at %d minutes. Wait time was %d minutes.\n", customer_at_A.id, clock, clock - customer_at_A.arrival_time);
	return service_time_A;
}
int remove_customer_at_B()
{
	element customer_at_B;
	int service_time_B = 0;

	if (is_empty(&queueB)) return 0;
	customer_at_B = dequeue(&queueB);
	service_time_B = customer_at_B.service_time_B - 1;
	served_customers++;
	waited_time += clock - customer_at_B.arrival_time;
	printf("Customer %d starts service at B in %d minutes. Wait time was %d minutes.\n", customer_at_B.id, clock, clock - customer_at_B.arrival_time);
	return service_time_B;
}


// Print the statistics.
void print_stat()
{
	printf("Number of customers served = %d\n", served_customers);
	printf("Total wait time =% d minutes\n", waited_time);
	printf("Average wait time per person = %f minutes\n",
		(double)waited_time / served_customers);
	printf("Number of customers still waiting = %d\n", customers - served_customers);
}


// Simulation program
void main()
{
	int service_time_A = 0;
	int service_time_B = 0;


	clock = 0;
	while (clock < duration) {
		clock++;
		printf("Current time=%d\n", clock);
		if (is_customer_arrived() && is_empty(&queueA)) {
			insert_customer_in_A(clock);
		}

		// Check if the customer who is receiving the service is finished.
		if (is_customer_arrived() && !is_empty(&queueA)) {	// the customer is receiving service

			insert_customer_in_B(clock);
		}
		if (service_time_A > 0) {
			service_time_A--;
		}



		// no customer is receiving service. 
		// So, take out a customer from the queue and start the service.
		else {
			service_time_A = remove_customer_at_A();

		}
		if (service_time_B > 0) {
			service_time_B--;
		}
		else {
			service_time_B = remove_customer_at_B();

		}
	}
	print_stat();
}


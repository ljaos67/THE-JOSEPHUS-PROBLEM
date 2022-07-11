/**************************************************************************************************
CSCI 340 - Assignment 06 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
TA: Saiteja Alubelli
Date Due: October 23, 2020

Purpose: The purpose of this program is to implement the josephus elimination logic on an object
of the list container. The function that populates the list values and the function that prints the
list values are defined in josephus.h. A list container is treated like a circle and every mth 
member is removed from the list until there remains one member. 
***************************************************************************************************/

#include "josephus.h"

int main()
{
	// ths list is declared to be populated
	list<string> li;
	args a; // args will hold the members for list size, deletion freqeuncy, and print params
	int p=0; // used later on to remove mth value
	int dcount=0; // used to track index in list since list doesnt support RA iterators
	unsigned  n; 
	unsigned cnt = 0; // tracks removed object count
	cin >> n;
	if(n<1) // makes sure list size and argument deletion frequency is >1
	{
		cout << "input size of n is too low, exiting program...\n";
		exit(1);
	}
	a.N = n;
	cin >> n;
	if(n<1)
	{
		cout << "input size of M is too low exiting program...\n";
		exit(1);
	}
	a.M = n; // sets members of args to input stream
	cin >> n;
	a.K = n;
	init_vals(li,a);
	print_list(li,cnt); // prints initial list
	auto it = li.begin();
	while(li.size()>1)
	{		
		p = (a.M-1)%li.size(); // three cases of which to traverse list
		if((dcount+p) > li.size()) // case where you have passed the end of the list 
		{
			dcount = dcount-li.size(); // tracks how far you passed
			p = (a.M-1)%li.size(); // tells how far to advance
			dcount = (dcount + p);
			advance(it,dcount); // advance function for list 
			it = li.erase(it); // erases element
			it = li.begin(); 
			cnt++;
		}
		else if ((dcount + p) == li.size()) // case where you have reached the end of the list
		{
			dcount=0;
			li.pop_front();
			it = li.begin();
			cnt++;
		}
		else // case where you you remain in the parameters of the list
		{
			dcount = dcount + p;
			advance(it,dcount);
			it = li.erase(it);
			it = li.begin();
			cnt++;
		}
		if(((cnt%a.K)==0)||(cnt==(a.N-1))) // prints at the print frequency and the last value 
		{
	
			print_list(li,cnt);
		}
	}
	cout << "\n";
	return 0;
}


#ifndef H_JOSEPHUS
#define H_JOSEPHUS
/***************************************************************************************
CSCI 340 - Assignment 06 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
TA: Saiteja Alubelli
Date DueL October 23, 2020

Purpose: The purpose of this program is to use the linked list container to represent 
the Josephus elimination method where members are counted and eliminated in a circle. 
In this header file, naming convention for the objects is defined in the SEQ class and
creates a variable of type string to assign to members of a list. In this header file,
we have two functions, one that populates a list with string members and one that prints
the values of the list. The logic that performs the circular elimination will be shown
in josephus.cc.

****************************************************************************************/

// pre-processing directices--input/output streams, string class, list container, and
// algorithm which I don't think I ended up using
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#define NO_LETS  26    // no of letters in English alphabet
#define NO_ITEMS 12    // no of items printed on single line

// struct for input arguments

struct args {
    unsigned N,       // no of initial people   
             M,       // count to eliminate person
             K;       // frequency of printouts
};

// class to generate name tags for people

class SEQ {
private:
    string id;         // name tag for person
    unsigned size, nd; // no of people, no of digits in name tags

    // returns no of digits in name tags
    unsigned find_nd ( const double& sz ) {
        if ( ( sz / NO_LETS ) <= 1 ) return 2;
        else return ( find_nd ( sz / NO_LETS ) + 1 );
    }

public:
    // constructor for name-tag generator
    SEQ ( const unsigned& s = 1 ) : size ( s ) {
        double sz = ( double ) size / 9; nd = find_nd ( sz );
        id = string ( nd, 'A' ); id [ nd - 1 ] = '1'; 
    }

    // returns next name tag in sequence
    string operator ( ) ( ) {
        string tmp = id; int i = nd - 1;
        if ( id [ i ] < '9' ) id [ i ]++;
        else {
            id [ i ] = '1'; bool flag = true;
            for ( i--; i >= 0 && flag; i-- )
                if ( id [ i ] < 'Z' ) { id [ i ]++; flag = false; }
                else id [ i ] = 'A';
        } 
        return tmp;
    }
};

// reads and initializes all input arguments
// this function outputs members of a which were initiallized in main
// then it creates an object of the SEQ class of size a.N which is the
// member of a that defines the initiial size of the list
// we use the () operator of SEQ to print out the name tags for each
// member of list until it fills up to the size
void init_vals(list<string> &li, args &a)
{
	cout << "Number of people? " << a.N << "\n";
	cout << "Index for elimination? " << a.M << "\n";
	cout << "Index for printing? " << a.K << "\n";
	SEQ b(a.N);
	for(int i=0;i<a.N;i++)
	{
		li.push_back(b());
	}
};

// prints all name tags for remaining people after elimination
// This function prints the members of list with a single space
// then creates a newline after 12 objects have printed
// in addition to the list, the function prints the count that 
// keeps track of members that were removed and prints that as well
// if no members have been removed, if 1-9 members have been removed,
// and if 10+ members have been removed are the possible cases
void print_list ( const list < string >&li, const unsigned&cnt )
{
	int icount =0;
	if(cnt==0)
	{
		cout << "\n";
		cout << "Initial group of people" << "\n";
		cout << "-----------------------\n";
		auto it = li.begin();
		while(it!=li.end())
		{
			if(icount<11)
			{
				cout << *it << " ";
				icount++;
			}
			else
			{
				cout << *it << " \n";
				icount=0;
			}
			++it;
		}
	}
	else if((cnt > 0) && (cnt <10)) 
	{
		cout << "\n\n";
		cout << "After eliminating " << cnt << "th person\n";
		cout << "----------------------------\n";
		auto it = li.begin();
		while(it!=li.end())
		{
			if(icount<11)
			{
				cout << *it << " ";
				icount++;
			}
			else
			{
				cout << *it << " \n";
				icount=0;
			}
			++it;
		}
	}
	else
	{
		cout << "\n\n";
		cout << "After eliminating " << cnt << "th person\n";
		cout << "-----------------------------\n";
		auto it = li.begin();
		while(it!=li.end())
		{
			if(icount<11)
			{
				cout << *it << " ";
				icount++;
			}
			else
			{
				cout << *it << " \n";
				icount=0;
			}
			++it;
		}
	}
};

#endif

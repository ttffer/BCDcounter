#include "systemc.h"
using namespace sc_core;
SC_MODULE(bcd)
{
	sc_in<bool> clk;
	//sc_int<7>count;
	int temp;
	SC_CTOR(bcd)
	{
		//SC_CTHREAD(printtime, clk.pos());
		SC_CTHREAD(add, clk.pos());
	}

	void printtime()
	{
		while (true) {
			wait();
			cout << sc_time_stamp() << " time is: " << clk->read() <<endl;
		}
	}

	void add() {
		temp =0;
		while (true) {
			//if (temp == 100) { temp = 0; }
				wait();
				cout << "number is " << temp << endl;
				temp = temp + 1;
				if (temp == 100) { temp = 0; }			
				
			
		}
	}
};
// BCD_counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "systemc.h"
#include "bcd.cpp"
/*
int main()
{
    std::cout << "Hello World!\n";
}*/

#include <systemc>
using namespace sc_core;

SC_MODULE(CLOCK) {
    sc_port<sc_signal_in_if<bool>> clk; // a port to access clock
    SC_CTOR(CLOCK) {
        SC_THREAD(thread); // register a thread process
        sensitive << clk; // sensitive to clock
        dont_initialize();
    }
    void thread() {
        while (true) {
            std::cout << sc_time_stamp() << ", value = " << clk->read() << std::endl; // print current clock value
            wait(); // wait for next clock value change
        }
    }
};

int sc_main(int, char* []) {
   
    sc_clock clk("clk", 1, SC_NS, 0.5,0, SC_NS, false); // 1s period, 0.5s true, 0.5s false, start at 0s, start at false.
    bcd bcd1("mybcd");   // instantiate module
    bcd1.clk(clk);// bind port    
    sc_start(150, SC_NS); // run simulation for 150 ns
    return 0;
}

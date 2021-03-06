
#ifndef SYSC_UP_DOWN_COUNTER
#define SYSC_UP_DOWN_COUNTER

#include <systemc.h>

SC_MODULE( Counter ) {

    // Port declaration
    sc_in_clk    iclk;  // postive edge triggerd
    sc_in<bool>  Reset;  // true for reset
    sc_in<bool>  Enable; // true for counting
    sc_in<bool>  UpDown; // ture for count up
    sc_out<int>  Value;

    // Channel, submodules declaration

    // Constructor declaration
    SC_CTOR( Counter ) {            // registration the constructor of "Counter"
        SC_METHOD( process_method );  // registration entry() as event handler
        dont_initialize();            // method entry() is not made runnable during initialization
        sensitive_pos << iclk;       	// entry() is triggered at positive edge of Clock
        v = 0;                        // give counter initial value
        
        trace_file = sc_create_vcd_trace_file("wave");
        sc_trace(trace_file, v, "value");
        sc_trace(trace_file, iclk, "clk");
        sc_trace(trace_file, Reset, "reset");
        sc_trace(trace_file, Enable, "enablle");
        sc_trace(trace_file, UpDown, "updown");
    }
    
    ~Counter() {
        sc_close_vcd_trace_file(trace_file);
        cout << "Created wave.vcd" << endl;
    }
    
    sc_trace_file* trace_file;
    
    // Process declaration
    void process_method( void );

    // Helper declartion

    // Private data
    int  v;


};

#endif


#include "Counter.h"

void  Counter::process_method( void ) {
    /*- Write the behavior code of the up/down counter here -*/
    if( Reset.read() == true ) {
        // reset to zero
        v = 0;    
    }
    else if( Enable.read() == true ) {

        if(UpDown.read() == true) {
            if (v < 15)
                v++;
            else
                v = 15;
        } else {
            if (v > 0)
                v--;
            else
                v = 0;
        }
    }

    // cout << "Counter::process_method " << sc_time_stamp() << " Value = " << Value.read() << " , v = " << v << endl;

    Value.write( v ); // update the output signal
}
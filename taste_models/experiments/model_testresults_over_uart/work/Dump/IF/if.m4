divert(-1)
/*
*  This m4 file uses the following diverts:
*    1 for overall structure
*    5 for cast functions for GUI parameter subtypes
*    7 for num functions on Enum types
*    10 for signals
*    20 for functions
*/dnl
include(templates.m4)
divert(-1)
define(`m4_teststart00_pi_sp_if',`testentrypoint_pi_sp_if')dnl
define(`m4_teststart00_pi_sp_if_provider',`testentrypoint')dnl
define(`m4_teststart00_samrh71tx',`uartotherend_samrh71tx')dnl
define(`m4_teststart00_samrh71tx_provider',`uartotherend')dnl
define(`m4_uartotherend_samrh71rx',`teststart00_samrh71rx')dnl
define(`m4_uartotherend_samrh71rx_provider',`teststart00')dnl
define(`m4_env_pi_1_cyclic',`teststart00_pi_1_cyclic')dnl
define(`m4_env_PI_1_CYCLIC_provider',`teststart00')dnl
divert(1)dnl
system taste;
/*
 *
 * Data View
 *
 */
include(dataview.if)

type math = abstract
    integer abs(integer);
    real abs(real);
    integer fix(real);
    real power(real, real);
    integer Shift_Left(integer, integer);
    integer Shift_Right(integer, integer);
    integer ceil(real);
    integer floor(real);
    real float(integer);
    integer round(real);
    real sin(real);
    real cos(real);
    integer trunc(real);
endabstract;

type enum_functions = abstract
undivert(7)
endabstract;


divert(20)
m4_c_function(testentrypoint,// ERROR: Interface "pi_sp_if" in function "TestEntryPoint" has unsupported kind: "SPORADIC_OPERATION"

)

m4_c_function(teststart00,(PI_1_CYCLIC,(),(),(), 0),

// ERROR: Interface "samrh71rx" in function "TestStart00" has unsupported kind: "SPORADIC_OPERATION"

)

m4_c_function(uartotherend,// ERROR: Interface "samrh71tx" in function "UartOtherEnd" has unsupported kind: "SPORADIC_OPERATION"

)



divert(1)
type assign = abstract
undivert(5)
endabstract;

/*
 *
 * Interface View
 *
 */
signal set_timer(integer);
signal reset_timer();

undivert(10)

undivert(20)

endsystem;

priorityrules
undivert(30)
endpriorityrules;

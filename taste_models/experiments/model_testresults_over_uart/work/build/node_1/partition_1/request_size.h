#ifndef REQUEST_SIZE_H
#define REQUEST_SIZE_H

#include <stdint.h>

#include "dataview-uniq.h"

// struct used to calculate buffer size for drivers
struct GenericRtems6AllParametersStub
{
    union
    {
        // input ports
        uint8_t teststart00_samrh71rx[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING];

        // output ports
        uint8_t TestStart00_samrh71tx_UartOtherEnd_samrh71tx[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING];

        uint8_t dummy_union_field[1];
    } all_types;
};

// GENERIC_PARTITION_BUFFER_SIZE should be even number
#define GENERIC_PARTITION_BUFFER_SIZE (((sizeof(struct GenericRtems6AllParametersStub) + 1) / 2) * 2)


#define TESTENTRYPOINT_PI_SP_IF_REQUEST_SIZE (1)

#define TESTSTART00_PI_1_CYCLIC_REQUEST_SIZE (1)

#define TESTSTART00_SAMRH71RX_REQUEST_SIZE (asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING)

#define UARTOTHEREND_UARTOTHEREND_SAMRH71TX_REQUEST_SIZE (asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING)

#endif

#include "system_spec.h"
#include <stddef.h>

#include <drivers_config.h>
#include "dataview-uniq.h"



// remote_port_names from partition partition_1
#define SYSTEM_SPEC_UARTOTHEREND_SAMRH71TX_REQUEST_SIZE (asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING)


// remote_port_names from partition partition_2
#define SYSTEM_SPEC_TESTSTART00_SAMRH71RX_REQUEST_SIZE (asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING)


enum SystemBus port_to_bus_map[] = {
    BUS_INVALID_ID,
	BUS_BUS_1,
	BUS_BUS_1,
};

enum RemoteInterface bus_to_port_map[] = {
	INTERFACE_INVALID_ID,
	INTERFACE_TESTSTART00_SAMRH71RX,
	INTERFACE_UARTOTHEREND_SAMRH71TX,
};

struct PartitionBusPair port_to_partition_bus_map[] = {
    { PARTITION_INVALID_ID, BUS_INVALID_ID },
    { PARTITION_2, BUS_BUS_1 },
    { PARTITION_1, BUS_BUS_1 },
};

enum SystemBus device_to_bus_map[SYSTEM_DEVICE_NUMBER] = {
    BUS_BUS_1,
    BUS_BUS_1,
    BUS_INVALID_ID,
};

const void* const device_configurations[SYSTEM_DEVICE_NUMBER] = {
    &pohidrv_node_1_uart1,
    &pohidrv_node_2_uart1,
    NULL,
};

const unsigned packetizer_configurations[SYSTEM_DEVICE_NUMBER] = {
    PACKETIZER_PASSTHROUGH,
    PACKETIZER_PASSTHROUGH,
    PACKETIZER_DEFAULT,
};

int bus_message_size[SYSTEM_BUSES_NUMBER] = {0};

void initialize_system_spec()
{
    bus_message_size[BUS_BUS_1] = (SYSTEM_SPEC_TESTSTART00_SAMRH71RX_REQUEST_SIZE > bus_message_size[BUS_BUS_1]) ? SYSTEM_SPEC_TESTSTART00_SAMRH71RX_REQUEST_SIZE : bus_message_size[BUS_BUS_1];
    bus_message_size[BUS_BUS_1] = (SYSTEM_SPEC_UARTOTHEREND_SAMRH71TX_REQUEST_SIZE > bus_message_size[BUS_BUS_1]) ? SYSTEM_SPEC_UARTOTHEREND_SAMRH71TX_REQUEST_SIZE : bus_message_size[BUS_BUS_1];
}

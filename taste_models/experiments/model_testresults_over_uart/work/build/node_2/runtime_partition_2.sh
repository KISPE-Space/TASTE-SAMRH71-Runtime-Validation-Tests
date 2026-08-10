#!/bin/sh

GENERIC_RUNTIME_COMMON_PATH="${HOME}/tool-inst/include/TASTE-Runtime-Common"
SAMRH71_RTEMS_RUNTIME_PATH="${HOME}/tool-inst/include/TASTE-SAMX-RTEMS-Runtime"
SAMRH71_RTEMS_DRIVERS_PATH="${HOME}/tool-inst/include/TASTE-SAMRH71-RTEMS-Drivers"

mkdir -p "partition_2/runtime/"

echo "Copying TASTE common runtime"
cp -u -r "${GENERIC_RUNTIME_COMMON_PATH}"/src/Broker "partition_2/runtime/"
cp -u -r "${GENERIC_RUNTIME_COMMON_PATH}"/src/Escaper "partition_2/runtime/"
cp -u -r "${GENERIC_RUNTIME_COMMON_PATH}"/src/Packetizer "partition_2/runtime/"
cp -u -r "${GENERIC_RUNTIME_COMMON_PATH}"/src/RuntimeCommon "partition_2/runtime/"

cp -r "${SAMRH71_RTEMS_RUNTIME_PATH}"/src/BrokerLock "partition_2/runtime/"

echo "Copying TASTE SAMRH71 RTEMS runtime"
mkdir -p "partition_2/runtime/SAMX-RTEMS-Runtime"

cp -u -r "${SAMRH71_RTEMS_RUNTIME_PATH}"/src "partition_2/runtime/SAMX-RTEMS-Runtime"

echo "Copying ARM-BSP"
mkdir -p "partition_2/runtime/SAMX-RTEMS-Runtime/arm-bsp"

cp -u -r "${SAMRH71_RTEMS_RUNTIME_PATH}"/arm-bsp "partition_2/runtime/SAMX-RTEMS-Runtime"

echo "Copying TASTE SAMRH71 RTEMS default linker script"
mkdir -p "partition_2/runtime/SAMX-RTEMS-Runtime/linker_script/"

cp -u -r "${SAMRH71_RTEMS_RUNTIME_PATH}"/linker_script "partition_2/runtime/SAMX-RTEMS-Runtime"

echo "Copying TASTE SAMRH71 RTEMS Drivers"
echo "Copying source code of device drivers"
mkdir -p "partition_2/drivers/"
echo "Drivers samrh71_rtems_serial"
cp -u -r "${SAMRH71_RTEMS_DRIVERS_PATH}/samrh71_rtems_serial" "partition_2/drivers"


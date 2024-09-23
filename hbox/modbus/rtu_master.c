#include "modbus.h"

bool modbus_rtu_master_request(modbus_io_interface_t *io,uint8_t function_code,void *context,size_t context_length)
{
    return modbus_io_interface_request(MODBUS_IO_INTERFACE_RTU_MASTER,(modbus_io_interface_t *)io,function_code,context,context_length);
}



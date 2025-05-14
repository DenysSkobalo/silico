#include "device.h"
#include <stdio.h>

Register init_device(uint32_t address) {
    Register dev;
    dev.status = STATUS_READY;
    dev.control = CTRL_ENABLE;
    dev.error_code = ERR_NONE;
    dev.address = address;

    return dev;
}

void set_status(Register* dev, uint16_t status_flags) {
    dev->status |= status_flags;
}

void clear_status(Register* dev, uint8_t status_flags) {
    dev->status &= ~status_flags;
}

void set_data(Register* dev, uint32_t data) {
    dev->data = data;
}

uint32_t get_data(Register* dev) {
    return dev->data;
}

void print_device_register(Register* dev) {
    printf("Register Status: 0x%02X (binary): ", dev->status);
    print_binary(dev->status, 8);

    printf("Register Control: 0x%02X (binary): ", dev->control);
    print_binary(dev->control, 8);

    printf("Register Error Code: 0x%04X (binary): ", dev->error_code);
    print_binary(dev->error_code, 16);

    printf("Register Address: 0x%08X (binary): ", dev->address);
    print_binary(dev->address, 32);
}

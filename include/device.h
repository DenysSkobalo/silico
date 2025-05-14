#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>
#include "utils.h"

#define STATUS_READY     0x01
#define STATUS_BUSY      0x02
#define STATUS_ERROR     0x04
#define STATUS_INTERRUPT 0x08

#define CTRL_ENABLE     0x01
#define CTRL_RESET      0x02
#define CTRL_INT_EN     0x04
#define CTRL_DMA_MODE   0x08

#define ERR_NONE     0x0000
#define ERR_TIMEOUT  0x0001
#define ERR_OVERFLOW 0x0002
#define ERR_PARITY   0x0003
#define ERR_UNKNOWN  0x00FF

#define DEADBEEF_ADDRESS 0xDEADBEEF

typedef struct {
    uint8_t status;
    uint8_t control;
    uint16_t error_code;
    uint32_t address;
    uint32_t data; // поле для зберігання даних
} __attribute__((packed)) Register;

Register init_device(uint32_t address);
void set_status(Register* dev, uint16_t status_flags);
void clear_status(Register* dev, uint8_t status_flags);
void print_device_register(Register* dev);
void set_data(Register* dev, uint32_t data);
uint32_t get_data(Register* dev);

#endif

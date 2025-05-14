#include <stdio.h>
#include <stdint.h>

// Status flags
#define STATUS_READY     0x01
#define STATUS_BUSY      0x02 
#define STATUS_ERROR     0x04 
#define STATUS_INTERRUPT 0x08 

// Control flags
#define CTRL_ENABLE     0x01
#define CTRL_RESET      0x02
#define CTRL_INT_EN     0x04
#define CTRL_DMA_MODE   0x08

// Error codes
#define ERR_NONE     0x0000
#define ERR_TIMEOUT  0x0001
#define ERR_OVERFLOW 0x0002
#define ERR_PARITY   0x0003
#define ERR_UNKNOWN  0x00FF

#define DEADBEEF_ADDRESS 0xDEADBEEF

// 32-bits register controller
typedef struct {
    uint8_t status; 
    uint8_t control;
    uint16_t error_code; 
    uint32_t address; // address in memory or MMIO (Memory Mapped Input/Output)
} __attribute__((packed)) Register;

// Function declarations
Register init_device(uint32_t address);
void set_status(Register* dev, uint16_t status_flags);
void clear_status(Register* dev, uint8_t status_flags);
void print_binary(uint32_t value, int bits);
void print_device_register(Register* dev);

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

void print_binary(uint32_t value, int bits) {
		for (int i = bits - 1; i >= 0; i--) {
			printf("%c", (value & (1 << i)) ? '1' : '0');
		}
		printf("\n");
	}

void print_device_register(Register* dev) {
	printf("Device Status: 0x%02X (binary): ", dev->status);
	print_binary(dev->status, 8);

	printf("Device Control: 0x%02X (binary): ", dev->control);
	print_binary(dev->control, 8);

	printf("Device Error Code: 0x%04X (binary): ", dev->error_code);
	print_binary(dev->error_code, 16);

	printf("Device Address: 0x%08X (binary): ", dev->address);
	print_binary(dev->address, 32);
}

int main() {
    Register dev = init_device(DEADBEEF_ADDRESS);
    set_status(&dev, STATUS_ERROR);
	print_device_register(&dev);
    return 0;
}


#include "device.h"
#include "memory.h"
#include "utils.h"
#include <stdio.h>

int main() {
    // Initialize regsiter
    Register dev = init_device(DEADBEEF_ADDRESS);
    set_status(&dev, STATUS_READY);
	printf("\n-------Info Regsiter------\n");
    print_device_register(&dev);

    set_data(&dev, 0x00000001); 
	printf("\n-------Data in Regsiter------\n");
    printf("hex: 0x%08X\n", get_data(&dev));
    printf("bin: 0b");
    print_binary(get_data(&dev), 32);
    printf("dec: %u\n", get_data(&dev)); 

	return 0;
}

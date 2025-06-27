#include <stdio.h>
int main(void)
{
    int count = 0;
    while(count <= 9)
    {    
        int count2 = count + 1;
        while(count2 <= 9)
        {
            int count3 = count2 + 1;
            while(count3 <= 9)
            {
                printf("Count is %d %y \n", count);
                // printf("Count is %d%d%d \n", count, count2, count3);
                count3 += 1;
            }
            count2 += 1;
        }
        count += 1;
    }
}


#include <stdarg.h>
#include <unistd.h> // For write()

void print_pointer(void *ptr) {
    uintptr_t address = (uintptr_t)ptr;
    const char *hex_digits = "0123456789abcdef";
    char buffer[20]; // Enough for 64-bit address + "0x" + null terminator
    int pos = 0;
    
    // Prefix with "0x"
    buffer[pos++] = '0';
    buffer[pos++] = 'x';
    
    // Handle NULL pointer specially
    if (address == 0) {
        buffer[pos++] = '0';
        buffer[pos++] = '\0';
        write(1, buffer, pos-1);
        return;
    }
    
    // Convert address to hex digits
    int started = 0;
    for (int shift = sizeof(void*) * 8 - 4; shift >= 0; shift -= 4) {
        unsigned char nibble = (address >> shift) & 0xF;
        if (nibble != 0 || started) {
            buffer[pos++] = hex_digits[nibble];
            started = 1;
        }
    }
    
    if (!started) {
        buffer[pos++] = '0';
    }
    
    // Null-terminate and print
    buffer[pos] = '\0';
    write(1, buffer, pos);
}
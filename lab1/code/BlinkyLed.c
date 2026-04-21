int main() {
    int i;                  // counter for get ready delay
    unsigned long int j;    // counter for blinky delay

    i = 0;
    j = 0;

    // Enable clock for GPIOG, GPIOH, GPIOI
    *(unsigned long*)(0x40023830) |= 0x40 | 0x80 | 0x100;

    for (i = 0; i < 4; i++) {}

    // PG6
    *(unsigned long*)(0x40021800) =
        ((*(unsigned long*)(0x40021800) & (~0x00002000)) | (0x00001000));

    // PG7
    *(unsigned long*)(0x40021800) =
        ((*(unsigned long*)(0x40021800) & (~0x00008000)) | (0x00004000));

    // PG8
    *(unsigned long*)(0x40021800) =
        ((*(unsigned long*)(0x40021800) & (~0x00020000)) | (0x00010000));

    // PH2
    *(unsigned long*)(0x40021C00) =
        ((*(unsigned long*)(0x40021C00) & (~0x00000020)) | (0x00000010));

    // PH3
    *(unsigned long*)(0x40021C00) =
        ((*(unsigned long*)(0x40021C00) & (~0x00000080)) | (0x00000040));

    // PH6
    *(unsigned long*)(0x40021C00) =
        ((*(unsigned long*)(0x40021C00) & (~0x00002000)) | (0x00001000));

    // PH7
    *(unsigned long*)(0x40021C00) =
        ((*(unsigned long*)(0x40021C00) & (~0x00008000)) | (0x00004000));

    // PI10
    *(unsigned long*)(0x40022000) =
        ((*(unsigned long*)(0x40022000) & (~0x00200000)) | (0x00100000));

    while (1) {

        // 1100000 -> PG6, PG7
        *(unsigned long*)(0x40021814) |= 0x40;
        *(unsigned long*)(0x40021814) |= 0x80;
        for (j = 0; j < 2000000; j++) {}
        *(unsigned long*)(0x40021814) &= ~0x40;
        *(unsigned long*)(0x40021814) &= ~0x80;
        for (j = 0; j < 2000000; j++) {}

        // 0011000 -> PG8, PH2
        *(unsigned long*)(0x40021814) |= 0x100;
        *(unsigned long*)(0x40021C14) |= 0x4;
        for (j = 0; j < 2000000; j++) {}
        *(unsigned long*)(0x40021814) &= ~0x100;
        *(unsigned long*)(0x40021C14) &= ~0x4;
        for (j = 0; j < 2000000; j++) {}

        // 0000110 -> PH3, PH6
        *(unsigned long*)(0x40021C14) |= 0x8;
        *(unsigned long*)(0x40021C14) |= 0x40;
        for (j = 0; j < 2000000; j++) {}
        *(unsigned long*)(0x40021C14) &= ~0x8;
        *(unsigned long*)(0x40021C14) &= ~0x40;
        for (j = 0; j < 2000000; j++) {}

        // 0000001 -> PH7, PI10
        *(unsigned long*)(0x40021C14) |= 0x80;
        *(unsigned long*)(0x40022014) |= 0x400;
        for (j = 0; j < 2000000; j++) {}
        *(unsigned long*)(0x40021C14) &= ~0x80;
        *(unsigned long*)(0x40022014) &= ~0x400;
        for (j = 0; j < 2000000; j++) {}
    }
}
//==============================================================
//              4-BIT LCD INTERFACING WITH PIC18F4580
//==============================================================
//
// LCD is connected in 4-bit mode.
//
// PIC18F4580                16x2 LCD
// ---------                 --------
// RD4  -------------------> D4
// RD5  -------------------> D5
// RD6  -------------------> D6
// RD7  -------------------> D7
//
// RC0  -------------------> RS
// RC1  -------------------> E
//
// RW of LCD is connected to GND
// because we are only performing WRITE operations.
//
//==============================================================

#include <p18f4580.h>


//==============================================================
// LCD CONTROL PIN DEFINITIONS
//==============================================================

// RS = Register Select
// RS = 0 --> Command mode
// RS = 1 --> Data mode
#define RS PORTCbits.RC0

// E = Enable pin
// A HIGH-to-LOW transition on E tells the LCD to read
// the data/command present on D4-D7.
#define E PORTCbits.RC1


//==============================================================
// FUNCTION PROTOTYPES
//==============================================================

void Delay(int);
void Lcd_Cmd(char);
void Lcd_Data(char);
void Lcd_String(const rom char*);
void Lcd_Inti();


//==============================================================
//                       MAIN FUNCTION
//==============================================================

void main()
{
    //----------------------------------------------------------
    // PORT CONFIGURATION
    //----------------------------------------------------------

    // Make PORTD pins RD0-RD7 as OUTPUT.
    // We are using the upper four pins RD4-RD7 for LCD data.
    TRISD = 0x00;

    // RC0 --> RS pin of LCD
    // Configure RC0 as OUTPUT.
    TRISCbits.RC0 = 0;

    // RC1 --> E pin of LCD
    // Configure RC1 as OUTPUT.
    TRISCbits.RC1 = 0;


    //----------------------------------------------------------
    // LCD INITIALIZATION
    //----------------------------------------------------------

    // Initialize LCD in 4-bit mode.
    Lcd_Inti();


    //----------------------------------------------------------
    // INFINITE LOOP
    //----------------------------------------------------------

    // Microcontroller programs normally keep running continuously.
    // Therefore, while(1) creates an infinite loop.
    while(1)
    {
        // Send a string to LCD.
        Lcd_String("Welcome:");

        // Clear the LCD screen.
        Lcd_Cmd(0x01);
    }
}


//==============================================================
//                 LCD INITIALIZATION FUNCTION
//==============================================================

void Lcd_Inti()
{
    //----------------------------------------------------------
    // LCD INITIALIZATION COMMANDS
    //----------------------------------------------------------

    // 0x02 --> Initialize LCD in 4-bit mode.
    Lcd_Cmd(0x02);

    // 0x0E --> Display ON, Cursor ON, Cursor Blink OFF.
    // 0x0F --> Display ON, Cursor ON, Cursor Blink ON.
    Lcd_Cmd(0x0E);

    // 0x01 --> Clear the LCD screen.
    Lcd_Cmd(0x01);

    // 0x06 --> Increment cursor position after every character.
    //          Display does not shift.
    Lcd_Cmd(0x06);

    // 0x28 --> 4-bit mode, 2 lines, 5x8 character font.
    // 0x38 --> 8-bit mode, 2 lines, 5x8 character font.
    Lcd_Cmd(0x28);

    // 0x80 --> Move cursor to first row, first column.
    Lcd_Cmd(0x80);
}


//==============================================================
//                  LCD STRING FUNCTION
//==============================================================
//
// This function sends a complete string to the LCD.
//
// Example:
//     Lcd_String("Welcome");
//
// The string is stored in ROM/Program Memory.
// 'str' points to the first character of the string.
//
//==============================================================

void Lcd_String(const rom char* str)
{
    // Continue until NULL character '\0' is found.
    //
    // Every C string automatically ends with '\0'.
    while(*str != '\0')
    {
        // Send one character to LCD.
        Lcd_Data(*str);

        // Move pointer to the next character.
        str++;
    }
}

//==============================================================
//                       DELAY FUNCTION
//==============================================================
//
// Generates an approximate software delay.
//
// The delay depends on the PIC clock frequency and compiler.
//
//==============================================================

void Delay(int a)
{
    int i, j;

    for(i = 0; i < a; i++)
    {
        for(j = 0; j < a; j++);
    }
}


//==============================================================
//                   LCD COMMAND FUNCTION
//==============================================================
//
// This function sends a COMMAND to the LCD.
//
// Example commands:
//
// 0x01 --> Clear display
// 0x02 --> 4-bit mode
// 0x06 --> Increment cursor
// 0x0E --> Display ON, cursor ON
// 0x28 --> 4-bit, 2-line mode
// 0x80 --> First row, first column
//
// In 4-bit mode, an 8-bit command is divided into:
//
//             HIGH NIBBLE + LOW NIBBLE
//
// Example:
//     0x28 = 0010 1000
//            ---- ----
//            High Low
//
//==============================================================

void Lcd_Cmd(char ch)
{
    char temp;


    //----------------------------------------------------------
    // SEND HIGH NIBBLE
    //----------------------------------------------------------

    // Extract upper 4 bits.
    //
    // Example:
    // ch = 0x28 = 0010 1000
    //
    // ch & 0xF0
    //      1111 0000
    //      --------
    //      0010 0000
    //
    // Result = 0x20
    temp = (ch & 0xF0);

    // Send the high nibble to PORTD.
    // Since LCD is connected to RD4-RD7,
    // the upper four bits of PORTD are used.
    PORTD = temp;

    // RS = 0 means COMMAND mode.
    RS = 0;

    // RW = 0 means WRITE operation.
    // RW is assumed to be permanently connected to GND,
    // so no software control is required.

    // Enable LCD to read the command.
    E = 1;

    // Small delay to allow LCD to process the signal.
    Delay(100);

    // Disable LCD enable signal.
    E = 0;


    //----------------------------------------------------------
    // SEND LOW NIBBLE
    //----------------------------------------------------------

    // Extract lower 4 bits.
    //
    // Example:
    // ch = 0x28 = 0010 1000
    //
    // ch & 0x0F
    //      0000 1111
    //      --------
    //      0000 1000
    //
    // Result = 0x08
    //
    // Shift left by 4 positions because LCD is connected
    // to RD4-RD7.
    //
    // 0000 1000 << 4
    // =0010 0000
    temp = ((ch & 0x0F) << 4);

    // Send the low nibble through RD4-RD7.
    PORTD = temp;

    // Enable LCD to read the lower nibble.
    E = 1;

    Delay(100);

    // Finish the write operation.
    E = 0;
}


//==============================================================
//                    LCD DATA FUNCTION
//==============================================================
//
// This function sends one CHARACTER to the LCD.
//
// Example:
//
//     Lcd_Data('A');
//
// Since LCD is working in 4-bit mode, one character is
// divided into two parts:
//
//     HIGH NIBBLE --> sent first
//     LOW NIBBLE  --> sent second
//
//==============================================================

void Lcd_Data(char dt)
{
    char temp;


    //----------------------------------------------------------
    // SEND HIGH NIBBLE
    //----------------------------------------------------------

    // Extract upper 4 bits of character.
    //
    // Example:
    // 'A' = 0x41 = 0100 0001
    //
    // High nibble = 0100
    //
    // After masking:
    // 0100 0001
    // 1111 0000
    // ---------
    // 0100 0000
    temp = (dt & 0xF0);

    // Send high nibble to LCD through RD4-RD7.
    PORTD = temp;

    // RS = 1 means DATA mode.
    // LCD understands that the value is a character
    // to be displayed.
    RS = 1;

    // RW = 0 means WRITE operation.
    // RW is connected to GND.

    // Enable LCD to read the high nibble.
    E = 1;

    Delay(100);

    // Disable Enable signal.
    E = 0;


    //----------------------------------------------------------
    // SEND LOW NIBBLE
    //----------------------------------------------------------

    // Extract lower 4 bits.
    //
    // Example:
    // 'A' = 0100 0001
    //
    // dt & 0x0F
    //
    // 0100 0001
    // 0000 1111
    // ---------
    // 0000 0001
    //
    // Shift left by 4 because LCD data pins are RD4-RD7.
    temp = ((dt & 0x0F) << 4);

    // Send low nibble to LCD.
    PORTD = temp;

    // RS remains 1 because this is still DATA mode.
    //
    // RS = 1 tells LCD:
    // "The value on D4-D7 is character data."
    
    // Enable LCD to read the low nibble.
    E = 1;

    Delay(100);

    // Finish the write operation.
    E = 0;
} 

/* END */
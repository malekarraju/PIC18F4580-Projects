#include <p18f4580.h>

// LCD control pins
// RC0 -> RS (Register Select)
// RC1 -> EN (Enable)
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1


// Function declarations
void cmd(char);          // Send command to LCD
void dat(char);          // Send character/data to LCD
void delay(int);         // Generate delay
void lcd_init(void);     // Initialize LCD


// ----------------------------------------------------
// DELAY FUNCTION
// ----------------------------------------------------
void delay(int a)
{
    int i, j;

    // Outer loop controls the approximate delay time
    for(i = 0; i < a; i++)

        // Inner loop creates the actual time delay
        for(j = 0; j < 233; j++);
}


// ----------------------------------------------------
// MAIN FUNCTION
// ----------------------------------------------------
void main(void)
{
    // Make all PORTA pins digital
    // This is important because some PIC pins are
    // analog by default.
    ADCON1 = 0x0F;


    // PORTC -> OUTPUT
    // RC0 = RS
    // RC1 = EN
    TRISC = 0x00;


    // PORTD -> OUTPUT
    // PORTD is connected to LCD data pins
    TRISD = 0x00;


    // PORTB direction:
    //
    // 0xF0 = 1111 0000
    //
    // RB7-RB4 = INPUT  -> keypad ROWS
    // RB3-RB0 = OUTPUT -> keypad COLUMNS
    //
    TRISB = 0xF0;


    // Initialize the LCD
    lcd_init();


    // ------------------------------------------------
    // INFINITE LOOP
    // ------------------------------------------------
    while(1)
    {

        // =================================================
        // COLUMN 1 SCAN
        // =================================================
        //
        // 0xFE = 1111 1110
        //
        // RB0 = 0  -> Column 1 LOW
        // RB1 = 1
        // RB2 = 1
        // RB3 = 1
        //
        // RB4-RB7 are inputs.
        //
        // Now PIC checks which ROW becomes LOW
        // when a key is pressed.
        //
        PORTB = 0xFE;


        // If R1-C1 key is pressed:
        // RB0 LOW travels through the pressed key
        // to RB4.
        //
        // PORTB becomes:
        // 1110 1110 = 0xEE
        //
        // Therefore key = 7
        if(PORTB == 0xEE)
        {
            dat('7');       // Display 7 on LCD
            while(PORTB == 0xEE);
        }

        // R2-C1 -> key 8
        // PORTB = 1101 1110 = 0xDE
        if(PORTB == 0xDE)
        {
            dat('8');          
            while(PORTB == 0xDE);
        }

        // R3-C1 -> key 9
        // PORTB = 1011 1110 = 0xBE
        if(PORTB == 0xBE)
        {
			while(PORTB == 0XBE);
            dat('9');
        }

        // R4-C1 -> key /
        // PORTB = 0111 1110 = 0x7E
        if(PORTB == 0x7E)
        {
            dat('/');
            while(PORTB == 0x7E);
        }



        // =================================================
        // COLUMN 2 SCAN
        // =================================================
        //
        // 0xFD = 1111 1101
        //
        // RB1 = 0 -> Column 2 LOW
        //
        PORTB = 0xFD;

        // R1-C2 -> key 4
        // 1110 1101 = 0xED
        if(PORTB == 0xED)
        {
            dat('4');
            while(PORTB == 0XED);
        }


        // R2-C2 -> key 5
        // 1101 1101 = 0xDD
        if(PORTB == 0xDD)
        {
            dat('5');
			while(PORTB == 0XDD);
        }


        // R3-C2 -> key 6
        // 1011 1101 = 0xBD
        if(PORTB == 0xBD)
        {
            dat('6');
            while(PORTB == 0XBD);
        }


        // R4-C2 -> key *
        // 0111 1101 = 0x7D
        if(PORTB == 0x7D)
        {
            dat('*');
			while(PORTB == 0X7D);
        }



        // =================================================
        // COLUMN 3 SCAN
        // =================================================
        //
        // 0xFB = 1111 1011
        //
        // RB2 = 0 -> Column 3 LOW
        //
        PORTB = 0xFB;


        // R1-C3 -> key 1
        // 1110 1011 = 0xEB
        if(PORTB == 0xEB)
        {
            dat('1');
            delay(100);
            cmd(0x01);
        }


        // R2-C3 -> key 2
        // 1101 1011 = 0xDB
        if(PORTB == 0xDB)
        {
            dat('2');
            delay(100);
            cmd(0x01);
        }


        // R3-C3 -> key 3
        // 1011 1011 = 0xBB
        if(PORTB == 0xBB)
        {
            dat('3');
            delay(100);
            cmd(0x01);
        }


        // R4-C3 -> key -
        // 0111 1011 = 0x7B
        if(PORTB == 0x7B)
        {
            dat('-');
            delay(100);
            cmd(0x01);
        }



        // =================================================
        // COLUMN 4 SCAN
        // =================================================
        //
        // 0xF7 = 1111 0111
        //
        // RB3 = 0 -> Column 4 LOW
        //
        PORTB = 0xF7;


        // R1-C4 -> key C
        // 1110 0111 = 0xE7
        if(PORTB == 0xE7)
        {
            dat('C');
            delay(100);
            cmd(0x01);
        }


        // R2-C4 -> key 0
        // 1011 0111 = 0xB7
        if(PORTB == 0xB7)
        {
            dat('0');
            delay(100);
            cmd(0x01);
        }


        // R3-C4 -> key =
        // 1101 0111 = 0xD7
        if(PORTB == 0xD7)
        {
            dat('=');
            delay(100);
            cmd(0x01);
        }


        // R4-C4 -> key +
        // 0111 0111 = 0x77
        if(PORTB == 0x77)
        {
            dat('+');
            delay(100);
            cmd(0x01);
        }
    }
}



// ====================================================
// LCD COMMAND FUNCTION
// ====================================================
//
// Used when we want to send a COMMAND to LCD.
//
// Example:
// cmd(0x01) -> Clear LCD
// cmd(0x80) -> Move cursor to first position
//
void cmd(char a)
{
    // Put command on LCD data pins
    PORTD = a;


    // RS = 0 means COMMAND
    RS = 0;


    // Enable LCD
    EN = 1;

    delay(10);

    // Disable LCD
    EN = 0;
}



// ====================================================
// LCD DATA FUNCTION
// ====================================================
//
// Used when we want to send a CHARACTER to LCD.
//
// Example:
// dat('7') -> Display 7
// dat('A') -> Display A
//
void dat(char b)
{
    // Put character/data on LCD data pins
    PORTD = b;


    // RS = 1 means DATA/CHARACTER
    RS = 1;


    // Enable LCD
    EN = 1;

    delay(10);

    // Disable LCD
    EN = 0;
}



// ====================================================
// LCD INITIALIZATION FUNCTION
// ====================================================
void lcd_init(void)
{
    // 8-bit mode
    // 2-line LCD
    // 5x7 character font
    cmd(0x38);
    delay(10);


    // Display ON
    // Cursor ON
    cmd(0x0E);
    delay(10);


    // Clear LCD
    cmd(0x01);
    delay(10);


    // Move cursor to first position
    cmd(0x80);
    delay(10);


    // Entry mode
    // Cursor moves to right after displaying data
    cmd(0x06);
    delay(10);
}
/*
This is an implementation of a Event Driven Finite State Machine.

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2023 Fernando Magro and other contributors.

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>

/*===========================================================================*/
// STATE DRIVEN FINITE STATE MACHINE EXAMPLE

#define EVENT    4
#define STATE    3

void Neutral (void);
void Forward (void);
void Reverse (void);
void Not_Valid (void);
void QuitProgram (void);

enum {
    NEUTRAL,
    FORWARD,
    REVERSE
}; // all the valid states

enum {
    NEUTRAL_BTN,
    REVERSE_BTN,
    FORWARD_BTN,
    QUIT_BTN
}; // all the possible events

unsigned char currentState = NEUTRAL; // set the initial state.


/*===========================================================================*/
void (* State_Event_Matrix[EVENT][STATE]) () =
{
    {   // Event Neutral_btn
        Not_Valid,      // callback function called when Neutral_btn clicked at NEUTRAL STATE
        Neutral,        // callback function called when Neutral_btn clicked at FORWARD STATE
        Neutral,        // callback function called when Neutral_btn clicked at REVERSE STATE
    },
    {   // Event Reverse_btn
        Reverse,        // State NEUTRAL
        Not_Valid,      // State FORWARD
        Not_Valid,      // State REVERSE
    },
    {   // Event Forward_btn
        Forward,        // State NEUTRAL
        Not_Valid,      // State FORWARD
        Not_Valid,      // State REVERSE
    },
    {   // Event Quit_btn
        QuitProgram,        // State NEUTRAL
        Not_Valid,        // State FORWARD
        Not_Valid,          // State REVERSE
    }
};

/*===========================================================================*/
void Not_Valid (void)
{
    printf("\nNot valid, state unchanged!!!\n");
}

/*===========================================================================*/
void Neutral(void)
{
    printf("\nState changed to NEUTRAL!!!\n");
    currentState = NEUTRAL;
}

/*===========================================================================*/
void Forward(void)
{
    printf("\nState changed to FORWARD!!!\n");
    currentState = FORWARD;
}

/*===========================================================================*/
void Reverse(void)
{
    printf("\nState changed to REVERSE!!!\n");
    currentState = REVERSE;
}

/*===========================================================================*/
void QuitProgram (void) {
    printf("\n\nThe State Event Machine is stoped by user!!!!\n\n");
    exit(0);

}

/*===========================================================================*/
int main (int argc, char *argv[])
{
    //int quit = 0, c;
    int c;
    printf("\n-----------------------------------------\n");
    printf("- State Event Machine Test              -\n");
    printf("- 'n' --> Change state to NEUTRAL       -\n");
    printf("- 'f' --> Change state to FORWARD       -\n");
    printf("- 'r' --> Change state to REVERSE       -\n");
    printf("- 'q' --> Quit                          -\n");
    printf("-----------------------------------------\n");
    // Always start the machine in Neutral state
    Neutral();
    while (1)
    {
        c = getchar();

        switch(c)
        {
        case 'n':
            State_Event_Matrix[NEUTRAL_BTN][currentState]();
            break;
        case 'f':
            State_Event_Matrix[FORWARD_BTN][currentState]();
            break;
        case 'r':
            State_Event_Matrix[REVERSE_BTN][currentState]();
            break;
        case 'q':
            State_Event_Matrix[QUIT_BTN][currentState]();
            break;
        }
    }

}
/*===================== T h e  e n d ========================================*/

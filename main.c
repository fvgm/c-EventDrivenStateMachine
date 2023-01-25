#include <stdio.h>
#include <stdlib.h>

/*===========================================================================*/
// STATE EVENT MACHINE EXAMPLE

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
};

enum {
    NEUTRAL_BTN,
    REVERSE_BTN,
    FORWARD_BTN,
    QUIT_BTN
};

unsigned char currentState = NEUTRAL;


/*===========================================================================*/
void (* State_Event_Matrix[EVENT][STATE]) () =
{
    {   // Event Neutral_btn
        Not_Valid,      // State NEUTRAL
        Neutral,        // State FORWARD
        Neutral,        // State REVERSE
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

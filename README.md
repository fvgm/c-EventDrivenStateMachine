# c-EventDrivenStateMachine
A Event-Driven Finite State Machine written in C for Embedded Systems.  
In the programming field, a event-driven state machine is charecterized if the transitions from one state to another is triggered by an event or a message.  
This example is written in standard C language, where a car transmission system can be in one of the following states:  
* Forward
* Neutral
* Reverse
But, we can't go to Reverse gear directly from Forward and vice-versa; we need to pass thru Neutral before. Also, in this simple example, we can turn off the engine (i.e. quit the program) only at the Neutral state.



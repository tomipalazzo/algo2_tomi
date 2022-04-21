#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "student.h"

stack_t *stack;

int main()
{
    stack = createStack(100);

    student_t stud1 = {
        .name = "Steve Balmer",
        .dni = 12345678,
        .califications = {3,2,1},
        .concept = -2,
    };

    studentp_t stud2 = {
        .name = "Linus Torvalds",
        .dni = 23456789,
        .califications = {9,7,8},
        .concept = 1,
    };


    uint32_t *studp;

    // Hint: ver 'createFrame'

    // Push student stud2
    stack->createFrame(stack);
    Union64 studentDir;

    studentp_t * punteroStud2 = &stud2;
        
    studentDir.r = punteroStud2;
    
    stack->push(stack, studentDir.e.low);
    stack->push(stack, studentDir.e.high);



    // Push random value
    uint32_t value = 42;
    stack->push(stack,value);
    value = stack->pop(stack);
    printf("Valor: %i \n", value);



    // Push student stud1
    stack->createFrame(stack);

          
    student_t * punteroStud1 = &stud1;
    
    studentDir.r = punteroStud1;
    
    stack->push(stack, studentDir.e.low);
    stack->push(stack, studentDir.e.high);

    // Print student st1 y st2

    void (*prStudpt)() = printStudent;
    myCall(stack, prStudpt);

    // A qué apunta el esp???


    prStudpt = printStudentp;
    myCall(stack, prStudpt);


    //free(punteroStud1);
    //free(punteroStud2);
    free(stack->_stackMem);
    free(stack); // Alcanza?

    return 0;
}

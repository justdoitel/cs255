//THIS CODE WAS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING ANY
//SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR - El YIRDAW

.global main
.data
    .align 2
    n: .word 13
    ans: .skip 4

.text
main:
    movw r0,#:lower16:n
    movt r0,#:upper16:n
    ldr r0,[r0] //r0 is now n
    push {r0} @passing n as a parameter to fib
    bl fib
    add sp,#4 //pop the parameter of fib
    movw r0,#:lower16:ans
    movt r0,#:upper16:ans
    str r5,[r0] @have a contract with fib to have the answer back in r5
    b End 


@a would be [fp,#8]
@x would be [fp,#-4]
@y would be [fp,#-8]
@returns the answer on r5
fib:
    push {lr}
    push {fp}
    mov fp,sp
    sub sp,#8 //free memory for x and y

    ldr r0,[fp,#8] //r0=a
    cmp r0,#0 
    beq return //we're done if a==0

    ldr r0,[fp,#8] //r0=a
    cmp r0,#1
    beq return //we're done if a==1

    ldr r0,[fp,#8] //r0=a
    sub r0,#1 //r0=a-1
    push {r0}
    bl fib
    add sp,#4 //free the memory for the parameter
    str r5,[fp,#-4] //x=fib(a-1)

    ldr r0,[fp,#8] //r0=a
    sub r0,#2 //r0=a-2
    push {r0}
    bl fib
    add sp,#4 //free the memory for the parameter
    str r5,[fp,#-8] //y=fib(a-2)

    ldr r0,[fp,#-4] //r0=x
    ldr r1,[fp,#-8] //r1=y
    add r5,r0,r1 //r5=r0+r1

    add sp,#8 //free the memory of x and y
    pop {fp}
    pop {lr}
    bx lr

return:
    mov r5,#1
    add sp,#8 //free the memory of x and y
    pop {fp}
    pop {lr}
    bx lr

End:
    nop
    
//THIS CODE WAS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING ANY
//SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW

.global main

.data
    .align 2
    ans: .skip 4


.text
main:
    mov r0, #70
    mov r1, #20
    push {r0} @to pass as parameter a to gcd
    push {r1} @to pass as parameter b to gcd
    bl gcd

    add sp, #8 @pop the parameters of gcd
    movw r0,#:lower16:ans
    movt r0,#:upper16:ans
    str r5,[r0] @have a contract with gcd to have the answer back in r5
    b End

@b would be [fp,#8]
@a would be [fp,#12]
@r would be [fp,#-4]
@returns the answer on r5
gcd: 
    push {lr}
    push {fp}
    mov fp,sp

    ldr r0, [fp,#8] @r0 is now b
    cmp r0,#0
    beq done @if b==0, we are done

    ldr r1, [fp,#12] @r1 is now a
    push {r1} @to pass as a for rem
    push {r0} @to pass as b for rem
    bl rem
    add sp, #8 @popping rem's parameters

    ldr r0, [fp,#8]
    push {r0} @to pass current b as a for the next gcd call
    push {r6} @to pass the remainder (since we have a contract with rem to return on r6) as b for the next gcd call
    bl gcd
    add sp, #8

    pop {fp}
    pop {lr}
    bx lr

@b would be [fp,#8]
@a would be [fp,#12]
@q would be [fp,#-4]
@r would be [fp,#-8]
@returns the answer on r6
rem:
    push {lr}
    push {fp}  
    mov fp,sp

    mov r0,#0
    push {r0} @int q=0
    ldr r0, [fp,#12]
    push {r0} @int r=a

    
while:
    ldr r0, [fp,#-8] @r0 is r
    ldr r1, [fp,#8] @r1 is b
    cmp r0,r1
    blt rest @at this point, we're done with rem
    ldr r0, [fp,#-4] @r0 is q
    add r0, #1
    str r0, [fp,#-4] @q++
    ldr r0, [fp,#-8] 
    sub r0, r1 @r0=r-b
    str r0, [fp,#-8] @r=r0(r-b)
    b while

    

rest:
    add sp, #8 @popping the numbers pushed by rem
    ldr r6,[fp,#-8] @storing the return of rem in r6
    pop {fp}
    pop {lr}
    bx lr


done:
    ldr r5, [fp,#12] @store result in r5
    pop {fp}
    pop {lr}
    bx lr


End:
    nop


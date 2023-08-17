//THIS CODE WAS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING ANY
//SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW 

.global main

.data
    .align 2
    a: .word 1273
    q: .skip 4
    r: .skip 4
    b: .short 29
    ans: .skip 2

.text    
main:
    movw r0, #:lower16:q
    movt r0, #:upper16:q @r0 now contains address of q
    mov r1,#0
    str r1,[r0] @0 is stored in q
    movw r1,#:lower16:r
    movt r1,#:upper16:r @r1 contains address of r
    movw r2,#:lower16:a
    movt r2,#:upper16:a
    ldr r2,[r2] @r2 now has the value of a (in this case 86)
    str r2,[r1] @the value of a (in this case 86) is stored in r
    movw r2,#:lower16:b
    movt r2,#:upper16:b @r2 contains address of b

while:
    ldrsh r3,[r2] @r3 would have the value of b
    ldr r4,[r1] @r4 would have the value of r
    cmp r4,r3 @to flag the cpsr with r-b
    blt therest @if r-b is less than 0, the program can leave the while loop

    ldr r5, [r0] @r5 holds the value of q
    add r5, #1 @q+1 is stored in r5
    str r5,[r0] @q is changed to q+1 (the value in r5)
    sub r5,r4,r3 @r-b is stored in r5
    str r5,[r1] @r5 (which is r-b) is stored into r
    b while @since our check is at the beginning of the while loop, we just unconditionally go back

therest:
    ldr r5, [r0] @loads the value of q to r5
    movw r6, #:lower16:ans
    movt r6, #:upper16:ans 
    strh r5, [r6] @stores the value at r5 (q) to ans

additionally:
    movw r0, #:lower16:q
    movt r0, #:upper16:q
    ldr r0,[r0]
    movw r1, #:lower16:r
    movt r1, #:upper16:r
    ldr r1,[r1] 

End:
    nop


//THIS CODE WAS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING ANY
//SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW

.global main
.data
    .align 2
    n: .word 14 
    sum: .skip 2 //signed halfword
    i: .byte 69 //signed byte (distraction value -- it doesn't matter since it'd be reset)


.text
main:
    movw r0, #:lower16:n
    movt r0, #:upper16:n @r0 now contains address of n
    movw r1, #:lower16:sum
    movt r1, #:upper16:sum @r1 now contains address of sum
    movw r2, #:lower16:i
    movt r2, #:upper16:i @r2 now contains address of i
    mov r3, #0
    strb r3,[r2]//i=0

for:
    ldrsb r3,[r2] //r3=i
    ldr r4,[r0] //r4=n
    cmp r3,r4
    bge End //breaks if i!<n

    ldrsb r3,[r2] //r3=i
    ldrsb r4,[r2] //r4=i
    mul r5, r3, r4 //r5=i*i
    mul r3, r5, r4 //r3=i*i*i
    ldrsh r4,[r1] //r4=sum
    add r4,r3 //r4=sum+r3(which is i^3)
    strh r4,[r1] //sum=r4 (which is sum+i^3)
    
    ldrsb r3,[r2] //r3=i
    add r3,#1
    strb r3,[r2] //i++
    b for
End:
    nop



//THIS CODE WAS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING ANY
//SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. El YIRDAW

.global main
.data
    .align 2
    arr: .word 4,2,9,12,15,11,5,1,-15,-2
    len: .word 8
    i: .word 2
    sum: .word -4
    
.text
main:
    movw r0, #:lower16:len
    movt r0, #:upper16:len 
    ldr r0,[r0] //r0 is now len
    movw r1, #:lower16:arr
    movt r1, #:upper16:arr //r1 now has address of arr
    movw r2, #:lower16:i
    movt r2, #:upper16:i //r2 now has address of i
    movw r3, #:lower16:sum
    movt r3, #:upper16:sum //r3 now has address of sum
    mov r8, #4 //r8 would be 4 so that we can use it to find the address of a specific index of an array

while:
    ldr r4,[r2] //r4 = i
    cmp r4,r0 //i-len (with the cpsr marked)
    bge End

    mul r7, r4, r8 //r7 would now be the offset to get to arr[i]
    ldr r5,[r1,r7] //r5=arr[i]

    ldr r6,[r3] //r6=sum
    add r6,r5 //r6=sum+arr[i]
    str r6,[r3] //sum=sum+arr[i]
    add r4,#1 //r4=i+1
    str r4,[r2] //i=i+1
    b while

End:
    nop

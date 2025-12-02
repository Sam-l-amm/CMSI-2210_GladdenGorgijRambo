section .data
    test_byte db 0xAE
    
    fmt db 'Byte: 0x%02X -> Odd parity bit: %d', 0xA, 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp
    sub rsp, 32       
    
    mov al, [rel test_byte] 
    
    test al, al          
    setp al              
    xor al, 1         
    
    movzx edx, al   
    movzx ecx, byte [rel test_byte] 


    lea rcx, [rel fmt] 

    mov edx, ecx        
    mov r8d, edx        
    

    movzx eax, byte [rel test_byte]  
    movzx ebx, byte [rel test_byte]
    test bl, bl
    setp bl
    xor bl, 1
    

    lea rcx, [rel fmt]  
    movzx edx, al        
    movzx r8d, bl        

   call printf
    
    xor eax, eax     
    add rsp, 32
    pop rbp
    ret
BITS 16
org 0x7c00

start:
    ; Clear the screen
    mov ax, 0x03
    int 0x10

    ; Set video mode
    mov ax, 0x03
    int 0x10

    ; Set cursor position
    mov ah, 0x02
    mov bh, 0x00
    mov dh, 0x00  ; Row (Y)
    mov dl, 0x00  ; Column (X)
    int 0x10

    ; Display boot screen message
    call display_boot_screen

    ; Wait for a key press
    call wait_for_keypress

    ; Load the kernel
    mov bx, 0x9000
    mov es, bx
    mov ah, 0x02
    mov al, 0x01
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    mov dl, 0x80
    int 0x13

    ; Jump to kernel
    jmp 0x9000:0x0000

display_boot_screen:
    ; Display boot screen (example ASCII art)
    mov si, boot_screen_message
    call print_string
    ret

print_string:
    mov ah, 0x0E
.next_char:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .next_char
.done:
    ret

wait_for_keypress:
    mov ah, 0x00
    int 0x16
    ret

boot_screen_message db '====================================', 0x0D, 0x0A
                     db '           Welcome to SnaOS           ', 0x0D, 0x0A
                     db '====================================', 0x0D, 0x0A
                     db '        Press any key to continue...  ', 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0xAA55

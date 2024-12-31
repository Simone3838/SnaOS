; boot.asm
SECTION .text
BITS 16

start:
    cli                     ; Clear interrupts
    mov ax, 0x07C0          ; Set up 4K stack space after this bootloader
    add ax, 288             ; (4096 + 512) / 16 bytes per paragraph
    mov ss, ax
    mov sp, 4096

    mov ax, 0x07C0          ; Set data segment to where we're loaded
    mov ds, ax

    mov si, welcome_msg     ; Point to the welcome message
    call print_string       ; Print the welcome message

    jmp $                   ; Hang

print_string:
    mov ah, 0x0E            ; BIOS teletype function
.repeat:
    lodsb                   ; Load byte from string
    cmp al, 0
    je .done
    int 0x10                ; Print char
    jmp .repeat
.done:
    ret

welcome_msg db 'Hello, SnaOS!', 0

times 510-($-$$) db 0       ; Pad the rest of the boot sector with zeros
dw 0xAA55                   ; Boot signature

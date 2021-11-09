# AARONNNNNNNNNN
# arjun

# SYS_READ = 0
# SYS_WRITE = 1
# SYS_OPEN = 2
# SYS_BRK = 12
# SYS_EXIT = 60

# O_RDONLY = 0


.section .text
.global _start

_start:

# Get value of break
xor %rdi, %rdi
xor %rax, %rax
add $12, %al
syscall

# Increment break
xor %rdi, %rdi
add %rax, %rdi
add $9, %dil
xor %rax, %rax
add $12, %al
syscall

# Get filename
xor %rdi, %rdi
xor %rsi, %rsi
add %rax, %rsi
sub $9, %sil
xor %rdx, %rdx
add $9, %rdx
xor %rax, %rax
syscall

# Get value of break
xor %rdi, %rdi
xor %rax, %rax
add $12, %al
syscall

# Open the file
xor %rdi, %rdi
add %rax, %rdi
sub $9, %dil
xor %rsi, %rsi
xor %rax, %rax
add $2, %al
syscall

# Get value of break
xor %rdi, %rdi
xor %rax, %rax
add $12, %al
syscall

# Increment break
xor %rdi, %rdi
add %rax, %rdi
add $100, %dil
xor %rax, %rax
add $12, %al
syscall

# Read 100 bytes from file
xor %rdi, %rdi
add $3, %dil
xor %rsi, %rsi
add %rax, %rsi
sub $100, %sil
xor %rdx, %rdx
add $100, %dl
xor %rax, %rax
syscall

# Get value of break
xor %rdi, %rdi
xor %rax, %rax
add $12, %al
syscall

# Write contents of file
xor %rdi, %rdi
inc %rdi
xor %rsi, %rsi
add %rax, %rsi
sub $100, %sil
xor %rdx, %rdx
add $100, %dl
xor %rax, %rax
inc %rax
syscall

# Exit
xor %rdi, %rdi
xor %rax, %rax
add $60, %al
syscall

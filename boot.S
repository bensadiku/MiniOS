#first set magic number of multiboot
.set MAGIC, 0x1BADB002
#set flags
.set FLAGS, 0
#set checksum
.set CHECKSUM, -(MAGIC + FLAGS)

#we dont need other fields

#set multiboot seection
.section .multiboot

#set types for MAGIC, FLAGS etc
.long MAGIC
.long FLAGS
.long CHECKSUM


#stack for the kernel funcs
#stack grows from higher memory to lower
#first define the stack bottom 
stackBottom:



#e.g 512 stack size
#skip those
.skip 512

#set stack top
stackTop:

#set sections
.section .text
.global _start 
.type _start, @function

#starting point

_start:
	#get the current stack pointer from esp
	mov $stackTop, %esp
	# call the main kernel func
	call KERNEL_MAIN

	#clear the interrupts
	cli

#put system in infinite loop
hltLoop:
	hlt
	jmp hltLoop

.size _start, . - _start
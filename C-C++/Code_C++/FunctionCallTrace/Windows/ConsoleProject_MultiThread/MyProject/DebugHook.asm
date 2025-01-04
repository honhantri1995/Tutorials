
; To compile assemply with VS, righ click Project > Build Dependencies > Build Customizations... > select masm.
; External function used to Find out the name of th function given its address
extrn FindSymbol_enter:Proc
extrn FindSymbol_exit:Proc

.code
;--------------------------------------------------------------------
; _penter procedure
;--------------------------------------------------------------------

_penter proc

	; Store the volatile registers
	push r11
	push r10
	push r9
	push r8
	push rax
	push rdx
	push rcx

	; Reserve space for 4 registers [ rcx,rdx,r8 and r9 ] 32 bytes
	sub  rsp,20h 

	; Get the return address of the function
	mov  rcx,rsp
	mov  rcx,qword ptr[rcx+58h]
	sub  rcx,5

	; Call the function to get the name of the callee and caller	
	call FindSymbol_enter

	; Release the space reserved for the registersk by adding 32 bytes
	add  rsp,20h 

	; Restore the registers back by poping out
	pop rcx
	pop rdx
	pop rax
	pop r8
	pop r9
	pop r10
	pop r11

	;return
	ret

_penter endp

;--------------------------------------------------------------------
; _pexit procedure
;--------------------------------------------------------------------
_pexit proc
	
	; Store the volatile registers
	push r11
	push r10
	push r9
	push r8
	push rax
	push rdx
	push rcx

	; Reserve space for 4 registers [ rcx,rdx,r8 and r9 ] 32 bytes
	sub  rsp,20h 
	
	; Get the return address of the function
	mov  rcx,rsp
	mov  rcx,qword ptr[rcx+58h]

	call FindSymbol_exit

	; Release the space reserved for the registersk by adding 32 bytes
	add rsp,20h

	; Restore the registers back by poping out
	pop rcx
	pop rdx
	pop rax
	pop r8
	pop r9
	pop r10
	pop r11

	; Return
	ret
	
_pexit endp

end
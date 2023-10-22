/*
* Author : Hossam Daib
* File   : linker_script for cortex_m3
*/

MEMORY
{
	FLASH(rx) : ORIGIN = 0x00000000 , LENGTH = 512M
	SRAM(rwx) : ORIGIN = 0x20000000 , LENGTH = 512M 
}

SECTIONS
{
	.text : {
		*(.vectors*) 
		*(.text)
		*(.rodata)
		. = ALIGN(4) ;
		_E_text = . ;
	}> FLASH

	.data : {
		_S_data = . ;
		*(.data)
		. = ALIGN(4) ;
		_E_data = . ;
	}> SRAM AT> FLASH
	
	.bss : {
		_S_bss = . ;
		*(.bss)
		*(COMMON)
		. = ALIGN(4) ;
		_E_bss = . ;
		. = ALIGN(4) ;
		
	}> SRAM
	
}
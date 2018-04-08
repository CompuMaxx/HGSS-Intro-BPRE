        .gba
        .thumb
        .open input_game,output_game, 0x08000000
		

		.definelabel rom_code,0
		.ifdef BPEE
		.include "hooks/nop_bpee_intro.s"
		.endif

        .include "hooks/pointer.s"
        
        .org 0x08800000
        .importobj relocatable_obj
        .close

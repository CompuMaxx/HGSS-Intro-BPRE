    .macro BS_MESSAGE index
    .byte 0x10
    .short \index
    .endm

    .macro BS_GOTO loc
    .byte 0x28
    .long \loc
    .endm

    .macro BS_CMP_WORD op, address, value, loc
    .byte 0x2b
    .byte \op
    .long \address
    .long \value
    .long \loc
    .endm
    
    .equ BS_OP_FLAGS_SET, 4
    .equ BS_OP_FLAGS_CLEAR, 5

    .macro BS_WAITSTATE 
    .byte 0x3a
    .endm

    .macro BS_FINISH 
    .byte 0x3e
    .endm

    .macro BS_TRAINER_SLIDE_IN bank
    .byte 0x53
    .byte \bank
    .endm

    .macro BS_CALCULATE_MONEY loc
    .byte 0x5d
    .long \loc
    .endm

    .macro BS_GIVEMONEY 
    .byte 0x91
    .endm

    .macro BS_PICKUP 
    .byte 0xe5
    .endm


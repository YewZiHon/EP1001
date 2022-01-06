.global main

main:
  sbi 0x00, 1   ;pinmode 1 output, register 0x00 is a port A virtual register for data direction, VPORTA, DDRA
  sbi 0x00, 2   ;pinmode 2 output
  sbi 0x01, 1   ;turn led 1 on
  
loop:
  sbi 0x02, 1   ;toggle pin 1, register 0x02 is a port A virtual register for input, VPORTA, IN. Setting this bit high will toggle the bit in the OUT register.
  sbi 0x02, 2   ;toggle pin 2
  ldi r16,15    ;load register 16 with 15
  ldi r17,0     ;load register 17 with 0
  ldi r18,0     ;load register 18 with 0

delay: 
  dec r17       ;decrement reister 17
  brne delay    ;branch id r17 not equal to zero
  dec r18       ;decrement reister 18
  brne delay    ;branch id r18 not equal to zero
  dec r16       ;decrement reister 16
  brne delay    ;branch id r17 not equal to zero
  rjmp loop     ;go back to loop

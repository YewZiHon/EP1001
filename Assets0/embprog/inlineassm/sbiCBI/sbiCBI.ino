int main() {
  //set ddr
  asm __volatile__("sbi 0x00, 1 \n\t");
  //set pin
  asm __volatile__("loop: \n\t");
  asm __volatile__("sbi 0x02, 1 \n\t");
  //delay(1000);
  asm __volatile__(
    "ldi r16,20 \n\t"
    "ldi r17,0 \n\t"
    "ldi r18,0 \n\t"
    "delay: \n\t"
    "dec r17 \n\t" 
    "brne delay \n\t"
    "dec r18 \n\t"
    "brne delay \n\t"
    "dec r16 \n\t"
    "brne delay \n\t"
    "rjmp loop"
    : : :"r16", "r17", "r18");
}
#if (F_CPU!=4000000)
  #error "Set clock speed to 4MHz"
#endif

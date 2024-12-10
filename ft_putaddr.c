#include "ft_printf.h"

int ft_putaddr(void *addr)
{
  int i;
  
  i = 0;
  if (!addr)
    return (ft_putstr("(nil)"));
  i += ft_putstr("0x");
  i += ft_puthex((unsigned long)addr, 'x');
  return (i);
}
/*
int main()
{
   printf("Address: ");
    unsigned long addr = (unsigned long)&addr;  // Ottieni l'indirizzo di memoria di 'addr'
    // Stampa l'indirizzo con il prefisso "0x"
    int char_print = ft_putaddr(addr);  // La funzione ft_putaddr gestisce "0x" e l'indirizzo
    printf("\nCharacters printed: %d\n", char_print);  // Mostra quanti caratteri sono stati stampati

    return 0;
}
*/

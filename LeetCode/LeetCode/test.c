#include<inttypes.h>

void vga_putchar(int c, int color, int x, int y)
{
	uint16_t *pVRAM = (uint16_t*)0xB8000;
	pVRAM = pVRAM + ( x*80 + y);
	*pVRAM = c|(color<<8);
}


int main()
{
	//vga_putchar('a', 0x07, 0, 0);

  char *src = (char *)0xB8000000L;
  *src = 'M';
  src += 2;
  *src = 'D';
  return 0;
}
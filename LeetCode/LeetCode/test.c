#include<inttypes.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void vga_putchar(int c, int color, int x, int y)
{
	uint16_t *pVRAM = (uint16_t*)0xB8000;
	pVRAM = pVRAM + ( x*80 + y);
	*pVRAM = c|(color<<8);
}


int main()
{
//vga_putchar('a', 0x07, 0, 0);

//  char *src = (char *)0xB8000000L;
//  *src = 'M';
//  src += 2;
//  *src = 'D';

  char *src = "helloworld";
  printf("%s\n", src);


  //printf("%c",*src);
  //printf("%c",*(src+1));
  //printf("%c",*(src+2));
  //printf("\n");

  printf("%ld\n",strlen(src));
  char *des = malloc(strlen(src) + 1);
  char *p = des;
  while(*src != '\0') {
      printf("%c",*src);
      *p++ = *src++;
  }
  printf("\n");

  printf("%s\n", des);
  return 0;
}

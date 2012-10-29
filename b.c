/* b.c interchanges each pair of bits in an unsigned char */
#include <stdio.h>

unsigned char nibswap(unsigned char nib)
{
  switch(nib) 
	{
	case 0:
	  return nib;
	case 3:
	  return nib;
	case 1:
	  return 2;
	case 2:
	  return 1;
	default:
	  return 0;
	}
}

unsigned char swapnibs(unsigned char byte)
{
  unsigned char answer = 0;
  int i;
  for (i = 0; i < 4; i++)
	{
	  answer |= nibswap((byte >> i*2) & 3) << i*2;
	}
  return answer;
}

unsigned char strtobyte( char *c)
{
  int i;
  unsigned char byte = 0;
  char *p = c;
  for ( i = 0; i < 2; i++)
	{
	  switch(*p)
		{
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
		  byte |= (*p - '0') << (1-i)*4;
		  break;
	    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
		  byte |= (*p - 'a'+10) << (1-i)*4;
		  break;
		}
	  p++;
	}
  return byte;
}

int main(int argc, char **argv)
{
  printf("%s has %d args\n",argv[0], argc);
  printf("input: %s\n", argv[1]);
  unsigned char inputbyte = strtobyte(argv[1]);
  printf("byte is:%d in hex %x\n", inputbyte,inputbyte);
  printf("byte bit pair swapped in hex %x\n", swapnibs(inputbyte));
}

//s.c
#include <stdio.h>
#include <getopt.h>
#include <sys/socket.h>

static int verbose_flag;

int main(int argc, char **argv)
{
  int c;
      static struct option long_options[]= {

	{"verbose", no_argument,       &verbose_flag, 1},
	{"debug",   no_argument,       &verbose_flag, 0},
	/* These options don't set a flag.
	   We distinguish them by their indices. */
	{"add",     no_argument,       0, 'a'},
	{"ipaddr",  required_argument, 0, 'i'},
	{"port",    required_argument, 0, 'p'},
	{"file",    required_argument, 0, 'f'},
	{0, 0, 0, 0}
      }; /* static struct option */

  while(1)
    {

      int option_index = 0;

      c = getopt_long (argc, argv, "ai:p:f:",
		   long_options, &option_index);
     
      /* Detect the end of the options. */
      if (c == -1)
	break;

      switch (c)
	{
	case 0:
	  /* If this option set a flag, do nothing else now. */
	  if (long_options[option_index].flag != 0)
	    break;
	  printf ("option %s", long_options[option_index].name);
	  if (optarg)
	    printf (" with arg %s", optarg);
	  printf ("\n");
	  break;
	case 'a':
	  printf("option -a\n");
	  break;
	case 'i':
	  printf ("option -i with value `%s'\n", optarg);
	  break;
	case 'p':
	  printf ("option -p with value `%s'\n", optarg);
	  break;
	case 'f':
	  printf ("option -f with value `%s'\n", optarg);
	  break;
	case '?':
	  /* getopt_long already printed an error message. */
	  break;
     
	default:
	  printf("default switch\n");
	  break;
	} /* switch */
    }/* while */
  printf("socket\n");
}

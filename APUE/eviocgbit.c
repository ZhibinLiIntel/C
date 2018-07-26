#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <linux/input.h>
 
#define BITS_PER_LONG 32

#define BIT_WORD(nr) ((nr) / BITS_PER_LONG)

static int
test_bit(int nr, const volatile unsigned long *addr)
{
	unsigned long tmp = addr[BIT_WORD(nr)] >> (nr & (BITS_PER_LONG-1));
	//printf("nr & (BITS_PER_LONG-1) = %d\n", nr & (BITS_PER_LONG-1));
	//printf("tmp = %#x\n", tmp);
	return 1UL & (addr[BIT_WORD(nr)] >> (nr & (BITS_PER_LONG-1)));
	//return 1UL & tmp;
}

int
main(int argc, char ** argv)
{
	int fd;
	//unsigned long *evtype_b = malloc(sizeof(int));
	unsigned long evtype_b[EV_MAX];
	int yalv;

	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		perror("evdev open");
		exit(1);
	}

	memset(evtype_b, 0, sizeof(evtype_b));
	if (ioctl(fd, EVIOCGBIT(0x11, EV_MAX), evtype_b) < 0) {
		perror("evdev ioctl");
	}
	for (int i = 0; i < EV_MAX; i++)
		printf("evtype_b[%d] = %#x\n", i, evtype_b[i]);
	unsigned long n = evtype_b[0];
while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
}
printf("\n");


	printf("Supported event types:\n");

	for (yalv = 0; yalv < EV_MAX; yalv++) {
		if (test_bit(yalv, evtype_b)) {
		/* the bit is set in the event types list */
			printf("Event type 0x%02x ", yalv);
			printf("%d", yalv);
			switch (yalv) {
			case EV_SYN:
				printf("(Sync Events)\n");
				break;
			case EV_KEY:
				printf("(Keys or Buttons)\n");
				break;
			case EV_REL:
				printf("(Relative Axes)\n");
				break;
			case EV_ABS:
				printf("(Absolute Axes)\n");
				break;
			case EV_MSC:
				printf("(Miscellaneous)\n");
				break;
			case EV_LED:
				printf("(LEDs)\n");
				break;
			case EV_SND:
				printf("(Sounds)\n");
				break;
			case EV_REP:
				printf("(Repeat)\n");
				break;
			case EV_FF:
			case EV_FF_STATUS:
				printf("(Force Feedback)\n");
				break;
			case EV_PWR:
				printf("(Power Management)\n");
				break;
			default:
				printf("(Unknown: 0x%04hx)\n", yalv);
			}
		}
	}
	close(fd);
}

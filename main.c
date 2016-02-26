#include "main.h"

int main(int argc, char **argv)
{
	int width=77, delay=20;
	float freq=1, amp=1, tmp;

	/* get parameters and range check values */
	switch (argc){
		case 5:
			tmp = atoi(argv[4]);
			delay = (tmp >= 1) && (tmp <= 100) ?
					tmp : delay; 
		case 4:
			tmp = atoi(argv[3]);
			width = (tmp >= 50) && (tmp <= 77) ?
					tmp : 77;
		case 3:
			tmp = atof(argv[2]);
			amp = (tmp >= 0) && (tmp <= 1) ?
					tmp : amp;
		case 2:
			tmp = atof(argv[1]);
			freq = (tmp >= 0.1) && (tmp <= 10) ?
					tmp : freq;
	}

	/* generate sine wave and display */
	gen_sine(freq, amp, width, delay);

	return EXIT_SUCCESS;
}

/* generates a sinewave of specified frequency and amplitude */
static void gen_sine(
	const float freq,
	const float amp,
	const int width,
	const int delay)
{
	int A;
	char *disp=NULL;
	float x, y, d;
	A = amp * width;
	disp = (char *)calloc(sizeof(char), width + 1);	/* create display memory */
	memset(disp, ' ', width + 1);					/* clear display */
	d = 2 * M_PI * freq * delay / 1000;				/* calculate time step from delay */
	for (;;) {
		for (x=0; x < 2*M_PI; x+=d) {
			y = (A / 2 * sin(x)) + (width / 2);		/* generate sine wave */
			memset(disp, ' ', width + 1);
			disp[(int)y] = '*';
			printf("[%s]\n", disp);					/* display sine wave */
			fflush(stdout);
			usleep(delay * 1000);
		}
	}
	free(disp);
}

#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define MAX_SIZE 100


//
// Private
//
static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		// TODO: complete menu
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];

	char arraysize [MAX_SIZE];
	int SIZE_ARRAY=0;
	show_menu = true;
	bool getsize = false;
	while(getsize==false) 
	{
		flag:

		fgets(arraysize, sizeof(arraysize), stdin);
		arraysize[strcspn(arraysize, "\n")] = '\0';

		for (int i = 0 ; i < strlen(arraysize); i++) 
		{
			
			if(arraysize[i] < '1' || arraysize[i] > '9') 
			{
				printf("Only digits allowed\n");
				goto flag;
			}

		}
		arraysize[strcspn(arraysize, "\n")] = '\0';
		SIZE_ARRAY = atoi(arraysize);
		if(SIZE_ARRAY > 0) 
		{
			getsize=true;
			break;
		}
		printf("Value not allowed. \n");
		}
	

	
	if(getsize == true) 
	{
		running = true;
	}




	while (running) {
		printf("%d",SIZE_ARRAY);
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				printf("todo> implement BE + present results in FE\n");
				break;

			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				printf("todo> implement WE + present results in FE\n");
				break;
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}

#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include "mylibc.h"

void timer(void)
{
    int x = 0;
    int y = 0;
    struct timespec tp;
    clockid_t clk_id = CLOCK_REALTIME;

    getmaxyx(stdscr, x, y);
    clock_gettime(clk_id, &tp);
    mvprintw(x / 6, (y - my_nbrlen(tp.tv_sec)) / 2, "%d\n", clock_gettime(clk_id, &tp));
        refresh();

  // printf("result: %i\n", result);
  // printf("tp.tv_sec: %lld\n", tp.tv_sec);
  // printf("tp.tv_nsec: %ld\n", tp.tv_nsec);

  // result = clock_getres(clk_id, &tp);
  // printf("result: %i\n", result);
  // printf("tp.tv_sec: %lld\n", tp.tv_sec);
  // printf("tp.tv_nsec: %ld\n", tp.tv_nsec);

}

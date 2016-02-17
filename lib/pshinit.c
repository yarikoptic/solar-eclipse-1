/*
 * PSHINIT...set things up to use a program with Pipeshell and Pipecheck
 *
 * Call this from FORTRAN as if it were SUBROUTINE PSHINIT with no arguments
 * in order to set up a FORTRAN program for use by Pipeshell
 *
 * From C, call this as pshinit_();
 *
 * Author: Charles Peterson
 *   Date: 5-July-1995
 */
#include <stdio.h>
void pshinit_ (void)
{
    static unsigned long magic = 0xf31ae3ad;   /* generated by lrand48 */
                                      /* psh searches for this */
/*  setbuf (stdout, NULL); */

/*
 * The following USES 'magic' to force the compiler not to optimize
 * it away.  However, it isn't actually used by setvbuf: since
 * _IONBF is specified, there is NO buffering.  As a result, the
 * following call is actually equivalent to the above call which is
 * commented out.
 */
    setvbuf (stdout, (char *) &magic, _IONBF, sizeof magic);
}


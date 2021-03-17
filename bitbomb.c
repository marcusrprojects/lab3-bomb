/***************************************************************************
 * My Insidious BitBomb, Version 1.3
 * Copyright 2018, BitBombs Inc. All rights reserved.
 *
 * LICENSE:
 *
 * BitBombs Inc. (the PERPETRATOR) hereby grants you (the VICTIM)
 * explicit permission to use this bitbomb (the BITBOMB). This is a
 * time limited license, which expires on the segfault of the VICTIM.
 * The PERPETRATOR takes no responsibility for damage, frustration,
 * insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or other
 * harm to the VICTIM. The VICTIM may not distribute the source code of
 * the BITBOMB to any enemies of the PERPETRATOR.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and defuse the BITBOMB.
 * BITBOMB proof clothing may not be worn when handling this program. The
 * PERPETRATOR will not apologize for the PERPETRATOR's poor sense of
 * humor.  This license is null and void where the BITBOMB is prohibited
 * by law.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/* 
 * Note to self: Remember to erase this file so that victims will have no idea
 * what is going on while they perish in a spectacular segfault or bus error.
 */

FILE* infile;

int main(int argc, char** argv) {
  char* input;

  /* Note to development team: please remember to port this bitbomb to Windows
   * and put a fantastic GUI on it. We promised these features to Microsoft.
   * -- BitBombs Inc. Management */

  if (argc == 1) {  
    /* When run with no arguments, the bitbomb reads its input lines 
     * from standard input (i.e., the terminal). */
    infile = stdin;
  } else if (argc == 2) {
    /* When run with one argument <file>, the bitbomb reads from <file> 
     * until end-of-file (EOF), and then switches to standard input. Thus,
     * as you defuse each phase, you can add its defusing string to <file>
     * and avoid having to retype it. */
    if (!(infile = fopen(argv[1], "r"))) {
      printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
      exit(8);
    }
  } else {
    /* You can't call the bitbomb with more than 1 command line argument. */
    printf("Usage: %s [<input_file>]\n", argv[0]);
    exit(8);
  }

  /* Do all sorts of secret stuff that makes the bitbomb harder to defuse. */
  initialize_bitbomb();

  printf("Welcome to your own personal bitbomb. You have 6 phases with\n");
  printf("which to blow yourself up. Have a nice day!\n");

  /* Hmm...  Six phases must be more secure than one phase! */
  input = read_line();             /* Get input                   */
  phase_1(input);                  /* Run the phase               */
  phase_defused();                 /* Drat!  They figured it out!
                                    * Let me know how they did it. */
  printf("Phase 1 defused. Probably just luck. How about the next one?\n");

  /* The second phase is harder.  No one will ever figure out
   * how to defuse this... */
  input = read_line();
  phase_2(input);
  phase_defused();
  printf("Phase 2 defused, but the next phase is impossible. Don't even bother.\n");

  /* I guess this is too easy so far.  Some more complex code will
   * confuse people. */
  input = read_line();
  phase_3(input);
  phase_defused();
  printf("Okay, I lied. Phase 3 defused. But the next phase has 50%% more bits!\n");

  /* I guess 50% more bits wasn't enough. We can fix that... */
  input = read_line();
  phase_4(input);
  phase_defused();
  printf("Phase 4 defused, but that was just to give you false hope for the next one.\n");

  /* Round and 'round in memory we go, where we stop, the bitbomb blows! */
  input = read_line();
  phase_5(input);
  phase_defused();
  printf("Hmph. Phase 5 defused. Luckily, nobody has ever solved the next one...\n");

  /* This phase will never be used, since no one will get past the
   * earlier ones.  But just in case, make this one extra hard. */
  input = read_line();
  phase_6(input);
  phase_defused();

  /* Wow, they got it!  But isn't something... missing?  Perhaps
   * something they overlooked?  Mua ha ha ha ha! */

  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getWord(char *ans);
void updateBoard(char *ans, int *tracker, char *board);
void checkGuess(char *ans, int *tracker, char *guess, int *correct,
                int *turnsLeft);
void printBoard(char *board);

const int GUESSES = 5;

int main() {
  char ans[10];
  getWord(ans);
  int len = strlen(ans);

  // set up tracker
  int tracker[len]; // 0 incorrect 1 correct
  for (int i = 0; i < len; i++) {
    tracker[i] = 0;
  }

  // set up board
  char board[len]; // _ or ch
  for (int i = 0; i < len; i++) {
    board[i] = *"_";
  }

  int correct = 0;
  char guess[10] = {}; // err if len too long
  int turnsLeft = 5;
  while (turnsLeft > 0) {
    printBoard(board);
    puts("Take a guess:");
    scanf("%s", guess);
    checkGuess(ans, tracker, guess, &correct, &turnsLeft);
    if (correct == len) {
      puts("YOU WIN!");
      return 0;
    }
    updateBoard(ans, tracker, board);
    printf("You guessed %s\n", guess);
  }
  puts("Noooo so sorry.");
  printf("The word was %s\n", ans);
  return 0;
}

void updateBoard(char *ans, int *tracker, char *board) {
  for (int i = 0; i < strlen(ans); i++) {
    if (tracker[i] == 1) {
      if (board[i] != ans[i]) {
        board[i] = ans[i];
      }
    }
  }
}

// checkGuess ans with guess
void checkGuess(char *ans, int *tracker, char *guess, int *correct,
                int *turnsLeft) {
  int initial = *correct;

  for (int i = 0; i < strlen(ans); i++) {
    if (tracker[i] == 1) {
      continue;
    }
    for (int j = 0; j < strlen(ans); j++) {
      if (guess[j] == ans[i]) {
        tracker[i] = 1;
        *correct = *correct + 1;
      }
    }
  }
  // check if correct
  if (initial == *correct) {
    puts("add to hangman");
    *turnsLeft = *turnsLeft - 1;
    // add to hangman
  }
}

void printBoard(char *board) {
  for (int i = 0; i < strlen(board); i++) {
    printf("%c ", board[i]);
  }
  puts("");
}

const char WORDS[][20] = {
    "abruptly",   "absurd",     "abyss",      "affix",      "askew",
    "avenue",     "awkward",    "axiom",      "azure",      "bagpipes",
    "bandwagon",  "banjo",      "bayou",      "beekeeper",  "bikini",
    "blitz",      "blizzard",   "boggle",     "bookworm",   "boxcar",
    "boxful",     "buckaroo",   "buffalo",    "buffoon",    "buxom",
    "buzzard",    "buzzing",    "buzzwords",  "caliph",     "cobweb",
    "cockiness",  "croquet",    "crypt",      "curacao",    "cycle",
    "daiquiri",   "dirndl",     "disavow",    "dizzying",   "duplex",
    "dwarves",    "embezzle",   "equip",      "espionage",  "euouae",
    "exodus",     "faking",     "fishhook",   "fixable",    "fjord",
    "flapjack",   "flopping",   "fluffiness", "flyby",      "foxglove",
    "frazzled",   "frizzled",   "fuchsia",    "funny",      "gabby",
    "galaxy",     "galvanize",  "gazebo",     "giaour",     "gizmo",
    "glowworm",   "glyph",      "gnarly",     "gnostic",    "gossip",
    "grogginess", "haiku",      "haphazard",  "hyphen",     "iatrogenic",
    "icebox",     "injury",     "ivory",      "ivy",        "jackpot",
    "jaundice",   "jawbreaker", "jaywalk",    "jazziest",   "jazzy",
    "jelly",      "jigsaw",     "jinx",       "jiujitsu",   "jockey",
    "jogging",    "joking",     "jovial",     "joyful",     "juicy",
    "jukebox",    "jumbo",      "kayak",      "kazoo",      "keyhole",
    "khaki",      "kilobyte",   "kiosk",      "kitsch",     "kiwifruit",
    "klutz",      "knapsack",   "larynx",     "lengths",    "lucky",
    "luxury",     "lymph",      "marquis",    "matrix",     "megahertz",
    "microwave",  "mnemonic",   "mystify",    "naphtha",    "nightclub",
    "nowadays",   "numbskull",  "nymph",      "onyx",       "ovary",
    "oxidize",    "oxygen",     "pajama",     "peekaboo",   "phlegm",
    "pixel",      "pizazz",     "pneumonia",  "polka",      "pshaw",
    "psyche",     "puppy",      "puzzling",   "quartz",     "queue",
    "quips",      "quixotic",   "quiz",       "quizzes",    "quorum",
    "razzmatazz", "rhubarb",    "rhythm",     "rickshaw",   "schnapps",
    "scratch",    "shiv",       "snazzy",     "sphinx",     "spritz",
    "squawk",     "staff",      "strength",   "strengths",  "stretch",
    "stronghold", "stymied",    "subway",     "swivel",     "syndrome",
    "thriftless", "thumbscrew", "topaz",      "transcript", "transgress",
    "transplant", "triphthong", "twelfth",    "twelfths",   "unknown",
    "unworthy",   "unzip",      "uptown",     "vaporize",   "vixen",
    "vodka",      "voodoo",     "vortex",     "voyeurism",  "walkway",
    "waltz",      "wave",       "wavy",       "waxy",       "wellspring",
    "wheezy",     "whiskey",    "whizzing",   "whomever",   "wimpy",
    "witchcraft", "wizard",     "woozy",      "wristwatch", "wyvern",
    "xylophone",  "yachtsman",  "yippee",     "yoked",      "youthful",
    "yummy",      "zephyr",     "zigzag",     "zigzagging", "zilch",
    "zipper",     "zodiac",     "zombie",
};

void getWord(char *ans) {
  int n = rand() % 124;
  for (int i = 0; i < strlen(WORDS[n]); i++) {
    ans[i] = WORDS[n][i];
  }
}

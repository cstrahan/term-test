#include <stdio.h>

#include "termkey.h"

int main(int argc, char *argv[]) {
  char buffer[50];
  TermKey *tk = termkey_new(0, 0);

  if(!tk) {
    fprintf(stderr, "Cannot allocate termkey instance\n");
    exit(1);
  }

  TermKeyResult ret;
  TermKeyKey key;

  while((ret = termkey_waitkey(tk, &key)) != TERMKEY_RES_EOF) {
    termkey_strfkey(tk, buffer, sizeof buffer, &key, TERMKEY_FORMAT_VIM);
    printf("You pressed key %s\n", buffer);

    if(key.type == TERMKEY_TYPE_UNICODE &&
       key.modifiers & TERMKEY_KEYMOD_CTRL &&
       (key.code.codepoint == 'C' || key.code.codepoint == 'c'))
      break;
  }

  termkey_destroy(tk);
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BracketNode {
  char bracket;
  struct BracketNode *pre;
} BracketNode;

BracketNode *createNode(int bracket, BracketNode *pre) {
  BracketNode *newNode = (BracketNode *)malloc(sizeof(BracketNode));
  newNode->bracket = bracket;
  newNode->pre = pre;
  return newNode;
}

bool isValid(char *s) {
  if (strlen(s) % 2 != 0)
    return false;

  BracketNode *curr = NULL;
  for (int i = 0; s[i]; i++) {
    switch (s[i]) {
    case '(':
      curr = createNode(')', curr);
      break;
    case '{':
      curr = createNode('}', curr);
      break;
    case '[':
      curr = createNode(']', curr);
      break;
    default:
      if (curr == NULL || s[i] != curr->bracket)
        return false;
      BracketNode *pre = curr->pre;
      free(curr);
      curr = pre;
      break;
    }
  }

  return curr == NULL;
}
int main(void) {
  char s1[] = "()"; // 1
  printf("%d\n", isValid(s1));
  char s2[] = "({)"; // 0
  printf("%d\n", isValid(s2));

  return 0;
}
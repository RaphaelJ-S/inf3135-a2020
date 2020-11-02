#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int check_d(int argc, char **argv, int pos) {
  if(strcmp(argv[pos], "-d") == 0) {
    if((pos + 1) < argc) {
      char* val = argv[pos+1];
      if(strcmp(val, "INC") == 0 || strcmp(val,"DEC") == 0) {
        return 0;
      }
    }
    return 3;
  }
  return 0;
}

int check_v(int argc, char **argv, int pos) {
  if(strcmp(argv[pos], "-v") == 0 ) {
    if((pos + 1) < argc) {
      long entier = atol(argv[pos + 1]);
      if(!entier) {
        return 2;
      }
    }else {
      return 2; 
    }
  }
  return 0; 
}

int cmdline(int argc, char **argv) {
  bool a_c = false;

  if(argc != 1) {
    for(int i = 1; i != argc; i += 2) {

      int ret_d = check_d(argc, argv, i);
      if(ret_d != 0) return ret_d; 
      int ret_v = check_v(argc, argv, i);
      if(ret_v != 0) return ret_v;
      
      if(strcmp(argv[i], "-c") == 0) {
        if((i+1) < argc) {
          if(strcmp(argv[i+1], "MOT") == 0) {
            a_c = true;
          }

        }
      } 
    }
    
  }
  if(a_c) return 0; 
  return 1;
}
int main(int argc, char **argv) {
  int ret_cmd = cmdline(argc, argv);
  printf("\nle résultat de la cmdline : %d\n", ret_cmd);
}

#include "outil3.h"
#include "malib.h"

int main(int argc, char** argv) {
  char str[200];
  char* ptr;
  unsigned char flags[4]={0,0,0,0};
  identifiant_t identification = {9999, 2};
  Compteur_t compte = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  idPN_t idPN = {0, malloc(sizeof(size_t)), 0};
  version_t vers;   
  getVersion(&vers);
  donnees_t data = {&vers,flags , &compte, &identification, &idPN, 0};  
  int option = cmd(argc, argv, &data);
  
  if(option == 0) {
    printf("version #: %d.%d.%d",vers.major, vers.minor, vers.build);
    while(fgets(str,200, stdin) != NULL) {
        ptr = strtok(str, "\n");
        data.cmpt_s->nbrTrxTot += 1;
        lecture(ptr, &data);
    }
    affichageOptions(&data);
  }else printf("\n\nUne option n'est pas valide. Les options sont : -d -t -i -s\n\n");
  
  free(idPN.tab);
  return 0;
}

#ifndef MALIB_H
#define MALIB_H
typedef struct {
  size_t valInvalide;
  size_t manifErr;
  size_t cumulErr;
} compteur;

typedef struct {
  size_t timestamp;
  size_t id;
  char* evenement;
  unsigned char puissance;
} Identite; 

typedef struct {
  size_t timestamp;
  char* evenement;
  union {
    float celcius;
    char* erreur;
  };
} TmpHum;
typedef struct {
  size_t timestamp;
  char* evenement;
  union {
    float celcius;
    char* erreur;
  };
} TmpAmb;

typedef struct {
  size_t timestamp;
  char* evenement;
  union {
    float pulse;
    char* erreur;
  };
} Pulsation;

typedef struct {
  size_t timestamp;
  char* evenement;
  short puissRSSI;
  size_t id;
} Signal;

typedef struct {
  size_t timestamp;
  char* evenement;
  size_t id;
  size_t* idPN; 
} Echange;

int retourne(int);
#endif

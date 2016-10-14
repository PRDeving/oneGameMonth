#ifndef H_MONSTER
#define H_MONSTER

#include "includes.h"
struct _Monster {
  float pos[2];
  float direction;
  float aceleration;
  float topSpeed;

  int HP;
  int MaxHP;

  int S;
  int T;
  int CP;

  int Lvl;
  int treasure;
};

int _monster_takeDamage(Monster*, int);
int _monster_heal(Monster*, int);
int _monster_attacks(Monster*, Player*);
void _monster_dead(Monster*);

#endif


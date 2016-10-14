#ifndef PLAYER_H
#define PLAYER_H
#include "includes.h"
  struct _Player {
    float pos[2];
    float direction;
    float aceleration;
    float topSpeed;

    int HP;
    int MaxHP;

    int S;
    int T;
    int CP;

    int Exp;
    int ExpToNextLevel;
    int Lvl;

    int gold;
  };

  int _player_takeDamage(Player*, int);
  int _player_heal(Player*, int);
  int _player_attacks(Player*, Monster*);
  void _player_kills(Player*, Monster*);
  void _player_dead(Player*);

  int _player_winExp(Player*, int);
  int _player_nextLevel(Player*);
  int _player_getsGold(Player*, int);

#endif


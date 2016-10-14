#include "monster.h"
#include "player.h"

Player newPlayer() {
  Player player = {
    {10, 10}, //pos
    0,        //direction
    0,        //aceleration
    5,        //topSpeed

    15,       //HP
    15,       //MaxHP

    5,
    5,
    4,        //Critic prob

    0,        //Exp
    10,       //Exp to next Lvl
    1,        //Lvl

    0,        //Gold
  };

  return player;
}

int _player_takeDamage(Player* pj, int damage) {
  pj->HP -= damage;
  if (pj->HP <= 0) _player_dead(pj);
  return pj->HP;
}

int _player_heal(Player* pj, int amount) {
  pj->HP += amount;
  if (pj->HP > pj->MaxHP) pj->HP = pj->MaxHP;
  return pj->HP;
}

void _player_kills(Player* pj, Monster* mnt) {
  _player_winExp(pj, (int)(mnt->Lvl * randFloat(1, 3)));
  _player_getsGold(pj, mnt->treasure);
}

int _player_attacks(Player* pj, Monster* mnt) {
  int critic = randInt(0, 100);
  int damage = pj->S - mnt->T;
  if (critic > pj->CP) damage += (int)(pj->S/2);
  if (_monster_takeDamage(mnt, damage) <= 0) _player_kills(pj, mnt);
  return damage;
}
void _player_dead(Player* pj){
  pj->HP = 0;
};

int _player_winExp(Player* pj, int amount) {
  pj->Exp += amount;
  if (pj->Exp >= pj->ExpToNextLevel) _player_nextLevel(pj);
  return pj->Exp;
}
int _player_nextLevel(Player* pj) {
  pj->Lvl++;
  pj->ExpToNextLevel *= (int)(2 + (10/pj->Lvl));
  pj->S ++;
  pj->T ++;
  return pj->Lvl;
}
int _player_getsGold(Player* pj, int amount) {
  pj->gold += amount;
  return pj->gold;
}

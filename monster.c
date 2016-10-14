#include "monster.h"
#include "player.h"

Monster newMonster() {
  Monster monster = {
    {0, 0},     //float pos[2];
    0,          //float direction;
    0,          /* float aceleration; */
    5,          /* float topSpeed; */

    10,         /* int HP; */
    10,         /* int MaxHP; */

    4,          /* int S; */
    4,          /* int T; */
    5,          /* int CP; */

    3,          /* int Lvl; */
    randInt(1, 7),  /* int treasure; */
  };

  return monster;
}

int _monster_takeDamage(Monster* mnt, int damage) {
  mnt->HP -= damage;
  if (mnt->HP <= 0) _monster_dead(mnt);
  return mnt->HP;
}

int _monster_heal(Monster* mnt, int amount) {
  mnt->HP += amount;
  if (mnt->HP > mnt->MaxHP) mnt->HP = mnt->MaxHP;
  return mnt->HP;
}

void _monster_dead(Monster* mnt) {
  mnt->HP = 0;
}

int _monster_attacks(Monster* mnt, Player* pj) {
  int critic = randInt(0, 100);
  int damage = mnt->S - pj->T;
  if (critic > mnt->CP) damage += (int)(mnt->S/2);
  return damage;
}

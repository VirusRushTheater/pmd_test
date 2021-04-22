// Copyright(c) 2015 Purpasmart
// The MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#ifndef _ITEM_MANAGER_H_
#define _ITEM_MANAGER_H_

#include "util.h"
#include "itemlist.h"       // Made to include enum Items here and in pokemon.h
#include "common/vec.h"
#include "game/pokemon.h"

#define NO_ITEMS 0
#define MAX_ITEMS 48
#define NEXT_SLOT i + 1

typedef enum ItemLocation
{
    LocationBag,
    LocationPokemonLeader,
    LocationPokemonTeamateOne,
    LocationPokemonTeamateTwo,
    LocationPokemonTeamateThree,
    LocationPokemonTeamateFour,
    LocationPokemonTeamateFive,
    LocationPokemonTeamateSix,
    LocationPokemonTeamateSeven,
    LocationGround,
} ItemLocation;

typedef struct Bag
{
    struct Item *items;
    u32 size; // does not contain dupe items
    u32 real_size; // contains dupe items
    u32 capacity;
} Bag;

typedef struct Item
{
    Items type;
    void(*Throw)(struct Bag *, struct PokemonParty *, struct Pokemon_s *, ItemLocation, Items item);
    void(*Use)(struct Bag *, struct PokemonParty *, struct Pokemon_s *, ItemLocation, Items item);
    void(*Drop)(struct Bag *, struct PokemonParty *, struct Pokemon_s *, ItemLocation, Items item);
    void(*Reserved0)();
    void(*Reserved1)();
    void(*Reserved2)();
    ivec2 position;
    int size; // internal amount
} Item;

typedef struct Dungeon Dungeon;

Bag *Bag_New(bool init);
void Bag_Init(Bag *self);
void Bag_ShutDown(Bag *self);

void ClearBag(struct Bag *self);
bool IsBagEmpty(struct Bag *self);
bool IsBagFull(struct Bag *self);
void DisplayBag(struct Bag *self);
void Bag_SortItems(struct Bag *self);
void Bag_DecrementExistingItemInBag(Bag *self, int index);
void Bag_IncrementExistingItemInBag(Bag *self, int index);
int Bag_ItemAlreadyExists(Bag * self, Items type);
void Bag_CountSortItemsDesc(struct Bag *self, int n, int range);
//void AddEmptySlots(struct Bag *self);
//void UpdateBag(struct Bag *self);
void GiveItemToTeamMember(struct Bag *self, struct Pokemon_s *team_member, struct Item item);
void GiveItemToTeamMember_(struct Bag *self, struct Pokemon_s *team_member, const char *item_name);
void AddItemToBagByType(struct Bag *self, Items type);
void AddItemToBag(struct Bag *self, struct Item item);
// String version
void AddItemToBag_(Bag *self, const char *item_name);
void RemoveItemFromBag(Bag *self, struct Item item);
// String version
bool RemoveItemFromBag_(struct Bag *self, const char *item_name);
void RemoveItemFromTeamMemberToBag(struct Bag *self, struct Pokemon_s *team_member, struct Item item);

void RemoveItemFromTeamMemberToBag_(struct Bag *self, struct Pokemon_s *team_member, const char *item_name);
void AddItemToBagFromGround(Bag * bag, struct Pokemon_s *poke, Dungeon *dungeon);
bool RemoveItemFromGround(Dungeon *dungeon, struct Pokemon_s *poke);
bool RemoveItem(struct Bag *bag, struct Pokemon_s *poke, enum ItemLocation location, const char *item_name);

void Pokemon_AssignItem(struct Pokemon_s *dst_poke, const char *item_name);
void Bag_AssignItem(struct Bag *bag, int index, const char *item_name);
void Bag_AssignItemByType(struct Bag *bag, int index, Items type);

void UseItem(struct Bag *bag, struct PokemonParty *party, struct Pokemon_s *user, const char *item_name, ItemLocation location);
void UseItemFromBag(struct Bag *bag, struct PokemonParty *party, struct Pokemon_s *user, const char *item_name);


#endif

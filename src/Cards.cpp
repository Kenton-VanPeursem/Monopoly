#include "Cards.hpp"
#include <vector>

const long stack_size = 16;

Cards::Cards(e_type type)
{
    FILE* fp;
    long i;

    if      (type == CHANCE)
        fp = fopen("/Users/ksvanpeu/kProjects/Monopoly/db/Chance.txt", "r");
    else if (type == COMMUNITY_CHEST)
        fp = fopen("/Users/ksvanpeu/kProjects/Monopoly/db/Chest.txt", "r");
    else
        return;

    for (i = 0; i < stack_size; ++i)
    {
        fscanf(fp, "%li %li %li %s", stack[i].type, stack[i].amount1, stack[i].amount2, stack[i].description);
    }

    fclose(fp);

    Shuffle();
}

void Cards::Shuffle()
{
    std::vector<card*> tmp;
    long i, loc;

    for (i = 0; i < stack_size; ++i)
    {
        tmp.push_back(&stack[i]);
    }

    for (i = 0; i < stack_size; ++i)
    {
        loc = rand() % (stack_size - i);
        pile.push(tmp[loc]);
        tmp.erase.at(loc);
    }
}

void Cards::GetCard(card *it)
{
    it = pile.front();
    pile.push(it);
    pile.pop();
}



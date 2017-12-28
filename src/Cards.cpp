#include "Cards.hpp"
#include <list>
#include <vector>

Cards::Cards(e_type type)
{
    FILE *fp;
    long i;

    if (type == CHANCE)
        fp = fopen("/Users/ksvanpeu/kProjects/Monopoly/db/Chance.txt", "r");
    else if (type == COMMUNITY_CHEST)
        fp = fopen("/Users/ksvanpeu/kProjects/Monopoly/db/Chest.txt", "r");
    else
        return;

    char desc[BUFSIZ];
    for (i = 0; i < stack_size; ++i)
    {
        fscanf(fp, "%i %li %li %s", &stack[i].type, &stack[i].amount1, &stack[i].amount2, desc);
        stack[i].description = std::string(desc);
    }

    fclose(fp);

    Shuffle();
}

void Cards::Shuffle()
{
    std::vector<card *> tmp;
    long i, loc;

    for (i = 0; i < stack_size; ++i)
    {
        tmp.push_back(&stack[i]);
    }

    for (i = 0; i < stack_size; ++i)
    {
        loc = rand() % (stack_size - i);
        pile.push(tmp[loc]);
        auto it = tmp.begin();
        for (int j = 0; j < loc; ++j)
        {
            it++;
        }
        tmp.erase(it);
    }
}

void Cards::GetCard(card *it)
{
    it = pile.front();
    pile.push(it);
    pile.pop();
}

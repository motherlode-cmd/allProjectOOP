#include "eventkey.h"

void EventKey::makeAction(Player * player)
{
    notify(Level::State, print());
    player->gotKey(true);
}

//std::ostream& operator << (std::ostream & os, const EventKey & e) {
//    //os << "Player ot Key \n";
//    e.print(os);
//    return os;
//}

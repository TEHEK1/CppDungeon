#include "actions/Use.h"
#include "events/Chest.h"
namespace actions {
    Use::Use(Chest *chest) : m_chest(chest) {}

    void Use::act(Player *player) {
        m_chest->use(player);
    }

    Chest *Use::getChest() {
        return m_chest;
    }
}//namespace actions
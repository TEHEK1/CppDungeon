#include "actions/Use.h"
#include "events/Chest.h"
namespace actions {
    Use::Use(Chest *chest, int index) : m_chest(chest), m_index(index) {}

    void Use::act(Player *player) {
        m_chest->use(player, m_index);
    }

    Chest *Use::getChest() {
        return m_chest;
    }
}//namespace actions
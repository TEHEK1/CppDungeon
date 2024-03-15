#include "actions/Use.h"
#include "events/Chest.h"
namespace actions {
    Use::Use(const std::shared_ptr<Chest>& chest) : m_chest(chest) {}

    void Use::act(Player *player) {
        m_chest->use(player);
    }

    std::shared_ptr<Chest> Use::getChest() {
        return m_chest;
    }
}//namespace actions
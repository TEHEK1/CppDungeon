#include "actions/Use.h"
#include "events/Chest.h"
namespace actions {
    Use::Use(const std::shared_ptr<events::UsableEvent>& usableEvent) : m_usableEvent(usableEvent) {}

    void Use::act(Player *player) {
        m_usableEvent->use(player);
    }

    std::shared_ptr<events::UsableEvent> Use::UsableEvent() {
        return m_usableEvent;
    }
}//namespace actions
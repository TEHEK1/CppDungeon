#include "actions/Use.h"
#include "events/UsableEvent.h"
namespace actions {
    Use::Use(const std::shared_ptr<events::UsableEvent>& usableEvent) : m_usableEvent(usableEvent) {}

    void Use::act(Player *player) {
        m_usableEvent->use(player);
    }
    std::shared_ptr<events::UsableEvent> Use::getUsableEvent() {
        return m_usableEvent;
    }
}//namespace actions
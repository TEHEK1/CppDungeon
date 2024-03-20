#include "NPC.h"
#include "BattlefieldMedicine.h"

namespace NPC {
    namespace PlagueDoctor{
        class PlagueDoctor : public NPC {
            std::vector<std::vector<char>> drawAlive() override;
            PlagueDoctor();
        };
    }
}
#include <OGL3D/Game/OGame.h>
#include "CubeGame.h"  // Included the new game class
#include <iostream>

int main() {
    try {
        CubeGame game;  // Use our CubeGame implementation
        game.run();
    }
    catch (const std::exception& e) {
        std::clog << "Exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}

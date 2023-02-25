#include <raylib-cpp.hpp>

#include "fixed_loop.hpp"

namespace rl = raylib;

struct GameState {
    rl::Window window;
    util::FixedLoop fixed_loop;
};

static void main_loop(void* game_state_ptr)
{
    GameState& state = *static_cast<GameState*>(game_state_ptr);

    state.fixed_loop.update(20, []() {

    });

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    EndDrawing();
}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    rl::Window window(800, 600, "Swept AABB");

    util::FixedLoop fixed_loop(60.0f);

    GameState state { .window = window, .fixed_loop = util::FixedLoop(60.0f) };

    while (!state.window.ShouldClose()) {
        main_loop(&state);
    }

    return EXIT_SUCCESS;
}
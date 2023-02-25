#include <raylib-cpp.hpp>

#include "fixed_loop.hpp"

namespace rl = raylib;

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    rl::Window window(800, 600, "Swept AABB");

    util::FixedLoop fixed_loop(60.0f);

    rl::Rectangle wall(400, 200, 100, 300);
    rl::Rectangle box(100, 100, 50, 50);

    while (!window.ShouldClose()) {
        fixed_loop.update(20, [&]() {
            if (rl::Mouse::IsButtonDown(MOUSE_BUTTON_LEFT)) {
                rl::Vector2 pos = box.GetPosition() + box.GetSize() / 2.0f;
                pos += (rl::Mouse::GetPosition() - pos) / 10.0f;
                box.SetPosition(pos - box.GetSize() / 2.0f);
            }
        });

        BeginDrawing();
        ClearBackground(BLACK);

        wall.Draw(rl::Color::Gray());
        box.Draw(rl::Color::Red());

        DrawFPS(10, 10);
        EndDrawing();
    }

    return EXIT_SUCCESS;
}
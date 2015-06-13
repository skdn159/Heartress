#pragma once
enum BodyShape
{
    CIRCLE,
    BOX,
};

// enum CursorMode
// {
//     CURSOR_DEFAULT,
//     CURSOR_ATTACK,
//     CURSOR_TELEPORT,
//     CURSOR_SPLASH,
// };

enum Direction
{
    E,
    W,

};

enum GameResult
{
    WIN,
    LOSE,
};

enum MissileType
{
    MISSILE_NONE,
    DIRT_DESTROYER,
    TANK_DESTROYER,
    DIRT_MAKER,
};

enum Team
{
    TEAM_NONE,
    TEAM_A,
    TEAM_B,
};

enum UnitType
{
    UNIT_NONE,
    UNIT_TANK,
    UNIT_MISSILE,
};
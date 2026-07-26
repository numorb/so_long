# so_long

A small 2D tile-based game written in **C** from scratch, using the minimal graphics library **MiniLibX**. Built at 42 Berlin as part of the Common Core.

You play a character who must collect every collectible on the map and reach the exit, in as few moves as possible.

![](./preview.gif)

## What it does

- Parses and validates a map from a `.ber` file: the map must be rectangular, fully enclosed by walls, and contain exactly one player, one exit, and at least one collectible
- Verifies the map is actually solvable with a **flood-fill** pathfinding check before the game starts
- Renders the world with textured sprites; smooth window management (no flicker on minimize/focus)
- Movement with W/A/S/D, move counter printed to the shell on every step
- Clean exit on `ESC` or window close, with all allocated memory freed
- Handles every invalid input with an explicit `Error` message instead of crashing

## Bonus
- Enemy patrols that end the game on contact
- Sprite animation
- On-screen move counter rendered in the window
-->

## What it demonstrates

Manual memory management, file parsing and defensive input validation, a basic game loop, event-driven programming through X11/MiniLibX hooks, and a recursive flood-fill algorithm — all in raw C, no external libraries beyond MiniLibX.

## Build & run

```bash
make
./so_long maps/[mapname].ber
```

## Constraints (42 rules)

Written under the 42 "Norm": functions max 25 lines, no global variables, only `open/close/read/write/malloc/free/perror/strerror/exit` plus MiniLibX and the math library. Zero memory leaks (checked with valgrind) and zero crashes on any input, verified in peer-review defense.

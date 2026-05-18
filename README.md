# ♟️ CHECKMATE — A Chess Engine in C with GTK3 GUI

> A fully functional, rules-compliant chess game built from scratch in **C**, featuring a graphical interface via **GTK3**, an AI opponent, check/checkmate detection, and complete move validation for all six piece types.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Architecture](#architecture)
- [Game Logic](#game-logic)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Engineering Takeaways](#engineering-takeaways)

---

## Overview

CHECKMATE is a desktop chess application written entirely in **C** (no frameworks, no chess libraries). Every rule — piece movement, capture logic, check detection, checkmate resolution, and illegal move filtering — was implemented from first principles by the team.

The project was built as part of a collaborative engineering exercise at **IIT Jodhpur**, with a clean separation of concerns across game logic, GUI, and global state.

---

## Features

- **Full piece move generation** for all six chess pieces (King, Queen, Rook, Bishop, Knight, Pawn) for both White and Black
- **Check detection** — alerts the active player when their king is in check
- **Checkmate detection** — ends the game when no legal moves remain
- **Illegal move filtering** — moves that leave the player's own king in check are automatically excluded
- **Two game modes:**
  - **PvP** — two players on the same machine
  - **vs AI** — play as White against a computer-controlled Black opponent
- **Visual move hints** — legal squares are highlighted with blue dots on click
- **Piece capture** — captured pieces are removed from the board
- **GTK3 GUI** — pixel-art chess pieces rendered on a custom-drawn board with a dark border

---

## Tech Stack

| Layer | Technology |
|---|---|
| Language | C (C99) |
| GUI Framework | GTK3 (via `gtk/gtk.h`) |
| Graphics | Cairo (via GTK draw callbacks) |
| Build | GCC + pkg-config |
| OS | Linux (Ubuntu recommended) |

---

## Architecture

The codebase is split across five files following a clean separation of concerns:

```
checkmate/
├── main.c          # Entry point — initializes and runs the GTK application
├── game.c          # All chess logic: move generation, check, checkmate, AI
├── game.h          # Declarations for all game logic functions
├── gui.c           # All GTK window/widget code: board rendering, event handling
├── gui.h           # Declarations for all GUI functions
├── globals.c       # Global state: board array, turn tracker, UI references
└── globals.h       # Extern declarations and shared type definitions
```

Global state is managed through a single `char* chess_pieces[8][8]` board array, where each cell holds a filename string identifying the piece occupying that square (empty string if vacant). Lowercase filenames denote White pieces; uppercase denote Black — a simple, efficient encoding that drives all move and capture logic.

---

## Game Logic

### Move Generation

Each piece type has a dedicated function (`pawn_moves_white`, `rook_moves_black`, etc.) that populates a global `possible_moves[100][2]` array with all candidate destination squares, respecting:

- Board boundaries
- Friendly-piece blocking
- Capture-only squares (pawns)
- Sliding piece ray termination (rook, bishop, queen)
- Knight L-shape jumps over intervening pieces

### Check Detection

`check_white()` and `check_black()` scan the entire board from the perspective of each piece type to determine whether the king of that color is currently under attack — essentially running a reverse ray-cast from the king's position.

### Illegal Move Filtering

`filter_invalid_moves_white()` / `filter_invalid_moves_black()` iterate over the candidate moves array and simulate each move on a temporary board copy. Any move that results in the player's own king being in check is removed from the legal moves list before display.

### Checkmate

`checkmate_white()` / `checkmate_black()` iterate over every piece of the given color, generate all legal moves after filtering, and return true if the total legal move count across all pieces is zero while the king is in check.

### AI Opponent

The AI plays as Black using a random-move strategy: it selects a random piece with available legal moves and executes a random move from that piece's legal set. Implemented via `ai_random()` and `random_move()`.

---

## Getting Started

### Prerequisites

```bash
# Install GTK3 development libraries
sudo apt update
sudo apt install libgtk-3-dev gcc make
```

### Build

```bash
gcc main.c game.c gui.c globals.c \
    $(pkg-config --cflags --libs gtk+-3.0) \
    -o checkmate
```

### Run

```bash
./checkmate
```

> Make sure all `.png` piece asset files are in the same directory as the binary.

---

## Project Structure

```
checkmate/
├── main.c
├── game.c
├── game.h
├── gui.c
├── gui.h
├── globals.c
├── globals.h
├── assets/
│   ├── arook_white.png
│   ├── bknight_white.png
│   ├── cbishop_white.png
│   ├── dqueen_white.png
│   ├── eking_white.png
│   ├── ppawn_white.png
│   ├── Arook_black.png
│   ├── Bknight_black.png
│   ├── Cbishop_black.png
│   ├── Dqueen_black.png
│   ├── Eking_black.png
│   └── Ppawn_black.png
├── Checkmate_black_win.png
├── checkmate_white_win.PNG
└── Chessrules1.png
```

---

## Engineering Takeaways

Working across the full stack of this project — from move generation to GUI event handling — gave me hands-on exposure to problems I wouldn't have encountered in a typical assignment:

- **Rules engines are unforgiving.** Implementing every chess rule from scratch (pawn captures vs. advances, sliding piece ray termination, check vs. checkmate) forced a level of precision that no library can substitute for. One off-by-one in a boundary check cascades into illegal king moves.
- **Illegal move filtering is the hardest part.** The naive approach of "generate moves, then remove bad ones" sounds simple until you realize you need to simulate the board state after each candidate move, re-run check detection, and then restore the board — all without corrupting global state.
- **GTK3 event-driven programming.** Signal callbacks, widget lifecycle management across multiple windows, and simulating button presses programmatically (for the AI's turn) taught me how GUI frameworks decouple user intent from application state.
- **Multi-file C architecture.** Separating concerns across `game.c`, `gui.c`, and `globals.c` with clean header interfaces gave me practical experience with `extern` declarations, translation units, and the discipline required to avoid circular dependencies.
- **Debugging shared mutable state.** When the board array, turn tracker, and possible-moves list are all global, a single missed reset causes ghost moves and phantom checks. Systematic state logging was the only way through.

---

*Built from scratch. No chess libraries. No vibe-coding.*

---

*Built from scratch. No chess libraries. No vibe-coding.*

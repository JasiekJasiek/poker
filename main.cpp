//#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "src/card.hpp"
#include "src/deck.hpp"
#include "src/player.hpp"
#include "src/board.hpp"

int main(){
    
    Board board;

    board.play_game();

    board.print();

    return 0;
}
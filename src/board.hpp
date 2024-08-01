
const int START_MONEY = 1000;

class Board{
public:

    int mod(int n){
        return n % 4;
    }

    Board(){
        deck = new Deck();
        for(int i = 0; i < 4; ++i){
            players.push_back(new Player(i, START_MONEY));
        }
        cards_on_table.resize(5);
        money = 0;
        dealer = 0;
        game_finish = false;
    }

    void print(){
        for(auto i : players){
            auto hand = i -> getHand();
            hand.first.print();
            hand.second.print();
            std::cout << '\n';
        }
        std::cout << '\n';
        for(auto i : cards_on_table){
            i.print();
        }
    }

    void check_if_game_finish(){
        game_finish = true;
    }

    void deal_cards_for_players(){
        for(int i = 0; i < 4; ++i){
            players[ mod(dealer + i) ] -> get_new_hand(deck->getCard(), deck->getCard());
        }
    }

    void deal_cards_for_players(){
        for(int i = 0; i < 3; ++i){
            cards_on_table[ i ] = deck->getCard();
        }
    }

    void deal_ith_card(int i){
        cards_on_table[ i - 1 ] = deck->getCard();
    }

    void play_round(){
        deal_cards_for_players();
        small_blind(mod(dealer + 1));
        big_blind(mod(dealer + 2));
        pre_flop(mod(dealer + 3));
        deal_three_cards_for_table();
        flop(mod(dealer + 1));
        deal_ith_card(4);
        turn(mod(dealer + 1));
        deal_ith_card(5);
        river(mod(dealer + 1));
        showdown();
        dealer = mod(dealer + 1);
    }

    void play_game(){
        while(!game_finish){
            play_round();
            deck->shuffle();
            check_if_game_finish();
        }
    }

private:
    
    int dealer;
    int money;
    bool game_finish;
    Deck* deck;
    std::vector< Card > cards_on_table;
    std::vector< Player* > players;
    //std::vector< Bot* > bots;

};
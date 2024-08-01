class Deck{
public:
    Deck(){
        iterator = -1;
        deck.resize(52, Card());
        makeDeck();
    }

    void makeDeck(){
        std::fstream allCards;
        allCards.open("./src/allCards.txt", std::ios::in);
        for(int i = 0; i < 52; ++i){
            char symbol, value; int compValue;
            allCards >> symbol >> value >> compValue;
            Card c(symbol, value, compValue);
            deck[ i ] = c;
        }
        allCards.close();
        shuffle();
    }

    void shuffle(){
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> dist(1000, 5000);
        shuffle((int)dist(eng), eng);
    }

    Card getCard(){
        iterator++;
        return deck[ iterator ];
    }

    void reset(){
        iterator = -1;
        shuffle();
    }

    void print(){
        for(int i = 0; i < 52; ++i){
            deck[ i ].print();
        }
    }

private:

    void shuffle(int n, std::mt19937& eng){
        for(int i = 0; i < n; ++i){
            std::shuffle(deck.begin(), deck.end(), eng);
        }
    }

    std::vector< Card > deck;
    int iterator;
};
class Card{
public: 
    Card(char symbol, char value, int compValue){
        this -> symbol = symbol;
        this -> value = value;
        this -> compValue = compValue;
    }

    Card(){
        this -> symbol = ' ';
        this -> value = ' ';
        this -> compValue = 0;
    }

    std::pair< char, char > getAtributes(){
        return {symbol, value};
    }

    int getCompValue(){
        return compValue;
    }

    void print(){
        std::cout << symbol << " " << value << '\n';
    }

private:
    char symbol, value;
    int compValue;
};
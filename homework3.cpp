//
// Created by dbperry2 on 3/13/17.
//
#include <iostream>
#include "lexer.h"

using namespace std;
LexicalAnalyzer lexer;

/*
 * S -> A C
 * S -> B D
 * A -> a A
 * A -> #
 * B -> a B
 * B -> a
 * C -> c
 * D -> d
 *
 *
 * OR:
 *
 * S -> A C | B D
 * A -> a A | #
 * B -> a B | a
 * C -> c
 * D -> d
 *
 * terminals: a c d
 */

bool parse_A();
bool parse_B();
bool parse_C();
bool parse_D();

//S -> A C | B D
bool parse_S()
{

    if (parse_A())
    {
        if (parse_C())
        {
            cout << "S -> AC" << endl;
            return true;
        }
        else
        {
            cout << "S -> A ~C" << endl;
            return false;
        }
    }
    else if (parse_B())
    {
        if(parse_D())
        {
            cout << "S -> BD" << endl;
            return true;
        }
        else
        {
            cout << "S -> B ~D" << endl;
            return false;
        }
    }
    else
    {
        cout << "S -> ~(A || B) ... " << endl;
        return false;
    }
}

//A -> a A | #
bool parse_A()
{
    Token tok;

    tok = lexer.GetToken();
    if(tok.token_type == )
    {
        tok = lexer.GetToken();
        if((tok.Token_type == LPAREN) || tok.token_type == DOT)
        {
            //if condition checks FIRST(A)
            //technically we can omit the previous if statement
            //and go straight to parseA
            //this way detects error as soon as possible
            lexer.ungettoken
            if(parseA
                    gettoken
                if RPAREN
                    cout << "( A )"
            return true
            else
            unget
            return false
            else
            return false
        }
        else
            return false
    }
    else if DOT
        return true
    else
        unget
        cout << "A -> ~( A ) and A -> ." << endl;
    return true;

}


//B -> a B | a
bool parse_B()
{
    /*
    Similar to A
    */
}

//C -> c
bool parse_C()
{
    
}

//D -> d
bool parse_D()
{
    
}


int main()
{
    parse_S();

    Token t = lexer.GetToken();
    if(t.token_type != END_OF_FILE)
        cout << "FAILURE!" << endl;
    
    return 0;
}
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

bool testing = true;

bool parse_A();
bool parse_B();
bool parse_C();
bool parse_D();

//S -> A C | B D
bool parse_S()
{
    if(testing)
        cout << "Parsing S" << endl;

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
        cout << "S -> ~AC and S -> ~BD" << endl;
        return false;
    }
}

//A -> a A | #
bool parse_A()
{
    Token tok;

    tok = lexer.GetToken();

    if(testing)
    {
        cout << "Parsing A" << endl;
        tok.Print();
    }

    if(tok.token_type == aTerm)
    {
        if (parse_A())
        {
            cout << "A -> aA" << endl;
            return true;
        }
        else
        {
            cout << "A -> a ~A" << endl;
            return false;
        }
    }
    else if(tok.token_type == cTerm)
    {
        lexer.UngetToken(tok);
        cout << "A -> epsilon" << endl;
        return true;
    }
    else
    {
        lexer.UngetToken(tok);
        cout << "A -> ~a A and A -> ~epsilon" << endl;
        return false;
    }
}


//B -> a B | a
bool parse_B()
{
    Token tok;

    tok = lexer.GetToken();

    if(testing)
    {
        cout << "Parsing B" << endl;
        tok.Print();
    }

    if(tok.token_type == aTerm)
    {
        if (parse_B())
        {
            cout << "B -> aB" << endl;
            return true;
        }
        else
        {
            cout << "B -> a" << endl;
            return true;
        }
    }
    else
    {
        lexer.UngetToken(tok);
        cout << "B -> ~aB and B -> ~a" << endl;
        return false;
    }
}

//C -> c
bool parse_C()
{
    Token tok;

    tok = lexer.GetToken();

    if(testing)
    {
        cout << "Parsing C" << endl;
        tok.Print();
    }

    if(tok.token_type == cTerm)
    {
        cout << "C -> c" << endl;
        return true;
    }
    else
    {
        lexer.UngetToken(tok);
        cout << "C -> ~c" << endl;
        return false;
    }
}

//D -> d
bool parse_D()
{
    Token tok;

    tok = lexer.GetToken();

    if(testing)
    {
        cout << "Parsing D" << endl;
        tok.Print();
    }

    if(tok.token_type == dTerm)
    {
        cout << "D -> d" << endl;
        return true;
    }
    else
    {
        lexer.UngetToken(tok);
        cout << "D -> ~d" << endl;
        return false;
    }
}


int main()
{
    parse_S();
    Token t = lexer.GetToken();

    if(testing)
    {
        cout << "Done Parsing. EOF?" << endl;
        t.Print();
    }


    if(t.token_type != END_OF_FILE)
        cout << "FAILURE!" << endl;
    
    return 0;
}
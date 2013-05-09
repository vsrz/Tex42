
#include <iostream>
#include <vector>
#include <iterator>
#include "DominoCollectionTests.h"
#include "Domino.h"
#include "DominoCollection.h"

void DominoCollectionTests::RunAllTests( void )
{
	// Other tests do this already
	// DominoCollectionAddDominoes();
    DrawRandomDominoes();
    ShuffleTest();
    GenerateDominoSets();
}

void DominoCollectionTests::ShuffleTest( void )
{
    name = "DominoCollection Shuffling Test";
    beginTest();
    DominoCollection dominoes;
	DominoCollection lastshuffle;

	// generate a double-six domino set
	for( int i = 6; i > -1; --i )
    {
        for( int j = i; j > -1; --j )
        {
            dominoes.addDomino( Domino( i, j) );
        }
    }
	
	lastshuffle = dominoes;

    std::cout << "WARNING: Test may fail if the same shuffle occurs twice" << std::endl;
    for( int i = 0; i < 5; ++i ) 
    {
        dominoes.shuffle();
		std::cout << "Shuffling dominoes.";
		assert( lastshuffle != dominoes );
		std::cout << " Ok." << std::endl;
		lastshuffle = dominoes;
    }

	std::cout << std::endl;

    endTest();
}

void DominoCollectionTests::DrawRandomDominoes( void )
{
    name = "DominoCollection Draw Random Dominoes";
    beginTest();
    Domino doubleFive( 5, 5 );
    Domino doubleFour( 4, 4 );
    Domino treySix( 3, 6 );
    Domino doubleOne( 1, 1);

    DominoCollection trick;

    std::cout << "Insert dominoes into collection";

    trick.addDomino( doubleFive );
	assert(trick.contains( doubleFive ));
    trick.addDomino( doubleFour );
	assert(trick.contains( doubleFour ));
    trick.addDomino( treySix );
	assert(trick.contains( treySix ));
    trick.addDomino( doubleOne );
	assert(trick.contains( doubleOne ));
	std::cout << " Ok." << std::endl;

    std::cout << "Remove " << trick.getSize() << " dominoes in order from Collection.";
    Domino d;

    d = trick.removeDomino();
    assert( d == doubleOne );
    d = trick.removeDomino();
    assert( d == treySix );
    d = trick.removeDomino();
    assert( d == doubleFour );
    d = trick.removeDomino();
    assert( d == doubleFive );
    std::cout << " Ok." << std::endl;

    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( doubleOne );

    std::cout << "Draw " << trick.getSize() << " random dominoes from Collection.";
    
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );

	std::cout << " Ok." << std::endl;

    endTest();

}

void DominoCollectionTests::AddDominoes( void )
{

    name = "DominoCollection Adding Dominoes";
    
    Domino doubleFive( 5, 5 );
    Domino doubleFour( 4, 4 );
    Domino treySix( 3, 6 );
    Domino oneOne( 1, 1);

    beginTest();

    DominoCollection trick;

    std::cout << "Create and print a collection." << std::endl;
    trick.addDomino( doubleFive );
    std::cout << "Add 5,5" << trick << std::endl;
    trick.addDomino( doubleFour );
    std::cout << "Add 4,4" << trick << std::endl;
    trick.addDomino( treySix );
    std::cout << "Add 3,6" << trick << std::endl;
    trick.addDomino( oneOne );
    std::cout << "Add 1,1" << trick << std::endl;
    trick.addDomino( doubleFive );
    std::cout << "Add 5,5" << trick << std::endl;
    trick.addDomino( doubleFour );
    std::cout << "Add 4,4" << trick << std::endl;
    trick.addDomino( treySix );
    std::cout << "Add 3,6" << trick << std::endl;
    trick.addDomino( oneOne );
    std::cout << "Add 1,1" << trick << std::endl;


    std::cout << "Create and print a collection." << std::endl;
    std::cout << trick << std::endl;
    std::cout << " Ok." << std::endl;

    endTest();
}

/**
 * Generates and verifies domino sets
 */
void DominoCollectionTests::GenerateDominoSets( void )
{
    name = "Domino spawn tests.";
    beginTest();

    std::cout << "Generate a set of Double-Six dominoes.";
    DominoCollection set;
    set.generateDoubleSixSet();

    assert( set.size() == 28 );
    assert( set.countDominoes( Domino( 6,6 ) ) == 1 );
    assert( set.countDominoes( Domino( 6,5 ) ) == 1 );
    assert( set.countDominoes( Domino( 6,4 ) ) == 1 );
    assert( set.countDominoes( Domino( 6,3 ) ) == 1 );
    assert( set.countDominoes( Domino( 6,2 ) ) == 1 );
    assert( set.countDominoes( Domino( 6,1 ) ) == 1 );
    assert( set.countDominoes( Domino( 6,0 ) ) == 1 );
    assert( set.countDominoes( Domino( 5,5 ) ) == 1 );
    assert( set.countDominoes( Domino( 5,4 ) ) == 1 );
    assert( set.countDominoes( Domino( 5,3 ) ) == 1 );
    assert( set.countDominoes( Domino( 5,2 ) ) == 1 );
    assert( set.countDominoes( Domino( 5,1 ) ) == 1 );
    assert( set.countDominoes( Domino( 5,0 ) ) == 1 );
    assert( set.countDominoes( Domino( 4,4 ) ) == 1 );
    assert( set.countDominoes( Domino( 4,3 ) ) == 1 );
    assert( set.countDominoes( Domino( 4,2 ) ) == 1 );
    assert( set.countDominoes( Domino( 4,1 ) ) == 1 );
    assert( set.countDominoes( Domino( 4,0 ) ) == 1 );
    assert( set.countDominoes( Domino( 3,3 ) ) == 1 );
    assert( set.countDominoes( Domino( 3,2 ) ) == 1 );
    assert( set.countDominoes( Domino( 3,1 ) ) == 1 );
    assert( set.countDominoes( Domino( 3,0 ) ) == 1 );
    assert( set.countDominoes( Domino( 2,2 ) ) == 1 );
    assert( set.countDominoes( Domino( 2,1 ) ) == 1 );
    assert( set.countDominoes( Domino( 2,0 ) ) == 1 );
    assert( set.countDominoes( Domino( 1,1 ) ) == 1 );
    assert( set.countDominoes( Domino( 1,0 ) ) == 1 );
    assert( set.countDominoes( Domino( 7,0 ) ) == 0 );
    assert( set.countDominoes( Domino( -1,-1 ) ) == 0 );
    
    std:: cout << " Ok." << std::endl;

    endTest();

    
}


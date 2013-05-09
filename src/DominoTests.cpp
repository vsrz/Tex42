
#include <iostream>
#include "DominoTests.h"


void DominoTests::RunAllTests( void )
{
    DominoCreation();
    DominoPipTests();
    DominoComparison();
}

void DominoTests::DominoPipTests( void )
{
    name = "Domino Creation";
    Domino fiveFive( 5, 5 );
    Domino fiveFour( 5, 4 );

    beginTest();
    
    std::cout << "High PIP on a 5 | 5 == 5";
    assert( fiveFive.getHighPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "Low PIP on a 5 | 5 == 5";
    assert( fiveFive.getLowPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "5 | 5 is a double";
    assert( fiveFive.isDouble() == true );
    std::cout << " Ok." << std::endl;

    std::cout << "High PIP on a 5 | 4 == 5";
    assert( fiveFour.getHighPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "Low PIP on a 5 | 4 == 4";
    assert( fiveFour.getLowPip() == 4 );
    std::cout << " Ok." << std::endl;

    std::cout << "5 | 4 is not a double";
    assert( fiveFour.isDouble() == false );
    std::cout << " Ok." << std::endl;

    std::cout << "High PIP on a 4 | 5 == 5";
    assert( fiveFour.getHighPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "Low PIP on a 4 | 5 == 4";
    assert( fiveFour.getLowPip() == 4 );
    std::cout << " Ok." << std::endl;

    std::cout << "4 | 5 is not a double";
    assert( fiveFour.isDouble() == false );
    std::cout << " Ok." << std::endl;

    
    endTest();

}

void DominoTests::DominoCreation( void )
{
    name = "Domino Creation";
    Domino d( 5, 6 );
    beginTest();

    std::cout << "Creating Domino, 5 | 6 ";
    std::cout << d;
    assert( d == Domino(d) );
    std::cout << " Ok." << std::endl;

    std::cout << "Assignment operator";
    Domino q = d;
    assert( q == d );
    std::cout << q;
    std::cout << " Ok." << std::endl;



    endTest();

}

void DominoTests::DominoComparison( void )
{
    name = "DominoComparison";
    int suit = 5;
    Domino ours( 6, 5 ), theirs( 4, 5 );

    beginTest();

    std::cout << "Suit is Fives" << std::endl;

    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;
    
    ours.setPip( 5, 5 );
    theirs.setPip( 5, 6 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 4, 5 );
    theirs.setPip( 5, 6 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 5, 4 );
    theirs.setPip( 5, 5 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 6, 5 );
    theirs.setPip( 5, 5 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 5, 6 );
    theirs.setPip( 5, 4 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 0, 6 );
    theirs.setPip( 0, 4 );
    std::cout << ours << " < " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 5, 5 );
    theirs.setPip( 0, 0 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 0, 6 );
    theirs.setPip( 5, 4 );
    std::cout << ours << " < " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 6, 6 );
    theirs.setPip( 6, 6 );
    std::cout << ours << " == && != " << theirs;
    assert( ( ours == theirs ) == true );
    assert( ( ours != theirs ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 6, 4 );
    theirs.setPip( 6, 6 );
    std::cout << ours << " == && != " << theirs;
    assert( ( ours != theirs ) == true );
    assert( ( ours == theirs ) == false );
    std::cout << " Ok." << std::endl;


    endTest();
}


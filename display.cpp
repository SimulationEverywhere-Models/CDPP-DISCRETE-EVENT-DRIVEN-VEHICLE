/*******************************************************************
*
*  DESCRIPTION: Atomic Model Display
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "display.h"      // class Display
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Display
* Description:
********************************************************************/
Display::Display( const string &name )
: Atomic( name )
, display_in1( addInputPort( "display_in1" ) )
, display_in2( addInputPort( "display_in2" ) )
//, wheel_turn( addOutputPort( "wheel_turn" ) )
, preparationTime( 0, 0, 5, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
* Precondition:
********************************************************************/
Model &Display::initFunction()
{
	this-> passivate();
	displayIn1 = 0;
	displayIn2 = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Display::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == display_in1 )
	{
		displayIn1 = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	if( msg.port() == display_in2 )
	{
		displayIn2 = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Display::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Display::outputFunction( const InternalMessage &msg )
{
	//sendOutput( msg.time(), wheel_turn, wheelTurn) ;
	return *this ;
}

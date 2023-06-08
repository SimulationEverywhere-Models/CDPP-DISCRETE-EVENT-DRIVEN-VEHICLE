/*******************************************************************
*
*  DESCRIPTION: Atomic Model Brakes
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "brakes.h"      // class Brakes
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Brakes
* Description:
********************************************************************/
Brakes::Brakes( const string &name )
: Atomic( name )
, br_int( addInputPort( "br_int" ) )
//, wheel_turn( addOutputPort( "wheel_turn" ) )
, preparationTime( 0, 0, 15, 0 )
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
Model &Brakes::initFunction()
{
	this-> passivate();
	brake= 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Brakes::externalFunction( const ExternalMessage &msg )
{
	int in_brk;

	if( msg.port() == br_int )
	{
		in_brk = static_cast < int > (msg.value());

		brake = brake + in_brk;

		if(brake > 0)
			holdIn( active, preparationTime );
		else {
			brake = 0;
			this-> passivate();
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Brakes::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Brakes::outputFunction( const InternalMessage &msg )
{
	//sendOutput( msg.time(), wheel_turn, wheelTurn) ;
	return *this ;
}

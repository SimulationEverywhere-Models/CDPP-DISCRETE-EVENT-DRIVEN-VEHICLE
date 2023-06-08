/*******************************************************************
*
*  DESCRIPTION: Atomic Model SteerMechType
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "steerMechType.h"      // class Motor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Motor
* Description:
********************************************************************/
SteerMechType::SteerMechType( const string &name )
: Atomic( name )
, delta_angle( addInputPort( "delta_angle" ) )
, wheel_turn( addOutputPort( "wheel_turn" ) )
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
Model &SteerMechType::initFunction()
{

	this-> passivate();
	wheelTurn = 0;
	return *this ;

}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &SteerMechType::externalFunction( const ExternalMessage &msg )
{

	if( msg.port() == delta_angle )
	{
		wheelTurn = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	return *this;

}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &SteerMechType::internalFunction( const InternalMessage & )
{

	passivate();
	return *this ;

}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &SteerMechType::outputFunction( const InternalMessage &msg )
{

	sendOutput( msg.time(), wheel_turn, wheelTurn) ;
	return *this ;

}

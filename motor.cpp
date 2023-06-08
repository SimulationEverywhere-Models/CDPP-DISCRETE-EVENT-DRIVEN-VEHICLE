/*******************************************************************
*
*  DESCRIPTION: Atomic Model Motor
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "motor.h"      // class Motor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Motor
* Description:
********************************************************************/
Motor::Motor( const string &name )
: Atomic( name )
, mot_torq( addInputPort( "mot_torq" ) )
, mot_rpm( addOutputPort( "mot_rpm" ) )
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
Model &Motor::initFunction()
{
	this-> passivate();
	torq = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Motor::externalFunction( const ExternalMessage &msg )
{
	int in_torq;

	if( msg.port() == mot_torq )
	{
		in_torq = static_cast < int > (msg.value());

		torq = torq + in_torq;

		if(torq > 0)
			holdIn( active, preparationTime );
		else {
			torq = 0;
			this-> passivate();
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Motor::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Motor::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), mot_rpm, torq) ;
	return *this ;
}

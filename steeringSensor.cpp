/*******************************************************************
*
*  DESCRIPTION: Atomic Model SteeringSensor
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "steeringSensor.h"      // class SteeringSensor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: SteeringSensor
* Description:
********************************************************************/
SteeringSensor::SteeringSensor( const string &name )
: Atomic( name )
, act_wheel_angle( addInputPort( "act_wheel_angle" ) )
, act_ang_fb( addOutputPort( "act_ang_fb" ) )
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
Model &SteeringSensor::initFunction()
{
	this-> passivate();
	wheelAngle = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &SteeringSensor::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == act_wheel_angle )
	{
		wheelAngle = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &SteeringSensor::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &SteeringSensor::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), act_ang_fb, wheelAngle) ;
	return *this ;
}

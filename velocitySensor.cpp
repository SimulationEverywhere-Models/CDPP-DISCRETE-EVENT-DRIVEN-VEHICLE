/*******************************************************************
*
*  DESCRIPTION: Atomic Model VelocitySensor
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "velocitySensor.h"      // class VelocitySensor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: VelocitySensor
* Description:
********************************************************************/
VelocitySensor::VelocitySensor( const string &name )
: Atomic( name )
, act_rpm( addInputPort( "act_rpm" ) )
, act_rpm_fb( addOutputPort( "act_rpm_fb" ) )
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
Model &VelocitySensor::initFunction()
{
	this-> passivate();
	rpm = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &VelocitySensor::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == act_rpm )
	{
		rpm = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &VelocitySensor::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &VelocitySensor::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), act_rpm_fb, rpm) ;
	return *this ;
}

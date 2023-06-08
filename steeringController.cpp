/*******************************************************************
*
*  DESCRIPTION: Atomic Model SteeringController
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "steeringController.h"      // class SteeringController
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: SteeringController
* Description:
********************************************************************/
SteeringController::SteeringController( const string &name )
: Atomic( name )
, turn_angle( addInputPort( "turn_angle" ) )
, drive_straight( addInputPort( "drive_straight" ) )
, act_ang_fb( addInputPort( "act_ang_fb" ) )
, disp_info2( addOutputPort( "disp_info2" ) )
, delta_angle( addOutputPort( "delta_angle" ) )
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
Model &SteeringController::initFunction()
{
	this-> passivate();
	turn_angle_val = 0;
	act_ang_fb_val = 0;
	delta_angle_val = 0;
	flag = PROC_SRAIGHT;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &SteeringController::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == turn_angle )
	{
		turn_angle_val = static_cast < int > (msg.value());
		delta_angle_val = (turn_angle_val - act_ang_fb_val );
		flag = PROC_TURN;
		holdIn( active, preparationTime );
	}

	if( msg.port() == drive_straight )
	{
		delta_angle_val = ZERO_ANGLE;
		flag = PROC_SRAIGHT;
		holdIn( active, preparationTime );
	}

	if( msg.port() == act_ang_fb )
	{
		act_ang_fb_val = static_cast < int > (msg.value());
		flag = PROC_FB;
		holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &SteeringController::internalFunction( const InternalMessage & )
{
	passivate();
	flag = PROC_SRAIGHT;
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &SteeringController::outputFunction( const InternalMessage &msg )
{
	if(flag == PROC_TURN || flag == PROC_SRAIGHT)
		sendOutput( msg.time(), delta_angle, delta_angle_val) ;

	sendOutput( msg.time(), disp_info2, act_ang_fb_val) ;
	return *this ;
}

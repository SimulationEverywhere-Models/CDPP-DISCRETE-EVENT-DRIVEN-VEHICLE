/*******************************************************************
*
*  DESCRIPTION: Atomic Model MovementController
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

/** include files **/
#include "movementController.h"      // class Motor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Motor
* Description:
********************************************************************/
MovementController::MovementController( const string &name )
: Atomic( name )
, accel( addInputPort( "accel" ) )
, decel( addInputPort( "decel" ) )
, emerg_brk( addInputPort( "emerg_brk" ) )
, act_rpm_fb( addInputPort( "act_rpm_fb" ) )
, mot_torq( addOutputPort( "mot_torq" ) )
, br_int( addOutputPort( "br_int" ) )
, disp_info1( addOutputPort( "disp_info1" ) )
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
Model &MovementController::initFunction()
{

	this-> passivate();
	act_rpm_fb_val = 0;
	flag = PROC_BRK;
	return *this ;

}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &MovementController::externalFunction( const ExternalMessage &msg )
{

	if( msg.port() == accel && act_rpm_fb_val < MAX_RPM)
	{
		flag = PROC_ACCEL;
		holdIn( active, preparationTime );
	}
	if( msg.port() == decel && act_rpm_fb_val > ZERO_RPM )
	{
		flag = PROC_DECEL;
		holdIn( active, preparationTime );
	}

	if( msg.port() == emerg_brk )
	{
		flag = PROC_BRK;
		holdIn( active, preparationTime );
	}

	if( msg.port() == act_rpm_fb )
	{
		act_rpm_fb_val = static_cast < int > (msg.value());
		flag = PROC_FB;
		holdIn( active, preparationTime );
	}


	return *this;

}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &MovementController::internalFunction( const InternalMessage & )
{

	passivate();
	return *this ;

}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &MovementController::outputFunction( const InternalMessage &msg )
{

	if( flag == PROC_ACCEL )
	{
		sendOutput( msg.time(), mot_torq, MOT_UP_STEP) ;
		sendOutput( msg.time(), br_int, NO_BRK) ;
	}

	if( flag == PROC_DECEL )
	{
		sendOutput( msg.time(), mot_torq, MOT_DWN_STEP) ;
		sendOutput( msg.time(), br_int, BRK_UP_STEP) ;
	}

	if( flag == PROC_BRK )
	{
		sendOutput( msg.time(), mot_torq, MOT_STOP) ;
		sendOutput( msg.time(), disp_info1, MAX_BRK) ;
	}

	sendOutput( msg.time(), disp_info1, act_rpm_fb_val) ;
	return *this ;

}

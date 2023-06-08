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

#ifndef __SteeringController_H
#define __SteeringController_H

//#include <list>
#include "atomic.h"     // class Atomic


#define ZERO_ANGLE    0


class SteeringController : public Atomic
{
public:
	SteeringController( const string &name = "SteeringController" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &turn_angle;
	const Port &drive_straight;
	const Port &act_ang_fb;
	Port &delta_angle;
	Port &disp_info2;
	Time preparationTime;
	int turn_angle_val;
	int act_ang_fb_val;
	int delta_angle_val;
	enum FLAG {PROC_TURN, PROC_SRAIGHT, PROC_FB} flag;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class SteeringController

// ** inline ** //
inline
string SteeringController::className() const
{
	return "SteeringController" ;
}

#endif   //__MOTOR_H

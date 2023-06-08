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

#ifndef __MovementController_H
#define __MovementController_H

//#include <list>
#include "atomic.h"     // class Atomic

#define MAX_RPM 100
#define MOT_STOP   -1000
#define ZERO_RPM    0
#define ZERO_INT    0
#define MOT_UP_STEP    10
#define MOT_DWN_STEP    -10
#define MAX_BRK    100
#define NO_BRK   -1000
#define BRK_UP_STEP    10

class MovementController : public Atomic
{
public:
	MovementController( const string &name = "MovementController" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

	const Port &accel;
	const Port &decel;
	const Port &emerg_brk;
	const Port &act_rpm_fb;
	Port &mot_torq;
	Port &br_int;
	Port &disp_info1;

	Time preparationTime;
	int act_rpm_fb_val;
	enum FLAG {PROC_ACCEL, PROC_DECEL, PROC_FB, PROC_BRK} flag;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Motor

// ** inline ** //
inline
string MovementController::className() const
{
	return "MovementController" ;
}

#endif   //__MOTOR_H

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

#ifndef __STEERINGSENSOR_H
#define __STEERINGSENSOR_H


#include "atomic.h"     // class Atomic

class SteeringSensor : public Atomic
{
public:
	SteeringSensor( const string &name = "SteeringSensor" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &act_wheel_angle;
	Port &act_ang_fb;
	Time preparationTime;
	int wheelAngle;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class SteeringSensor

// ** inline ** // 
inline
string SteeringSensor::className() const
{
	return "SteeringSensor" ;
}

#endif   //__STEERINGSENSOR_H

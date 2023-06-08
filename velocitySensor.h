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

#ifndef __VELOCITYSENSOR_H
#define __VELOCITYSENSOR_H

//#include <list>
#include "atomic.h"     // class Atomic

class VelocitySensor : public Atomic
{
public:
	VelocitySensor( const string &name = "VelocitySensor" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &act_rpm;
	Port &act_rpm_fb;
	Time preparationTime;
	int rpm;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class VelocitySensor

// ** inline ** //
inline
string VelocitySensor::className() const
{
	return "VelocitySensor" ;
}

#endif   //__STEERMECH_H

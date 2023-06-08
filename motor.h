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

#ifndef __MOTOR_H
#define __MOTOR_H

//#include <list>
#include "atomic.h"     // class Atomic

class Motor : public Atomic
{
public:
	Motor( const string &name = "Motor" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &mot_torq;
	Port &mot_rpm;
	Time preparationTime;
	int torq;

//	Time timeLeft;

};	// class Motor

// ** inline ** //
inline
string Motor::className() const
{
	return "Motor" ;
}

#endif   //__MOTOR_H

/*******************************************************************
*
*  DESCRIPTION: Atomic Model SteerMechType
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

#ifndef __SteerMechType_H
#define __SteerMechType_H

//#include <list>
#include "atomic.h"     // class Atomic

class SteerMechType : public Atomic
{
public:
	SteerMechType( const string &name = "SteerMechType" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &delta_angle;
	Port &wheel_turn;
	Time preparationTime;
	int wheelTurn;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Motor

// ** inline ** //
inline
string SteerMechType::className() const
{
	return "SteerMechType" ;
}

#endif   //__SteerMechType_H

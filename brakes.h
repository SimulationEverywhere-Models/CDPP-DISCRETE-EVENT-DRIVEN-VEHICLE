/*******************************************************************
*
*  DESCRIPTION: Atomic Model Brakes
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

#ifndef __BREAKS_H
#define __BREAKS_H

//#include <list>
#include "atomic.h"     // class Atomic

class Brakes : public Atomic
{
public:
	Brakes( const string &name = "Brakes" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &br_int;
	Time preparationTime;
	int brake;


//	Time timeLeft;

};	// class Brakes

// ** inline ** //
inline
string Brakes::className() const
{
	return "Brakes" ;
}

#endif   //__BREAKS_H

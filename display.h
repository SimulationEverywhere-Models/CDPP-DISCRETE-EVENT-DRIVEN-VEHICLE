/*******************************************************************
*
*  DESCRIPTION: Atomic Model Display
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL: mailto:
*
*  DATE: 18/10/2012
*
*******************************************************************/

#ifndef __DISPLAY_H
#define __DISPLAY_H

//#include <list>
#include "atomic.h"     // class Atomic

class Display : public Atomic
{
public:
	Display( const string &name = "Display" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &display_in1;
	const Port &display_in2;
	Time preparationTime;
	int displayIn1, displayIn2;

//	Time timeLeft;

};	// class Display

// ** inline ** //
inline
string Display::className() const
{
	return "Display" ;
}

#endif   //__DISPLAY_H

/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Mohamed Ebada & Ali Salaheddin
*
*  EMAIL:
*
*  DATE: 18/10/2012
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "brakes.h"        // class Breaks
#include "display.h"        // class Display
#include "motor.h"        // class Motor
#include "steeringSensor.h"        // class SteeringSensor
#include "steerMechType.h"        // class SteerMeshType
#include "velocitySensor.h"        // class VelocitySensor
#include "movementController.h"        // class MovementController
#include "steeringController.h"        // class SteeringController

void MainSimulator::registerNewAtomics()
{

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Brakes>(), "Brakes" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Display>(), "Display" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Motor>(), "Motor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<SteeringSensor>(), "SteeringSensor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<SteerMechType>(), "SteerMechType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<VelocitySensor>(), "VelocitySensor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MovementController>(), "MovementController" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<SteeringController>(), "SteeringController" ) ;


}


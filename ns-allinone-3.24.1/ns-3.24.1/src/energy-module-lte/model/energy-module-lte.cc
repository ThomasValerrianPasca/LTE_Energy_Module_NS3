/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "energy-module-lte.h"
#include "ns3/li-ion-energy-source.h"
#include <ns3/simulator.h>
#include <ns3/nstime.h>
namespace ns3 {

/* ... */
EnergyModuleLte::EnergyModuleLte()
:m_time_last_tx(0),
 m_time_last_rx(0)
{

}

EnergyModuleLte::~EnergyModuleLte(){

}

void EnergyModuleLte::Only_uplink_tx(double idleTime)
{
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);
	double supplyVoltage=5.0;
	double energyDecreasedIdle=0.1*supplyVoltage*idleTime/1000000000;
	//Energy to be decrease in joules
	double energyDecreasedTx=(0.11+0.306)*supplyVoltage*0.001;

	m_time_last_tx=Simulator::Now().GetMilliSeconds();

	if(m_time_last_rx==m_time_last_tx)
	{
		only_tx(energyDecreasedTx);
		both_donwlink_and_uplink(idleTime);

	}
	else{
		only_tx(energyDecreasedTx+energyDecreasedIdle);
		std::cout<<"Transmit chain is consuming power"<< (energyDecreasedTx+energyDecreasedIdle) <<" joules"<<std::endl;
	}

}

void EnergyModuleLte::Only_donwlink_rx(double idleTime)
{
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);

	double supplyVoltage=5.0;
	double energyDecreasedIdle=0.1*supplyVoltage*idleTime/1000000000;
	double energyDecreasedRx=(0.098+0.306)*supplyVoltage*0.001;
	if(m_time_last_rx==m_time_last_tx)
	{
		only_tx(energyDecreasedRx);
		both_donwlink_and_uplink(idleTime);

	}
	else{
		only_tx(energyDecreasedRx+energyDecreasedIdle);
		std::cout<<"Receive chain is consuming power"<< (energyDecreasedRx+energyDecreasedIdle) <<" joules"<<std::endl;
	}

	m_time_last_rx=Simulator::Now().GetMilliSeconds();


}

void EnergyModuleLte::Only_idle_decrease(double idleTime)
{
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);

	double supplyVoltage=5.0;
	double energyDecreasedIdle=0.1*supplyVoltage*idleTime/1000000000;
	only_tx(energyDecreasedIdle);
}
void EnergyModuleLte::both_donwlink_and_uplink(double idleTime)
{
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);
	double supplyVoltage=5.0;
	double energyDecreasedIdle=0.032*supplyVoltage*0.001;
	only_tx(energyDecreasedIdle);
	std::cout<<"Both Transmit and Receive chain is consuming power "<<std::endl;
}




}


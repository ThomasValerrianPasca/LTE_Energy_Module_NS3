/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef ENERGY_MODULE_LTE_H
#define ENERGY_MODULE_LTE_H
#include "ns3/li-ion-energy-source.h"
#include <ns3/nstime.h>
namespace ns3 {

/* ... */

/* ... */
class EnergyModuleLte {

public:
	//An Energy Source is created for every device
	LiIonEnergySource LIES;

	EnergyModuleLte();
	~EnergyModuleLte();
	//An LTE UE can be in transmit mode or reception mode
	int64_t m_time_last_tx; //Time since a transmission is observed
	int64_t m_time_last_rx; //Time since a reception is observed

	//Only downlink is enabled
	void Only_donwlink_rx(double idle_time_units);
	//Only uplink is enabled
	void Only_uplink_tx(double idle_time_units);
	//Decrease if the device is idle all time
	void Only_idle_decrease(double idle_time_units);
	//Decrease if the device is used simultaneous both uplink and downlink
	void both_donwlink_and_uplink(double idle_time_units);
};
}

#endif /* ENERGY_MODULE_LTE_H */


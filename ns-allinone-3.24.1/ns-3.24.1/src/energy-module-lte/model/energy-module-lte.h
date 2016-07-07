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
	LiIonEnergySource LIES;

	EnergyModuleLte();
	~EnergyModuleLte();
	int64_t m_time_last_tx;
	int64_t m_time_last_rx;
	void Only_donwlink_rx(double idle_time_units);
	void Only_uplink_tx(double idle_time_units);
	void Only_idle_decrease(double idle_time_units);
	void both_donwlink_and_uplink(double idle_time_units);
};
}

#endif /* ENERGY_MODULE_LTE_H */


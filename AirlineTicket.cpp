#include "AirlineTicket.h"

AirlineTicket::AirlineTicket() 
	: mPassengerName("UnKnown Passenger")
	, mNumberOfMiles(0)
	, mHasEliteSuperRewardsStatus(false)
{
	/*
	mPassengerName = "UnKnown Passenger";
	mNumberOfMiles = 0;
	mHasEliteSuperRewardsStatus = false;
	*/
}

AirlineTicket::~AirlineTicket()
{
}

double AirlineTicket::calculatePriceInDollars() const
{
	if (hasEliteSuperRewardsStatus()) {
		return 0.0;
	}

	return getNumberOfMiles() * 0.1;
}

const std::string& AirlineTicket::getPassengerName() const
{
	// // O: 여기에 return 문을 삽입합니다.
	return mPassengerName;
}

void AirlineTicket::setPassengerName(const std::string& name)
{
	mPassengerName = name;
}

int AirlineTicket::getNumberOfMiles() const
{
	return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	mNumberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
	return mHasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
	mHasEliteSuperRewardsStatus = status;
}

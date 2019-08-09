#pragma once

namespace Packet
{
	enum FailureCode
	{
		IncorrectVersion = 4,
		BadKey = 5,
		InvalidTeleportTarget = 6,
		EmailVerificationNeeded = 7,
		TeleportRealmBlock = 8,
	};
}